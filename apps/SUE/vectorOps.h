#ifndef VECTOR_OPS_H
#define VECTOR_OPS_H

//-----------------------------------------------------------------------------

#include <vector>
#include <string>

//-----------------------------------------------------------------------------

void histogramize(const std::vector<double>&	vect, 
				  int							boxes, 
				  std::string					fylName, 
				  double						excludedTails = 0);
	// histogramize makes a histogram from the values in vect.
	// the histogram has "boxes" rectangles.
	// the histogram goes to a .csv file called fylName.  
	// If double "excludedTails" is entered, 
	// the histogram will only cover the middle (100-excludedTails)% of 
	// the vector's range.  (this can be useful for readability when 
	// there are very long, low probability tails)

class VectorStats
{
public:
	VectorStats(const std::vector<double>& vect);
	~VectorStats();
	double mean();
	double median();
	double standardDeviation();
	void percentileBounds(double	percentile, 
						  double&	low, 
						  double&	high);
private:
	const std::vector<double>* _originalVectPtr;
	std::vector<double>* _sortedVectPtr;
	void makeSortedVect();
};
//-----------------------------------------------------------------------------

#endif

