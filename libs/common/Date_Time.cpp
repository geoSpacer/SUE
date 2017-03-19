//-----------------------------------------------------------------------------
//  Class implementation:  Date_Time
//-----------------------------------------------------------------------------

#include "Date_Time.h"
#include "Assert_That.h"

//-----------------------------------------------------------------------------

Date_Time::Date_Time(const Date &	 date,
		     const Time_Of_Day & time)
    : date_(date),
      time_(time)
{
}

//-----------------------------------------------------------------------------

bool operator<(const Date_Time & X,
	       const Date_Time & Y)
{
    if (X.date() < Y.date())
	return true;
    if (X.date() > Y.date())
	return false;

    //	Same date, so check times.
    if (X.time() < Y.time())
	return true;
    return false;
}

//-----------------------------------------------------------------------------

bool operator==(const Date_Time & X,
	        const Date_Time & Y)
{
    return (X.date() == Y.date()) &&
	   (X.time() == Y.time());
}
