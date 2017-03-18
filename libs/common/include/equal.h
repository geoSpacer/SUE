#ifndef COMMON_LIB__EQUAL_H
#define COMMON_LIB__EQUAL_H

//-----------------------------------------------------------------------------

#include "Default_Epsilon.h"

//-----------------------------------------------------------------------------

//  Function template:  equal
//
//  Template argument:
//	Flt_Pt_Type = floating-point type, i.e., float, double
//
//  This function tests two floating-point numbers for equality.  Returns true
//  if the difference between the values is less than the epsilon value.

template<class Flt_Pt_Type>
bool equal(Flt_Pt_Type x,
	   Flt_Pt_Type y,
	   Flt_Pt_Type epsilon = Default_Epsilon<Flt_Pt_Type>::value())
{
    return fabs(x - y) < epsilon;
}

//-----------------------------------------------------------------------------

#endif
