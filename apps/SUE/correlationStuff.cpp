
#include "pragmas.h"
#include <vector>
#include <map>
#include <list>
#include <string>
#include <iostream> 
#include <fstream>
#include <algorithm>
#include <cmath>

#include "common/Error.h"

#include "correlationStuff.h"
#include "distributionTypes.h"

using namespace std;

namespace{
	//--------------------------------------------------------------------------------

	template<class T>
	class compareOnFirst 
	{
		public:
			int operator() (const pair<T,int>* p1, const pair<T, int>* p2) const
			{ return p1->first < p2->first; }
	};

	//--------------------------------------------------------------------------------

	template<class T>
	void swap(std::vector<T>&	vect, 
			  int				a, 
			  int				b)
	// swaps values at vect[a] and vect[b]
	{
		if(a<0 || b<0 || a>=vect.size() || b>=vect.size())
		{
			throw Error("Program Error while generating correlation:"
						+(std::string)"\nOut of bounds vector element.\n");
		}
		T temp = vect[a];
		vect[a] = vect[b];
		vect[b] = temp;
		return;
	}

	//--------------------------------------------------------------------------------

	void rank(const std::vector<double>&		a, 
			  std::vector<int>&			rankVect)
	// fills the int vector rankVect with the ranks of "a"
	// s.t. if the i'th element of "a" is the 34th smallest element in "a",
	// bRank[i] = 34.
	// first ranked element has rank 0.  last element has rank size - 1.
	{
		int size = a.size();
		vector<pair<double,int>* > valSlotPairs(size);
		for(int i=0; i<size; i++)
			valSlotPairs[i] = new pair<double,int>(a[i],i);

		// sort
		sort(valSlotPairs.begin(), valSlotPairs.end(), compareOnFirst<double>()); 

		int originalSlot;
		for(int i=0; i<size; i++)
		{
			originalSlot = valSlotPairs[i]->second;
			// "i" is the rank of the current value/slot pair
			// (whose value was found at "originalSlot" in vector "a")
			rankVect[originalSlot] = i;
			// clean up as we go.
			delete valSlotPairs[i];
		}
	}

	//--------------------------------------------------------------------------------

	bool findTrade(std::map<int, std::list<int> >&	deltaMap, 
				   std::list<int>::const_iterator&	listIterLowX,
				   std::list<int>::const_iterator&	listIterHighX,
				   int&								lowDelta, 
				   int&								highDelta)
	// called by rankCorrelate.
	// deltaMap should be a const, but I can't make things compile if I 
	// do it that way.
	{
		if(highDelta > -lowDelta)
		{
			listIterLowX = deltaMap[highDelta].begin();
			while(true)
			{
				// if this is a valid deltaMap entry
				if(deltaMap.count(lowDelta))
				{
					// look for a good swap in deltaMap[lowDelta]
					listIterHighX = deltaMap[lowDelta].begin();
					while(listIterHighX != deltaMap[lowDelta].end())
					{
						if((*listIterHighX > *listIterLowX) && 
						   ((*listIterHighX + lowDelta) < (*listIterLowX + highDelta)))
							return false;
						else 
							listIterHighX++;
					}
				}
				lowDelta++;
				if(lowDelta > highDelta)
					throw Error("Program Error in RankCorrelate swapping algorithm.\n");
			}
		}
		else // we're dealing with an element that is below where it belongs.
		{
			listIterHighX = deltaMap[lowDelta].begin();
			while(true)
			{
				// if this is a valid deltaMap entry
				if(deltaMap.count(highDelta))
				{
					// look for a good swap in deltaMap[lowDelta]
					listIterLowX = deltaMap[highDelta].begin();
					while(listIterLowX != deltaMap[highDelta].end())
					{
						if((*listIterHighX > *listIterLowX) && 
						   ((*listIterHighX + lowDelta) < (*listIterLowX + highDelta)))
							return false;
						else
							listIterLowX++;
					}
				}
				highDelta--;
				if(highDelta < lowDelta)
					throw Error("Program Error in RankCorrelate swapping algorithm.\n");
			}			
		}
	}


