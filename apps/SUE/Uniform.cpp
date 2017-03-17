// Uniform.cpp: implementation of the Uniform class.
//
//////////////////////////////////////////////////////////////////////

#include "Uniform.h"
#include <stdlib.h>
using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

// We're assuming lowerBound < upperBound.
Uniform::Uniform(double		lowerBound, 
				 double		upperBound)
{
	_lower = lowerBound;
	_upper = upperBound;
	_range = upperBound - lowerBound;
}

Uniform::~Uniform()
{

}

double Uniform::CDFInv(double p) const
{
	return p * _range + _lower;
}
