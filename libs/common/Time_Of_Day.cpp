//-----------------------------------------------------------------------------
//  Class implementation:  Time_Of_Day
//-----------------------------------------------------------------------------

#include "Time_Of_Day.h"
#include "Assert_That.h"
#include "equal.h"

//-----------------------------------------------------------------------------

Time_Of_Day::Time_Of_Day(unsigned int hours,
			 unsigned int mins,
			 float	      secs)
    : hours_(hours),
      mins_(mins),
      secs_(secs)
{
    ASSERT_THAT(hours <= 23)
    ASSERT_THAT(mins <= 59)
    ASSERT_THAT(0.0 <= secs && secs < 60.0)
}

//-----------------------------------------------------------------------------

bool operator<(const Time_Of_Day & X,
	       const Time_Of_Day & Y)
{
    if (X.hours() < Y.hours())
	return true;
    if (X.hours() > Y.hours())
	return false;

    //	Same hours, so check mins.
    if (X.mins() < Y.mins())
	return true;
    if (X.mins() > Y.mins())
	return false;

    //	Same mins, so check secss.
    if (X.secs() < Y.secs())
	return true;
    return false;
}

//-----------------------------------------------------------------------------

bool operator==(const Time_Of_Day & X,
	        const Time_Of_Day & Y)
{
    return (X.hours()  == Y.hours()) &&
	   (X.mins() == Y.mins()) &&
	   equal(X.secs(), Y.secs());
}
