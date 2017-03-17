//-----------------------------------------------------------------------------
//  Class implementation:  Program_Options
//-----------------------------------------------------------------------------

#include "pragmas.h"

#include <sstream>
#include <cctype>

#include "Program_Options.h"
#include "Program_Arguments.h"
#include "Assertion_Error.h"
#include "Assert_That.h"

//-----------------------------------------------------------------------------

namespace
{

    //-------------------------------------------------------------------------

    //	The intent is to allow the programmer in the future to change the
    //	following three variables via class operations.

    const std::vector<std::string> & start_sequences()
	//  The vector of character sequences that can start an option.
    {
	static bool initialize = true;
	static std::vector<std::string> sequences;

	if (initialize) {
	    //	The sequences are checked in order, so the "--" must be before
	    //	the "-" if an argument like "--foo" is going to be treated
	    //	correctly.
	    sequences.push_back("--");
	    sequences.push_back("-");
#ifdef WIN32
	    sequences.push_back("/");
#endif
	    initialize = false;
	}

	return sequences;
    }

    //-------------------------------------------------------------------------

};

//-----------------------------------------------------------------------------

Program_Options::Program_Options(bool		abbreviations,
				 Str_Equal_Func str_equal_func)
    : abbreviations_(abbreviations),
      str_equal_func_(str_equal_func),
      options_()
{
    ASSERT_THAT(str_equal_func != 0)
}

//-----------------------------------------------------------------------------

void Program_Options::define(const std::string &  name,
			     unsigned int	  id,
			     Required_or_Optional reqd_or_opt,
			     Value_Status	  value_status)
{
    Program_Option option(name, id, reqd_or_opt, value_status);

    for (unsigned int i = 0; i < options_.size(); i++) {
	if (str_equal_func_(name, options_[i].name)) {
	    std::ostringstream condition;
	    condition << "The option \"" << name << "\" is defined only once.";
	    throw Assertion_Error(condition.str(), __FILE__, __LINE__);
	}
    }

    options_.push_back(option);
    matched_.push_back(false);
}

//-----------------------------------------------------------------------------

bool Program_Options::match(const std::string & argument,
			    unsigned int &	id,
			    bool &		value_present,
			    std::string &	value)
{
    using Program_Arguments::error;

    std::ostringstream mesg;	//  for error messages
	unsigned int i;

    std::string::size_type name_start = 0;
    for (i = 0; i < start_sequences().size(); i++) {
	std::string::size_type sequence_length = start_sequences()[i].size();
	if (argument.substr(0, sequence_length) == start_sequences()[i]) {
	    name_start = sequence_length;
	    break;
	}
    }

    if (i >= start_sequences().size())
	return false;

    //	Scan the option's name.
    std::string::size_type name_end = name_start;
    while (name_end < argument.size() && (isalnum(argument[name_end]) 
					  || argument[name_end] == '_')) {
	name_end++;
    }
    std::string name = argument.substr(name_start, name_end - name_start);
    if (name == "")
	throw error(argument, name, name_start, "Missing option name.");

    //	Do we have a value?
    if (name_end >= argument.size()) {
	value_present = false;
    }
    else if (argument[name_end] == '=') {
	value_present = true;
	value = argument.substr(name_end + 1);
    }
    else {
	throw error(argument, argument.substr(name_end, 1), name_end,
		    "Expected a letter, digit, \"_\", or \"=\".");
    }

    //	Is it the name of a defined option?
    std::vector<int> matched;
    for (unsigned int j = 0; j < options_.size(); j++) {
	if (str_equal_func_(name, options_[j].name)
		|| (abbreviations_
		    && str_equal_func_(name,
				       options_[j].name.substr(0, name.size())
				      )
		   )
	   )
	    matched.push_back(j);
    }
    switch (matched.size())
    {
	case 0:
	    throw error(argument, name, name_start, "Unknown option name.");

	case 1:
	    break;

	default:
	    mesg << "The abbreviation \"" << name
		 << "\" is ambiguous; it matches these options:";
	    for (unsigned int k = 0; k < matched.size(); k++)
		mesg << "\n  \"" << options_[matched[k]].name << "\"";
	    throw error(argument, name, name_start, mesg);
    }

    //	Does this option take a value?
    int index = matched[0];
    id = options_[index].id;
    matched_[index] = true;
    switch(options_[index].value_status)
    {
	case No_Value:
	    if (value_present) {
		mesg << "The option \"" << options_[index].name
					<< "\" does not require a value.";
		throw error(argument, "=", name_end, mesg);
	    }
	    break;

	case Value_Required:
	    if (! value_present || (value_present && value == "")) {
		mesg << "The option \"" << options_[index].name
					<< "\" requires a value.";
		throw error(argument, "=", name_end + (value_present ? 1 : 0),
			    mesg);
	    }
	    break;

	default:    //  Value_Optional
	    break;
    }

    return true;
}

//-----------------------------------------------------------------------------

void Program_Options::ensure_all_reqd_matched() const
{
    std::vector<std::string> unmatched;
    for (unsigned int i = 0; i < matched_.size(); i++) {
	if (! matched_[i] && (bool) options_[i].reqd_or_opt == (bool) Required)
	    unmatched.push_back(options_[i].name);
    }

    if (unmatched.size() == 0)
	return;

    std::ostringstream mesg;
    if (unmatched.size() == 1)
	mesg << "Missing the required option \"" << unmatched[0] << "\".";
    else {
	mesg << "Missing these required options:";
	for (unsigned int j = 0; j < unmatched.size(); j++)
	    mesg << "\n  \"" << unmatched[j] << "\"";
    }
    throw Program_Arguments::error(mesg);
}
