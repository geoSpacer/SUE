#ifndef COMMON_LIB__PERCENT_H
#define COMMON_LIB__PERCENT_H

//-----------------------------------------------------------------------------

inline
float percent(float percentage)
    //	Return the decimal equivalent of a percentage.
    //	Example: percent(85) returns .85
{
    return float(percentage / 100.0);
}

//-----------------------------------------------------------------------------

#endif
