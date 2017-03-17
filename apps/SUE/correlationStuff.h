
#ifndef CORRELATION_STUFF_H
#define CORRELATION_STUFF_H

#include <vector>
#include <map>
#include <list>

namespace CorrelationStuff
{
	double correlation(const std::vector<double>&	a, 
					   const std::vector<double>&	b);
		// returns r, the pearson correlation coefficient for a & b.

	double rankCorrelation(const std::vector<double>&	a, 
						   const std::vector<double>&	b);
		// returns the spearman rank correlation coefficient for a & b.

	double rankCorrelation(const std::vector<double>&	a, 
						   const std::vector<double>&	b,
						   std::vector<int>&			aRank, 
						   std::vector<int>&			bRank);
		// returns the spearman rank correlation coefficient for a & b.
		// Also fills the int vectors aRank and bRank with the ranks of a and b
		// s.t. if the i'th element of b is the 34th smallest element in b.
		// bRank[i] = 34.

	void rankCorrelate(const std::vector<double>&	x, 
					   std::vector<double>&			y, 
					   double						requestedRankCor);
		// vector y will be rearranged so as to achieve rank correlation
		// >= (but close to if >) rRank.
		// vector x will not change
		// 
		// Resulting scatter-plot spread is more or less uniform about 
		// lines perpendicular to the spline of best fit (where the 
		// spline of best fit would be the spline connecting the points
		// of a requestedRankCor = 1). 
		// 
		// For distributions with long, sparse tails, this method
		// may produce unusual scatter-plot spreads.
		// They are unusual in that there is generally
		// more variance from the spline of best fit
		// around the tails than in denser regions.
		// In the case of correlating two normal curves, this has
		// the effect of making a spread that looks like an hourglass 
		// tipped at an angle.
		// In some cases, this may be desirable, but the user
		// should be aware of this artifact.


	void decayRankCorrelate(const std::vector<double>&	x, 
							std::vector<double>&		y, 
							double						requestedRankCor);
		// a different (probably better) implementation of the above function.
		// this one runs (I think) in O(infinity) worst case, but  
		// should be O(nlgn) in practice.
		// 
		// resulting scatter-plot spread has more of a normal distribution
		// about lines perpendicular to the spline of best fit.
		//
		// This method has the same unusual tail behavior for non-uniform
		// distributions as the above method.

	void nicholsNormal(std::vector<double>&		x, 
					   std::vector<double>&		y, 
					   double					r,
					   double					xMean, 
					   double					xStdDev, 
					   double					yMean, 
					   double					yStdDev);
		// This correlation function differs from the two preceding functions in three 
		// important ways:
		// 1) It ONLY works if both parameters are normal.
		// 2) It is not a "post-generation" correlation function - it actually generates the 
		//		values that will be returned in the two vectors x & y. 
		// 3) It has "better" tail behavior.
}

#endif