//-----------------------------------------------------------------------------
//  Class implementation:  Date
//-----------------------------------------------------------------------------

#include "Date.h"
#include "Assert_That.h"

//-----------------------------------------------------------------------------

Date::Date(unsigned int year,
	   Month        month,
	   unsigned int day)
    : year_(year),
      month_(month),
      day_(day)
{
    ASSERT_THAT(January <= month && month <= December)
    ASSERT_THAT(1 <= day && day <= days_in(month, year))
}

//-----------------------------------------------------------------------------

bool operator<(const Date & X,
	       const Date & Y)
{
    if (X.year() < Y.year())
	return true;
    if (X.year() > Y.year())
	return false;

    //	Same year, so check months.
    if (X.month() < Y.month())
	return true;
    if (X.month() > Y.month())
	return false;

    //	Same month, so check days.
    if (X.day() < Y.day())
	return true;
    return false;
}

//-----------------------------------------------------------------------------

bool operator==(const Date & X,
	        const Date & Y)
{
    return (X.year()  == Y.year()) &&
	   (X.month() == Y.month()) &&
	   (X.day()   == Y.day());
}