	//--------------------------------------------------------------------------------

	bool makeTrade(std::map<int, std::list<int> >&	deltaMap, 
				   std::vector<double>&				y, 
				   std::vector<int>&				yRank,
				   std::list<int>::iterator&		listIterLowX,
				   std::list<int>::iterator&		listIterHighX,
				   int								lowDelta, 
				   int								highDelta, 
				   double							rankCor, 
				   double							requestedRankCor)
	// called by rankCorrelate
	{
		int xLow = *listIterLowX;
		int xHigh = *listIterHighX;
		// first swap...			
		swap(yRank, xLow, xHigh);	
		swap(y, xLow, xHigh);
		// then get the two new elements which will be inserted into map.
		// delta = yVal - xVal = distance y is above its sorted position.
		int deltaXHigh = yRank[xHigh] - (xHigh);
		int deltaXLow = yRank[xLow] - (xLow);				

		// then erase old two elements from map.
		deltaMap[lowDelta].erase(listIterHighX);
		deltaMap[highDelta].erase(listIterLowX);

		// if erasing these elements made either list empty, 
		// we'll need to update our map as well.
		if(deltaMap[highDelta].empty())
			deltaMap.erase(highDelta);
		if(deltaMap[lowDelta].empty())
			deltaMap.erase(lowDelta);

		// now insert two new elements into the map.
		if(deltaXHigh != 0)
			deltaMap[deltaXHigh].push_back(xHigh);
		if(deltaXLow != 0)
			deltaMap[deltaXLow].push_back(xLow);

		if(rankCor >= requestedRankCor || deltaMap.empty())
			return true;
		else 
			return false;
	}

	//--------------------------------------------------------------------------------

	void reOrderYAboutX(const std::vector<int>&		xRankVect, 
						std::vector<int>&			yRankVect,
						std::vector<double>&				yValVect)
	// called by rankCorrelate
	// reorders y and yRank as though they were connected to xRank through a sort of xRank.
	{
		vector<double> valTemp = yValVect;
		vector<int> rankTemp = yRankVect;
		int size = xRankVect.size();
		for(int b=0; b<size; b++)
		{
			yRankVect[xRankVect[b]] = rankTemp[b];
			yValVect[xRankVect[b]] = valTemp[b];
		}
	}

	//--------------------------------------------------------------------------------

	void makeDeltaMap(std::map<int, std::list<int> >&	deltaMap,
					  const std::vector<int>&			yRank)
	// called by rankCorrelate
	{
		int size = yRank.size();
		int delta;  // how many slots an element is above where it should be 
					// (if the vector was sorted).
		// i is our implicit sorted x index.
		for(int i=0; i<size; i++)
		{
			// how far the element is above where it should be = rank - where it should be.
			delta = yRank[i] - i;
			if(delta != 0)	// if delta == 0, the element happens to be in the right spot, so 
							// don't insert it into the map of misplaced elements.
				// if delta != 0, insert into the list at mapping "delta" 
				// the index at which we find an element that is
				// "delta" slots above where it should be.
				deltaMap[delta].push_back(i);
		}
	}

	//--------------------------------------------------------------------------------
};


//--------------------------------------------------------------------------------

double CorrelationStuff::correlation(const vector<double>&	a, 
				   const vector<double>&	b)
{
	int size = a.size();
	if(size != b.size())
		throw Error("Program Error in Correlation:"
					+(std::string)"\nvectors of unequal size.\n");
	double a_total = 0;
	double b_total = 0;
	for(int i=0; i<size; i++)
	{
		a_total += a[i];
		b_total += b[i];
	}
	double aMean = a_total/size;
	double bMean = b_total/size;

	double a_square_difference_sum = 0;
	double b_square_difference_sum = 0;

	for(int i=0; i<size; i++)
	{
		a_square_difference_sum += pow((a[i]-aMean),2.0);
		b_square_difference_sum += pow((b[i]-bMean),2.0);
	}
	double aStdDev = sqrt(a_square_difference_sum/((double)size-1.0));
	double bStdDev = sqrt(b_square_difference_sum/((double)size-1.0));

	double corr_sum = 0;
	for(int i=0; i<size; i++)
	{
		corr_sum += ((a[i]-aMean)/aStdDev)*((b[i]-bMean)/bStdDev);
	}
	
	return corr_sum/(double)(size-1);
}


