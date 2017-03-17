// Normal.cpp: implementation of the Normal class.
//
//////////////////////////////////////////////////////////////////////

#include "Normal.h"
#include <cmath>
#include <cstdlib>
using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Normal::Normal(double mode, double stdDev, int discreteIntervals, double stdDevRange)
	// cdfVect is our vector which stores the cumulative areas of the 
	// rectangles under the curve.
	// rectCenterVect stores the "x" value of the center of each of the 
	// rectangles used to generate the _cdfVect values.
	// We use member initialization with the correct size to avoid
	// the default constructor for vectors.
	:_cdfVect(discreteIntervals), _rectCenterVect(discreteIntervals)
{
	// I actually have this number memorized this far.  I'm such a nerd!
	_pi = (3.141592653589793238462643383279502884197169);
	_e = (2.718281828459045235306);
	_mode = mode;
	_stdDev = stdDev;
	// interval width = # of standard deviations we're covering * standard deviation magnitude
	//			(that gives us the range)
	// then divided by (the number of blocks we're dividing that range into).
	_intervalWidth = (2*stdDevRange * _stdDev/(double)discreteIntervals);
	// this is just a constant we use repeatedly later.
	_c1 = 1.0 / (_stdDev * sqrt(2.0 * _pi));

	// keep track of the cumulative area under the curve
	_total = 0;

	// - ("stdDevRange" standard deviations from the mean)
	// is our absolute lower boundary.
	double absolute_left = _mode - (stdDevRange * _stdDev);
	double current_rect_center;
	double current_rect_center_PDF;
	double temp_2;
	for(int i=0; i<discreteIntervals; i++)
	{
		// we're looking at the PDF of the center of the current rectangle
		current_rect_center = absolute_left + (i * _intervalWidth) + (.5 * _intervalWidth);
		current_rect_center_PDF = pdf(current_rect_center);
		// vector is indexed 0 through (_arraySize - 1), so (i-1), not i.
		_rectCenterVect[i] = current_rect_center;
		_total += current_rect_center_PDF * _intervalWidth;
		_cdfVect[i] = _total;
		temp_2 = _cdfVect[i];
	}

	// Now at this point, total should be very close to 1.0, but it's probably
	// not exactly that since we're ignoring the PDF tails and only approximating
	// the integral, so we'll want to make sure when we pick a random uniform number
	// (0,1) that we convert that to the interval of our _cdfVect range.
	_scale = _cdfVect[(_cdfVect.size())-1];
}

// vectors will take care of their own deallocation when they go out of scope.
Normal::~Normal()
{
}


// this returns PDF(x)/////////////////////////////////////////////////
double Normal::pdf(double x) const
{
	return _c1 * pow(_e, (-.5 * pow(((x - _mode)/_stdDev),2.0)));
}


double Normal::CDFInv(double p) const
{
	int left = 0;
	int right = _cdfVect.size() - 1;
	int temp;
	double cdf_val = _scale * p;
	// this is a quicksort-like search through our sorted array
	while(true)
	{
		if(0 == (right - left))
			return _rectCenterVect[right];
		// integer division takes the floor, so if we're looking
		// at the interval (1,2), temp will get assigned 1.
		temp = (int)((left + right)/2);
		if(cdf_val < _cdfVect[temp])
		{ 
			right = temp;
		}
		else
			left = temp + 1;
	}
}


