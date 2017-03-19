#include "leap_year.h"

//-----------------------------------------------------------------------------

bool leap_year(unsigned int year)
{
    if (year % 400 == 0)
	return true;
    if (year % 4 == 0 && year % 100 != 0)
	return true;
    return false;
}
