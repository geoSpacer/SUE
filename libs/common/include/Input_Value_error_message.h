#ifndef COMMON_LIB__INPUT_VALUE_ERROR_MESSAGE_H
#define COMMON_LIB__INPUT_VALUE_ERROR_MESSAGE_H

//-----------------------------------------------------------------------------

#include <string>

#include "Multi_Line_Text.h"	//  So the programmer doesn't have to include
				//  it if all she simply wants to do is use
				//  the functions below as arguments to
				//  Input::Text_File::error(...)

//-----------------------------------------------------------------------------

namespace Input_Value
{
    class Error;

    //-------------------------------------------------------------------------

    Multi_Line_Text error_message(const Input_Value::Error & error,
				  const std::string &	     where);
	//  Construct an error message for the given input-value error.
	//  {where} is a brief phrase explaining where the error happened,
	//  e.g., "with the input value "..."", or "in the "..." column".

    //-------------------------------------------------------------------------
};

//-----------------------------------------------------------------------------

namespace Message
{
    //-------------------------------------------------------------------------

    Multi_Line_Text error_with_value(const Input_Value::Error & error);
	//  Construct an error message like this:
	//
	//  Error with the input value "...":
	//    {message based on the type of error}
	//
	//  If the name of the input value is "" (i.e., there is no input value
	//  because the end of the input file has been reached), then this
	//  function just returns the message based on the error type.

    //-------------------------------------------------------------------------

    Multi_Line_Text error_in_column(const Input_Value::Error & error);
	//  Construct an error message like this:
	//
	//  Error in the "..." column:
	//    {message based on the type of error}

    //-------------------------------------------------------------------------
};

//-----------------------------------------------------------------------------

#endif
