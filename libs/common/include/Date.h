#ifndef COMMON_LIB__DATE_H
#define COMMON_LIB__DATE_H

//-----------------------------------------------------------------------------

#include "Month.h"

//-----------------------------------------------------------------------------

//  Class:  Date
//
//  This class represents a date (year, month, day).

class Date
{
    //------------
    //  Attributes

    public:

	unsigned int year() const;
	    //  The date's year.

	Month month() const;
	    //  The date's month.

	unsigned int day() const;
	    //  The date's day.

    //------------
    //  Operations

	Date(unsigned int year,
	     Month        month,
	     unsigned int day);
	    //  Construct a date.

    //-------------------------------------------------------------------------

    private:

	unsigned int year_;
	Month month_;
	unsigned int day_;
};

//-----------------------------------------------------------------------------

//  Operators to compare dates

bool operator<(const Date & X,
	       const Date & Y);
    //	Is the date {X} before the date {Y}?

bool operator>(const Date & X,
	       const Date & Y);
    //	Is the date {X} after the date {Y}?

bool operator==(const Date & X,
	        const Date & Y);
    //	Is the date {X} the same as the date {Y}?

bool operator!=(const Date & X,
	        const Date & Y);
    //	Is the date {X} different than the date {Y}?

bool operator<=(const Date & X,
	        const Date & Y);
    //	{X} < {Y} or {X} == {Y}?

bool operator>=(const Date & X,
	        const Date & Y);
    //	{X} > {Y} or {X} == {Y}?

//-----------------------------------------------------------------------------

#include "Date.inl"

//-----------------------------------------------------------------------------

#endif
