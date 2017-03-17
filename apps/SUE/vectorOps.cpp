#include "pragmas.h"

#include <cmath>
#include <iostream>
#include <algorithm>
#include <fstream>

#include "vectorOps.h"
#include "common/Error.h"

using namespace std;

void histogramize(const std::vector<double>&	vect, 
				  int							boxes, 
				  string						fylName, 
				  double						excludedTails)
{
	int size = vect.size();
	double low, high;
	// if we're histogramizing all of vect...
	if(excludedTails == 0)
	{
		low = vect[0];
		high = low;
		for(int i=0; i<size; i++)
		{
			if(vect[i]<low)
				low = vect[i];
			if(vect[i]>high)
				high = vect[i];
		}
	}
	else // if we're only histogramizing the middle onlyMiddlePercent % of vect
	{
		VectorStats vect_stats(vect);
		// this will set low and high to be the low and high boundaries for the middle % we want.
		vect_stats.percentileBounds(100-excludedTails, low, high);
	}
	double range = high - low; 
	double box_width = range/boxes;

	// here's the vector in which we'll store the histogram 
	// (with values initialized at zero).
	vector<double>* hist_vect = new vector<double>(boxes,0.0);

	// how many items fit in the range of each box?
	for(int i=0; i<size; i++)
	{
		// let's figure out which histogram box to put vect[i] into.
		// integer division takes the floor of a decimal number
		// which is exactly what we want here
		int slot = (int)((vect[i] - low)/box_width);
		if(vect[i] == high)
			// we have a problem in the case where array[i] = high.
			// In this situation, we don't want to try to slot it into
			// histArray[boxes] since histArray is only valid for 
			// 0 through boxes - 1.  
			slot--;
		
		if(vect[i] > high || vect[i] < low)
		{	// if we get into this if statement, excludedTails must be non-zero

			// should? put an assert here to make sure.

			// jump to next iteration without incrementing
			// any hist_vect slots because current vect[i] is outside
			// the middle percent we're looking at.
			continue;
		}
		// increment histArray[slot] because we have a hit!
		(*hist_vect)[slot]++;
	}// end for(int i=0; i<size; i++)

	// now convert the number of items in each box into the proportion in each
	// and print the stuff out.

	// make a .csv file.  We'll use \n for new line since it
	// is legible in a text editor and Excel likes it.
	ofstream outfile(fylName.c_str());
	if (outfile.is_open())
	{
		for(int i=0; i<boxes; i++)
			outfile << low + i*box_width << " to " << low + (i+1)*box_width << "," 
			 << (double)((double)((*hist_vect)[i])/(double)size) << "\n";
		outfile.close();
	}
	else
	{
		cout << "Error opening file";
	}
	// clean up our mess.
	delete hist_vect;
	return;
}


VectorStats::VectorStats(const vector<double>& vect)
{
	_sortedVectPtr = NULL;	// we won't make this until we need it.
	_originalVectPtr = &vect;
}

VectorStats::~VectorStats()
{
	if(_sortedVectPtr != NULL)	// if we made a sorted vect,
		delete _sortedVectPtr;	// get rid of it.
}


double VectorStats::mean()
{
	int size = _originalVectPtr->size();
	double total = 0;
	for(int i=0; i<size; i++)
		total += (*_originalVectPtr)[i];
	return total/size;
}

double VectorStats::median()
{
	if(_sortedVectPtr == NULL)	// if we haven't already made a sorted vect,
		makeSortedVect();		// do so.
	int size = _sortedVectPtr->size();
	if(size%2 != 0) //size is odd.
		return (*_sortedVectPtr)[size/2]; //integer division works for us here.
	else
		return .5*(*_sortedVectPtr)[size/2-1] + .5*(*_sortedVectPtr)[size/2];
}

double VectorStats::standardDeviation()
{
	int size = _originalVectPtr->size();
	double meen = this->mean();
	double delta_square_sum = 0;
	for(int i=0; i<size; i++)
		delta_square_sum += ((*_originalVectPtr)[i]-meen) * ((*_originalVectPtr)[i]-meen);
	return sqrt(delta_square_sum/((double)size-1.0));
}

void VectorStats::percentileBounds(double	percentile, 
								   double&	low, 
								   double&	high)
{
	if(_sortedVectPtr == NULL)	// if we haven't already made a sorted vect,
		makeSortedVect();		// do so.
	int size = _sortedVectPtr->size();
	// tail_size is the size (as a portion of size) of EACH tail 
	// (where "tail" is that which lies outside the middle "percentile")
	// so if we want the bounds enclosing the middle 75%, tail_size = 12.5% = .125
	double tail_size = (100.0 - percentile)/200.0;
	// "d_slot" is set to the slot at which we naively expect to find lowBound
	// in our vector.
	double d_slot = tail_size * size;
	// if the naive approach happens to be OK because "d_slot" works out to be an integer...
	if(d_slot == (int) d_slot)
	{
		low = (*_sortedVectPtr)[d_slot];
		high = (*_sortedVectPtr)[size - d_slot - 1];
	}
	else 
	{	// if "d_slot" isn't an integer, we can't draw our value from 
		// one vector element, so we'll take it from the two closest elements  
		// and weight them according to whichever is closer to (double) "d_slot".

	    // "decimal" is how much closer (as a fraction)
		// "d_slot" is to the "d_slot + 1"th slot than the "d_slot"th slot.
		double decimal = d_slot - (int)d_slot;
		low = (*_sortedVectPtr)[(int)d_slot] * (1-decimal) 
			 + (*_sortedVectPtr)[(int)d_slot+1] * decimal;
		high = (*_sortedVectPtr)[size-(int)d_slot-2] * decimal 
			  + (*_sortedVectPtr)[size-(int)d_slot-1] * (1-decimal);
	}
}

void VectorStats::makeSortedVect()	// makes a sorted vect.
{
	int size = _originalVectPtr->size();
	_sortedVectPtr = new vector<double>(size);
	*_sortedVectPtr = *_originalVectPtr;
	sort(_sortedVectPtr->begin(), _sortedVectPtr->end());
}