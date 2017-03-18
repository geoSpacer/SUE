#ifndef COMMON_LIB__AS_PERCENT_H
#define COMMON_LIB__AS_PERCENT_H

//-----------------------------------------------------------------------------

inline
float as_percent(float value)
    //	Return a value as a percentage.
    //	Example: as_percent(1.5) returns 150 (%).
{
    return float(value * 100.0);
}

//-----------------------------------------------------------------------------

#endif