double CorrelationStuff::rankCorrelation(const vector<double>&		a, 
					   const vector<double>&		b)
{
	if(a.size() != b.size())
		throw Error("Program Error in rankCorrelation:"
			+(std::string)"\nvectors of unequal size.\n");
	vector<int> a_rank(a.size());
	vector<int> b_rank(a.size());
	return CorrelationStuff::rankCorrelation(a, b, a_rank, b_rank);
}


double CorrelationStuff::rankCorrelation(const vector<double>&		a, 
					   const vector<double>&		b, 
					   vector<int>&					aRank, 
					   vector<int>&					bRank)
{
	int size = a.size();
	// since we'll be dealing with large numbers, it'll be helpful in calculations to 
	// have this as a double, rather than an int.
	double size_double = size;
	if(size != b.size() || size != aRank.size() ||
				size != bRank.size())
		throw Error("Program Error in rankCorrelation:"
			+(std::string)"\nvectors of unequal size.\n");
	rank(a, aRank);
	rank(b, bRank);
	// we use a double for this number rather than an integer because the number
	// can be very large for large vector sizes.
	double rank_delta_squared_sum = 0;
	for(int i=0; i<size; i++)
		rank_delta_squared_sum += (double)(aRank[i]-bRank[i]) 
									* (double)(aRank[i]-bRank[i]);
	return 1.0 - 6.0 * rank_delta_squared_sum
					/(size_double*size_double*size_double - size_double);
}



