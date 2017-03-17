// Triangular.cpp: implementation of the Triangular class.
//
//////////////////////////////////////////////////////////////////////

#include <stdlib.h>
#include <math.h>
#include "Triangular.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Triangular::Triangular(double	low, 
					   double	mode, 
					   double	high)
{
	_l = low;
	_m = mode;
	_r = high; 
	_areaLeftOfMode = (_m - _l)/(_r - _l);
	// this following are constants we use in the calculation
	// for sampling from the distribution 
	_c1 = (_m - _l)*(_r - _l);
	_c2a = (_l - _r)*(_r - _m); 
	_c2b = _r * _r - (_l * (_r - _m)) - (_r * _m);
}

Triangular::~Triangular()
{

}




double Triangular::CDFInv(double p) const
{
	if(p < _areaLeftOfMode)
		return lowerCDFInv(p);
	else
		return upperCDFInv(p);
}

double Triangular::lowerCDFInv(double p) const
{
	return _l + sqrt(p * _c1);
}
double Triangular::upperCDFInv(double p) const
{
	return _r - sqrt(p * _c2a + _c2b);
}
