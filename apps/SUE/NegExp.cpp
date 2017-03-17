// NegExp.cpp: implementation of the NegExp class.
//
//////////////////////////////////////////////////////////////////////

#include "NegExp.h"
#include <stdlib.h>
#include <math.h>
using namespace std;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

NegExp::NegExp(double low, double stdDev)
{
	_low = low;
	_stdDev = stdDev;
}

NegExp::~NegExp()
{

}


double NegExp::CDFInv(double p) const
{
	return (_low - _stdDev * log(1.0 - p));
}