void CorrelationStuff::rankCorrelate(const vector<double>&	x, 
				   vector<double>&			y, 
				   double					requestedRankCor)
{
	int size = x.size();
	if(size != y.size())
		throw Error("Program Error in rankCorrelate:"
				+(std::string)"\nvectors of unequal size.\n");
	// we'll simplify things by dealing with all cases as though we want
	// positive correlation and then when we're all done, reversing the pseudo-sorted
	// order if we want negative correlation.
	bool flip = false;
	if(requestedRankCor < 0)
	{
		flip = true;
		requestedRankCor *= -1.0;
	}
	if(requestedRankCor>1)
		throw Error("Error in rankCorrelate:"
				+(std::string)"\nrank correlation must be <= 1 and >= -1.\n");

	vector<int> xRank(size);
	vector<int> yRank(size);
	// not only does this tell us what rankCor is, it also establishes xRank and yRank
	double rankCor = CorrelationStuff::rankCorrelation(x, y, xRank, yRank);

	// if rankCor happens to already have greater magnitude than requested...
	// ...uh... sorry - that's just the way it is.
	if((rankCor > requestedRankCor && requestedRankCor > 0) 
		|| (rankCor < requestedRankCor && requestedRankCor < 0))
	{
		cout << "The rankCorrelation you requested was closer to zero than the\n"
			 << "independently generated sample space\n"
			 << "Sorry, but I'm not going to give you any better.\n";
		return;
	}

	reOrderYAboutX(xRank, yRank, y);

	// The list at mapping delta is a list of the implicit sorted x indices 
	// whose associated y's are delta distance away from their sorted positions.
	map<int, list<int> > deltaMap; 
	// deltaMap is passed by reference and constructed in the following function.
	makeDeltaMap(deltaMap, yRank);

	// we'll step through the map from either end - moving those elements furthest
	// from where they should be first.
	int lowestDelta = -size, highestDelta = size, lowDelta, highDelta;

	// our listIters will point to list elements within our map.  
	// therefore, they're pointing to an implicit sorted x value with an unsorted associated y.
	list<int>::iterator listIterLowX, listIterHighX;

	// we have to use double typecasting here because we have roughly 6/(size cubed) and the 
	// denominator is quite large for large vector sizes.
	double size_double = size;
	double c = 6.0/(size_double*size_double*size_double - size_double);
	bool goHome = false; // we set this when we've made rankCor >= requestedRankCor
	double newRankCor = rankCor;
	while(!goHome)
	{
		// go to next valid lowestDelta & highestDelta mappings.
		while(deltaMap.count(lowestDelta) == 0)
			if(lowestDelta < -1)
				lowestDelta++;
			else 
				throw Error("Program Error in rankCorrelate:"
						+(std::string)"\nProblem with swapping algorithm.\n");
		while(deltaMap.count(highestDelta) == 0)
			if(highestDelta > 1)
				highestDelta--;
			else
				throw Error("Program Error in rankCorrelate:"
						+(std::string)"\nProblem with swapping algorithm.\n");
		// now we know the degree of the most egregious sorted-order-offenders
		highDelta = highestDelta;
		lowDelta = lowestDelta;

		// Now find a pair to swap
		goHome = findTrade(deltaMap, listIterLowX, listIterHighX, lowDelta, highDelta);

// -----------------------------
		if(goHome == true)
		{
			cout << "\n\nhuh?\n\n";
			break;
		}
// -----------------------------

		// check what new rank correlation would be...
		// I'm typecasting with doubles because I was having trouble with large vectors
		// and I suspect the problem was with numbers getting out of integer range.
		newRankCor += c *((double)highDelta*(double)highDelta + (double)lowDelta*(double)lowDelta);
		newRankCor -= c * ((double(yRank[*listIterLowX] - *listIterHighX)) 
								* (double(yRank[*listIterLowX] - *listIterHighX))
							+ (double(yRank[*listIterHighX] - *listIterLowX)) 
								* (double(yRank[*listIterHighX] - *listIterLowX)));
		if(newRankCor < rankCor)
				throw Error("Program Error in rankCorrelate:"
						+(std::string)"\nProblem with swapping algorithm.\n");

		// Here, we'll make the swap and update 

		rankCor = newRankCor;
		goHome = makeTrade(deltaMap, y, yRank, listIterLowX, listIterHighX, lowDelta, highDelta, rankCor, requestedRankCor);
  }


	// if we wanted a negative correlation...
	if(flip == true)
		for(int b=0; b<size; b++)
			// change all ranks from b to size - b.
			xRank[b] = size - 1 - xRank[b];
	// now, we need to re-arrange y relative to x's actual non-sorted order.
	// perhaps we can come up with a more space-efficient way to do this.
// -----------------------------------------------------------------------------
	vector<double> temp = y;
	for(int b=0; b<size; b++)
		y[b] = temp[xRank[b]];
	return;
}



