#ifndef COMMON_LIB__TIME_OF_DAY_H
#define COMMON_LIB__TIME_OF_DAY_H

//-----------------------------------------------------------------------------

//  Class:  Time_Of_Day
//
//  This class represents a time during a day (clock time).

class Time_Of_Day
{
    //------------
    //  Attributes

    public:

	unsigned int hours() const;
	    //  The time's hours (between 0 and 23).

	unsigned int mins() const;
	    //  The time's minutes (between 0 and 59).

	float secs() const;
	    //  The time's seconds (>= 0.0 and < 60.0).

    //------------
    //  Operations

	Time_Of_Day(unsigned int hours,
		    unsigned int mins,
		    float	 secs);
	    //  Construct a time.

    //-------------------------------------------------------------------------

    private:

	unsigned int hours_;
	unsigned int mins_;
	float secs_;
};

//-----------------------------------------------------------------------------

//  Operators to compare Time_Of_Days

bool operator<(const Time_Of_Day & X,
	       const Time_Of_Day & Y);
    //	Is the time {X} before the time {Y}?

bool operator>(const Time_Of_Day & X,
	       const Time_Of_Day & Y);
    //	Is the time {X} after the time {Y}?

bool operator==(const Time_Of_Day & X,
	        const Time_Of_Day & Y);
    //	Is the time {X} the same as the time {Y}?

bool operator!=(const Time_Of_Day & X,
	        const Time_Of_Day & Y);
    //	Is the time {X} different than the time {Y}?

bool operator<=(const Time_Of_Day & X,
	        const Time_Of_Day & Y);
    //	{X} < {Y} or {X} == {Y}?

bool operator>=(const Time_Of_Day & X,
	        const Time_Of_Day & Y);
    //	{X} > {Y} or {X} == {Y}?

//-----------------------------------------------------------------------------

#include "Time_Of_Day.inl"

//-----------------------------------------------------------------------------

#endif
