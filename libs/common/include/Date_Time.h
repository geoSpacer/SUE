#ifndef COMMON_LIB__DATE_TIME_H
#define COMMON_LIB__DATE_TIME_H

//-----------------------------------------------------------------------------

#include "Date.h"
#include "Time_Of_Day.h"

//-----------------------------------------------------------------------------

//  Class:  Date_Time
//
//  This class represents a date and time (i.e, a specific time on a specific
//  day).

class Date_Time
{
    //------------
    //  Attributes

    public:

	const Date & date() const;
	    //	The date-time's date.

	unsigned int year() const;
	    //  The date-time's year.

	Month month() const;
	    //  The date-time's month.

	unsigned int day() const;
	    //  The date-time's day.

	const Time_Of_Day & time() const;
	    //	The date-time's time of day.

	unsigned int hours() const;
	    //  The date-time's hours (between 0 and 23).

	unsigned int mins() const;
	    //  The date-time's minutes (between 0 and 59).

	float secs() const;
	    //  The date-time's seconds (>= 0.0 and < 60.0).

    //------------
    //  Operations

	Date_Time(const Date &	      date,
		  const Time_Of_Day & time);
	    //  Construct a date-time.

    //-------------------------------------------------------------------------

    private:

	Date date_;
	Time_Of_Day time_;
};

//-----------------------------------------------------------------------------

//  Operators to compare date-times

bool operator<(const Date_Time & X,
	       const Date_Time & Y);
    //	Is the date-time {X} before the date-time {Y}?

bool operator>(const Date_Time & X,
	       const Date_Time & Y);
    //	Is the date-time {X} after the date-time {Y}?

bool operator==(const Date_Time & X,
	        const Date_Time & Y);
    //	Is the date-time {X} the same as the date-time {Y}?

bool operator!=(const Date_Time & X,
	        const Date_Time & Y);
    //	Is the date-time {X} different than the date-time {Y}?

bool operator<=(const Date_Time & X,
	        const Date_Time & Y);
    //	{X} < {Y} or {X} == {Y}?

bool operator>=(const Date_Time & X,
	        const Date_Time & Y);
    //	{X} > {Y} or {X} == {Y}?

//-----------------------------------------------------------------------------

#include "Date_Time.inl"

//-----------------------------------------------------------------------------

#endif
