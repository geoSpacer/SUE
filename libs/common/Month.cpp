#include "pragmas.h"

#include <string>
#include <map>

#include "Assert_That.h"
#include "Enum_Contiguous_Sequence.h"
#include "Enum_Vector.h"
#include "Ignore_Case.h"
#include "Enum_Circulator.h"
#include "Enum_assign.h"
#include "map_merge.h"
#include "leap_year.h"

#include "Month.h"

//-----------------------------------------------------------------------------

const Month Enum::Contiguous_Sequence<Month>::min = January;
const Month Enum::Contiguous_Sequence<Month>::max = December;

//-----------------------------------------------------------------------------

namespace
{
    const Enum::Vector<Month, std::string> & month_names()
	//  Returns a reference to a vector of month names.
    {
	static Enum::Vector<Month, std::string> names;
	static bool initialize = true;

	if (initialize)
	{
	    names[Jan] = "January";
	    names[Feb] = "February";
	    names[Mar] = "March";
	    names[Apr] = "April";
	    names[May] = "May";
	    names[Jun] = "June";
	    names[Jul] = "July";
	    names[Aug] = "August";
	    names[Sep] = "September";
	    names[Oct] = "October";
	    names[Nov] = "November";
	    names[Dec] = "December";

	    initialize = false;
	}
	return names;
    }
};

//-----------------------------------------------------------------------------

const std::string & name(const Month & month)
{
    ASSERT_THAT(January <= month && month <= December);
    return month_names()[month];
}

//-----------------------------------------------------------------------------

namespace
{
    const Enum::Vector<Month, std::string> & month_abbrs()
	//  Returns a reference to a vector of abbreviations for month names.
    {
	static Enum::Vector<Month, std::string> abbrs;
	static bool initialize = true;

	if (initialize)
	{
	    abbrs[Jan] = "Jan";
	    abbrs[Feb] = "Feb";
	    abbrs[Mar] = "Mar";
	    abbrs[Apr] = "Apr";
	    abbrs[May] = "May";
	    abbrs[Jun] = "Jun";
	    abbrs[Jul] = "Jul";
	    abbrs[Aug] = "Aug";
	    abbrs[Sep] = "Sep";
	    abbrs[Oct] = "Oct";
	    abbrs[Nov] = "Nov";
	    abbrs[Dec] = "Dec";

	    initialize = false;
	}
	return abbrs;
    }
};

//-----------------------------------------------------------------------------

const std::string & name_abbr(const Month & month)
{
    ASSERT_THAT(January <= month && month <= December);
    return month_abbrs()[month];
}

//-----------------------------------------------------------------------------

namespace
{
    //-------------------------------------------------------------------------

    typedef std::map<std::string, Month, Ignore_Case> Str_To_Month_Map;
	//  A typedef representing a map of strings to months.

    //-------------------------------------------------------------------------

    const Str_To_Month_Map & name_map()
	//  Returns a reference to a map of strings (i.e., month names) to
	//  months.
    {
	static Str_To_Month_Map map;
	static bool initialize = true;

	if (initialize)
	{
	    Enum::Circulator<Month> month;
	    for (month.from(Jan, To, Dec); with_each(month); )
		map[ month_names()[month] ] = month;
	    initialize = false;
	}
	return map;
    }

    //-------------------------------------------------------------------------
};

//-----------------------------------------------------------------------------

bool name_to_month(const std::string & name,
		   Month &	       month)
{
    return Enum::assign(month, name, name_map());
}

//-----------------------------------------------------------------------------

namespace
{
    const Str_To_Month_Map & abbr_map()
	//  Returns a reference to a map of strings (i.e., abbreviations of
	//  month names) to months.
    {
	static Str_To_Month_Map map;
	static bool initialize = true;

	if (initialize)
	{
	    Enum::Circulator<Month> month;
	    for (month.from(Jan, To, Dec); with_each(month); )
		map[ month_abbrs()[month] ] = month;
	    initialize = false;
	}
	return map;
    }
};

//-----------------------------------------------------------------------------

bool abbr_to_month(const std::string & abbr,
		   Month &	       month)
{
    return Enum::assign(month, abbr, abbr_map());
}

//-----------------------------------------------------------------------------

namespace
{
    const Str_To_Month_Map & name_and_abbr_map()
	//  Returns a reference to a map of strings (i.e., month names and
	//  their abbreviations) to months.
    {
	static Str_To_Month_Map map(merge(name_map(), abbr_map()));
	return map;
    }
};

//-----------------------------------------------------------------------------

bool name_or_abbr_to_month(const std::string & name_or_abbr,
			   Month &	       month)

{
    return Enum::assign(month, name_or_abbr, name_and_abbr_map());
}

//-----------------------------------------------------------------------------

unsigned int days_in(Month	  month,
		     unsigned int year)
{
    ASSERT_THAT(January <= month && month <= December);
    switch (month) {
        case January:
	case March:
	case May:
	case July:
	case August:
	case October:
	case December:
	    return 31;

	case April:
	case June:
	case September:
	case November:
	    return 30;

	default:  // February
	    return leap_year(year) ? 29 : 28;
    }
}
