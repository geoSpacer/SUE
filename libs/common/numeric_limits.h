#ifndef COMMON_LIB__NUMERIC_LIMITS_H
#define COMMON_LIB__NUMERIC_LIMITS_H

//-----------------------------------------------------------------------------

//  Functions to make it a little easier to access the minimum and maximum
//  acceptable values for a numeric type.

int max_int();
    //	The maximum value for an "int".

int min_int();
    //	The minimum negative value for an "int".

float max_float();
    //	The maximum value for a "float".

float min_float();
    //	The minimum value for a "float", i.e., the largest *negative*
    //	floating-point number that can be stored in a "float" variable.

//-----------------------------------------------------------------------------

#include "numeric_limits.inl"

//-----------------------------------------------------------------------------

#endif
