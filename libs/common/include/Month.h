#ifndef COMMON_LIB__MONTH_H
#define COMMON_LIB__MONTH_H

//-----------------------------------------------------------------------------

#include <string>

#include "Str_To_Value.h"

//-----------------------------------------------------------------------------

enum Month
{
    January   = 1,
    February  = 2,
    March     = 3,
    April     = 4,
    May	      = 5,
    June      = 6,
    July      = 7,
    August    = 8,
    September = 9,
    October   = 10,
    November  = 11,
    December  = 12,

    //	3-letter abbreviations
    Jan = January,
    Feb = February,
    Mar = March,
    Apr = April,
    // May is already 3-letters.
    Jun = June,
    Jul = July,
    Aug = August,
    Sep = September,
    Oct = October,
    Nov = November,
    Dec = December
};

//-----------------------------------------------------------------------------

#include "Enum_Contiguous_Sequence.h"
    //	Defines the prefix ++ and -- operators for a Month variable.

//-----------------------------------------------------------------------------

const std::string & name(const Month & month);
    //	Return the month's name.

const std::string & name_abbr(const Month & month);
    //	Return the month's name as a 3-letter abbreviation.

bool name_to_month(const std::string & name,
		   Month &	       month);
    //	Convert a month's name in a string to a month value.
    //	Returns:
    //	    true    Valid name was found in string, and {month} was assigned
    //			the corresponding enumerated value.
    //	    false   No valid month name was found in string.

bool abbr_to_month(const std::string & abbr,
		   Month &	       month);
    //	Convert a month's 3-letter abbreviation in a string to a month value.
    //	Returns:
    //	    true    Valid abbreviation found in string, and {month} was
    //			assigned the corresponding enumerated value.
    //	    false   No valid month abbreviation was found in string.

bool name_or_abbr_to_month(const std::string & name_or_abbr,
			   Month &	       month);
    //	Convert a month's name or 3-letter abbreviation in a string to a
    //	month value.
    //	Returns:
    //	    true    Valid name or abbreviation found in string, and {month}
    //			was assigned the corresponding enumerated value.
    //	    false   No valid month name or abbreviation was found in string.

inline
Str_To_Value<Month>::Func_Ptr Str_To_Value<Month>::default_func()
    //	Returns a pointer to the default function for converting a string to
    //	a month.
{
    return name_or_abbr_to_month;
}

unsigned int days_in(Month	  month,
		     unsigned int year);
    //	Returns the # of days in a particular month.  The year is needed to
    //	determine if it's a leap year.

//-----------------------------------------------------------------------------

#endif
