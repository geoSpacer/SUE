#ifndef COMMON_LIB__PROGRAM_OPTIONS_H
#define COMMON_LIB__PROGRAM_OPTIONS_H

//-----------------------------------------------------------------------------

#include <string>
#include <vector>

#include "Program_Option.h"
#include "Str_Equal_Func.h"

//-----------------------------------------------------------------------------

//  Class:  Program_Options
//
//  This class represents the set of command-line options that a program
//  accepts.

class Program_Options
{
    public:
	//------------
	//  Operations

	Program_Options(bool	       abbreviations  = true,
			Str_Equal_Func str_equal_func = std::operator==);
	    //	Create an empty set of options.  If {abbreviations} is true,
	    //	abbreviations of option names will be accepted as well as the
	    //	full names.  {str_equal_func} is used for checking if an
	    //	argument matches an option's name or abbreviation.

	void define(const std::string &	 name,
		    unsigned int	 id,
		    Required_or_Optional reqd_or_opt,
		    Value_Status	 value_status);
	    //	Define a new option, and add it to the set.

	bool match(const std::string & argument,
		   unsigned int	&      id,
		   bool &	       value_present,
		   std::string &       value);
	    //	Check if the given argument matches a defined option.  If so,
	    //	the function does the following and then returns "true":
	    //	
	    //	    1)  The option's id is assigned to {id}.
	    //	    2)  {value_present} is assigned accordingly to indicate if
	    //		a value was specified with the option.
	    //	    3)  If a value is present, it's assigned to {value}.
	    //
	    //	The function returns "false" if the argument does not start
	    //	with the initial sequence for an option.
	    //
	    //	An Error exception is thrown if the argument starts with the
	    //	initial sequence for an option, but one of these is true:
	    //
	    //	    1)  There's no option name.
	    //	    2)  The option's name is unknown.
	    //	    3)  The abbreviation used for the name is ambiguous (i.e.,
	    //		it matches 2 or more option names).
	    //	    4)  A value is specified and the option does not require
	    //		a value.
	    //	    5)  No value is specified, and the option requires one.

	void ensure_all_reqd_matched() const;
	    //	Check if all of the required options were matched.  If there
	    //	any required options that were not matched, then an Error
	    //	exception is thrown.

    private:
	bool abbreviations_;
	    //	Are abbreviations accepted as well?

	Str_Equal_Func str_equal_func_;
	    //	The function for matching an argument with a name or
	    //	abbreviation.

	std::vector<Program_Option> options_;
	    //	The defined options.

	std::vector<bool> matched_;
	    //	element [i] = "true" if the options_[i] was matched.
};

//-----------------------------------------------------------------------------

#endif