void CorrelationStuff::decayRankCorrelate(const vector<double>&	x, 
						vector<double>&			y, 
						double					requestedRankCor)
{
	int size = x.size();
	if(size != y.size())
		throw Error("Program Error in decayRankCorrelate:"
			+(std::string)"\nvectors of unequal size.\n");
	// we'll simplify things by dealing with all cases as though we want
	// positive correlation and then when we're all done, reversing the pseudo-sorted
	// order if we want negative correlation.
	bool flip = false;
	if(requestedRankCor < 0)
	{
		flip = true;
		requestedRankCor *= -1.0;
	}
	if(requestedRankCor>1)
		throw Error("Error in decayRankCorrelate:"
			+(std::string)"\nmust have -1 <= requested rank correlation <= 1.\n");
	double rank_cor = CorrelationStuff::rankCorrelation(x, y);

	vector<int> xRank(size);
	vector<int> yRank(size);
	// this establishes xRank and yRank
	rank(x, xRank);
	rank(y, yRank);

	vector<double> tempVals = y;
	vector<int> tempRanks = yRank;
	for(int b=0; b<size; b++)
	{
		//this sorts y and yRank.
		yRank[tempRanks[b]] = tempRanks[b];
		y[tempRanks[b]] = tempVals[b];
	}
	// we should only generate the value "size" very infrequently, if ever.
	Uniform unif(0, size);
	// since it's sorted, the rankCorrelation (relative to another sorted vector)
	// is exactly 1.
	rank_cor = 1.0;
	// we have to use double typecasting here because we have roughly 6/(size cubed) and the 
	// denominator is quite large for large vector sizes.
	double size_double = size;
	double c = 6.0/(size_double*size_double*size_double - size_double);

//
//	ofstream outfile("rankCors.csv");
//	if (outfile.is_open())
//	{
//		outfile.precision(10);
//
		
	int j = 0;
	if(requestedRankCor != 1.0)
	{
		int neighborDistance = 1;
		while(rank_cor>requestedRankCor)
		{
			for(int i=0; i<2*size && rank_cor > requestedRankCor; i++)
			{
				int u = size;
				int uNeighbor;
				while(u == size)
					u = unif.sample();
				// now we know 0<=u<=size-1
				if((unif.sample() > size/2 && u < size-neighborDistance) || u < neighborDistance)
					uNeighbor = u+neighborDistance;
				else
					uNeighbor = u-neighborDistance;
		
				int oldDelta1 = yRank[u] - u;
				int oldDelta2 = yRank[uNeighbor] - uNeighbor;
				rank_cor += c*((double)oldDelta1*(double)oldDelta1 + (double)oldDelta2*(double)oldDelta2);
		
				swap(yRank, u, uNeighbor);
				swap(y, u, uNeighbor);
		
				int newDelta1 = yRank[u] - u;
				int newDelta2 = yRank[uNeighbor] - uNeighbor;
				rank_cor -= c*((double)newDelta1*(double)newDelta1 + (double)newDelta2*(double)newDelta2);

//			so we should get 10 rank_cors per neighborDistance.
//			if(i%(size/5) == 0)
//			outfile << i + j*size*2 << "," << neighborDistance << ", " << rank_cor << "\n";
//
			}
			j++;
			// I arbitrarily chose "size/10" because it seemed like an appropriate number
			// perhaps some mathematics could be applied to find a better number.
			if(neighborDistance < size/8)
				neighborDistance *= 2;
		}
	}


//
//		outfile.close();
//	}
//

	// if we wanted a negative correlation...
	if(flip == true)
		for(int b=0; b<size; b++)
			// change all ranks from b to size - b.
			xRank[b] = size - 1 - xRank[b];
	// now, we need to re-arrange y relative to x's actual non-sorted order.
	// perhaps we can come up with a more space-efficient way to do this.
// -----------------------------------------------------------------------------
	vector<double> temp = y;
	for(int b=0; b<size; b++)
		// y-result's intended entry is y-old's (xRank[b])'th entry
		// (the more closely rank correlated, the closer yRank[b] will be to xRank[b].
		y[b] = temp[xRank[b]];
	return;
}




void CorrelationStuff::nicholsNormal(vector<double>& x, vector<double>& y, double r,
				   double xMean, double xStdDev, double yMean, double yStdDev)
{
	int size = x.size();
	if (size != y.size())
		throw Error("Program Error in bivariate normal generator:"
			+(std::string)"\nvectors of unequal size.\n");
	if (r < -1 || r > 1)
		throw Error("Error in bivariate normal generator:"
			+(std::string)"\nmust have -1 <= requested correlation <= 1.\n");
	else
	{
		// we'll use standard normals and then convert them to have the desired
		// means & standard deviations.
		Normal a(0, 1);
		a.batch(x);
		a.batch(y);
		for(int i=0; i<size; i++)
			y[i] = x[i]*r + y[i]*sqrt(1.0 - r*r);
		// now it's time to apply a transformation to the two standard normals to 
		// give them the requested means & standard deviations.
		for(int i=0; i<size; i++)
		{
			x[i] = x[i]*xStdDev + xMean;
			y[i] = y[i]*yStdDev + yMean;
		}
		return;
	}
}

