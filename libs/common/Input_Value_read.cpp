//-----------------------------------------------------------------------------
//  Implementation of:  Input_Value_Error::Name class
//			Input_Value_Error::Extra_Text class
//			"read" function
//-----------------------------------------------------------------------------

#include "../pragmas.h"

#include <string>
#include <sstream>

#include "Input_Value_read.h"
#include "Input_Value.h"
#include "Input_Value_Line.h"
#include "Input_Text_File.h"
#include "Required_or_Optional.h"
#include "Multi_Line_Text.h"
#include "Assert_That.h"
#include "has_whitespace.h"
#include "all_whitespace.h"

//-----------------------------------------------------------------------------

namespace Input_Value_Error
{
    //-------------------------------------------------------------------------
    //	Class:  Name
    //-------------------------------------------------------------------------

    Name::Name(const std::list<std::string> & expected_names,
	       const std::string &	      name_found)
	: Input_Value::Error(name_found),
	  expected_names_(expected_names),
	  name_found_(name_found)
    {
    }

    //-------------------------------------------------------------------------

    Name::Name(const std::string & expected_name,
	       const std::string & name_found)
	: Input_Value::Error(name_found),
	  expected_names_(1, expected_name),
	  name_found_(name_found)
    {
    }

    //-------------------------------------------------------------------------

    Multi_Line_Text Name::message() const
    {
	Multi_Line_Text mesg;

	if (expected_names().size() == 1) {
	    mesg += "Expected the input value \"" + expected_names().front()
						  + "\".";
	}
	else {
	    mesg += "Expected one of these input values:";
	    std::list<std::string>::const_iterator p;
	    for (p = expected_names().begin(); p != expected_names().end();
					       ++p) {
		mesg += "  " + *p;
	    }
	}
	return mesg;
    }

    //-------------------------------------------------------------------------
    //	Class:  Extra_Text
    //-------------------------------------------------------------------------

    Extra_Text::Extra_Text(const Input::Value & input_value,
			   const std::string &  text)
	: Input_Value::Error(input_value),
	  text_(text)
    {
    }

    //-------------------------------------------------------------------------

    Multi_Line_Text Extra_Text::message() const
    {
	Multi_Line_Text mesg;
	mesg += "Extra text found after the value:";
	mesg += "  " + text();
	return mesg;
    }

    //-------------------------------------------------------------------------
};

//-----------------------------------------------------------------------------
//  Function "read"
//-----------------------------------------------------------------------------

bool read(Input::Value &       value,
	  Input_Value::Line &  input_line,
	  Required_or_Optional reqd_or_opt,
	  Str_Equal_Func       str_equal_func)
    throw(Input_Value::Error)
{
    ASSERT_THAT(value.name() != "")
    ASSERT_THAT(! has_whitespace(value.name()))
    ASSERT_THAT(str_equal_func != 0)

    std::string rest_of_line;
    if (input_line.name_matches(value.name(), str_equal_func, rest_of_line)) {
	//  Read the value after the name.
	std::istringstream strm(rest_of_line);
	value.read(strm);

	//  Check for extra text after the value.
	std::string extra_text;
	if (! all_whitespace(strm, extra_text, 30))
	    throw Input_Value_Error::Extra_Text(value, extra_text);

	return true;
    }
    else {
	//  Missing name or wrong name on input line
	if ((bool) reqd_or_opt == (bool) Required)
	    throw Input_Value_Error::Name(input_line.unmatched_names(),
					  input_line.value_name());
	else
	    return false;
    }
}
