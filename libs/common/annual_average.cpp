#include "Month.h"
#include "Enum_Circulator.h"

#include "annual_average.h"

//-----------------------------------------------------------------------------

float annual_average(const Enum::Vector<Month, float> & monthly_values)
{
    float sum = 0;
    
    Enum::Circulator<Month> month;
    for (month.from(Jan, To, Dec); with_each(month); )
	sum += monthly_values[month];

    return sum / 12;
}
