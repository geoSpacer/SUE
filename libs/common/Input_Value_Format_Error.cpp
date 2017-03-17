//-----------------------------------------------------------------------------
//  Class implementation:  Input_Value_Error::{class}
//-----------------------------------------------------------------------------

#include "pragmas.h"

#include "Input_Value.h"
#include "Input_Formatted_Value.h"
#include "Input_Value_Format_Error.h"
#include "Multi_Line_Text.h"

//-----------------------------------------------------------------------------

namespace Input_Value_Error
{

    //-------------------------------------------------------------------------
    //  Bad_Value
    //-------------------------------------------------------------------------

    Bad_Value::Bad_Value(const Input::Formatted_Value & input_value,
			 const std::string &		bad_value)
	: Input_Value::Error(input_value),
	  description_(input_value.description()),
	  value_(bad_value)
    {
    }

    //-------------------------------------------------------------------------

    Bad_Value::Bad_Value(const std::string & name,
			 const std::string & description,
			 const std::string & bad_value)
	: Input_Value::Error(name),
	  description_(description),
	  value_(bad_value)
    {
    }

    //-------------------------------------------------------------------------
    //  Bad_Format
    //-------------------------------------------------------------------------

    Bad_Format::Bad_Format(const Input::Formatted_Value & input_value,
			   const std::string &		  bad_value)
	: Bad_Value(input_value, bad_value)
    {
    }

    //-------------------------------------------------------------------------

    Bad_Format::Bad_Format(const std::string & name,
			   const std::string & description,
			   const std::string & bad_value)
	: Bad_Value(name, description, bad_value)
    {
    }

    //-------------------------------------------------------------------------

    Multi_Line_Text Bad_Format::message() const
    {
	return Multi_Line_Text("The value \"" + value() +
			       "\" is invalid; expected " + description() +
			       ".");
    }

    //-------------------------------------------------------------------------
    //  Too_Big
    //-------------------------------------------------------------------------

    Too_Big::Too_Big(const Input::Formatted_Value & input_value,
		     const std::string &	    bad_value)
	: Bad_Value(input_value, bad_value)
    {
    }

    //-------------------------------------------------------------------------

    Multi_Line_Text Too_Big::message() const
    {
	return Multi_Line_Text("The value \"" + value() +
			       "\" is too big for " + description() + ".");
    }

    //-------------------------------------------------------------------------
    //  Not_In_Range
    //-------------------------------------------------------------------------

    Not_In_Range::Not_In_Range(const Input::Formatted_Value & input_value,
			       const std::string &	      bad_value,
			       const std::string &	      range)
	: Bad_Value(input_value, bad_value),
	  range_(range)
    {
    }

    //-------------------------------------------------------------------------

    Multi_Line_Text Not_In_Range::message() const
    {

	Multi_Line_Text mesg;
	mesg += "The value \"" + value() +
		"\" is not in the range of acceptable value:";
	mesg += "  " + range();
	return mesg;
    }

    //-------------------------------------------------------------------------
};
