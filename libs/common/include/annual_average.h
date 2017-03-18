#ifndef COMMON_LIB__ANNUAL_AVERAGE_H
#define COMMON_LIB__ANNUAL_AVERAGE_H

//-----------------------------------------------------------------------------

#include "Enum_Vector.h"

enum Month;

//-----------------------------------------------------------------------------

float annual_average(const Enum::Vector<Month, float> & monthly_values);

    //	Compute the annual average for a vector of monthly values.

//-----------------------------------------------------------------------------

#endif
