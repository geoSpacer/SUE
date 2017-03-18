#ifndef COMMON_LIB__INPUT_VALUE_FORMAT_ERROR_H
#define COMMON_LIB__INPUT_VALUE_FORMAT_ERROR_H

//-----------------------------------------------------------------------------

#include <string>

#include "Input_Value_Error.h"

//-----------------------------------------------------------------------------

//  Various types of errors for Input::Formatted_Value

namespace Input_Value_Error
{
    //-------------------------------------------------------------------------

    //	Class:  Bad_Value
    //
    //	This abstract class represents the error where an input value is bad.

    class Bad_Value
	: public Input_Value::Error
    {
	//------------
	//  Attributes

	public:

	    const std::string & description() const;
	    const std::string & value() const;

	//------------
	//  Operations

	public:

	    Bad_Value(const Input::Formatted_Value & input_value,
		      const std::string &	     bad_value);
	
	    Bad_Value(const std::string & name,
		      const std::string & description,
		      const std::string & bad_value);
	
	//---------------------------------------------------------------------

	private:
	    std::string description_;
	    std::string value_;
    };

    //-------------------------------------------------------------------------

    //	Class:  Bad_Format
    //
    //	This class represents the error where an input value is improperly
    //	formatted.

    class Bad_Format
	: public Bad_Value
    {
	//------------
	//  Operations

	public:

	    Bad_Format(const Input::Formatted_Value & input_value,
		       const std::string &	      bad_value);

	    Bad_Format(const std::string & name,
		       const std::string & description,
		       const std::string & bad_value);

	    Multi_Line_Text message() const;
    };

    //-------------------------------------------------------------------------

    //	Class:  Too_Big
    //
    //	This class represents the error where an input value is a valid number
    //	but is too big to store.

    class Too_Big
	: public Bad_Value
    {
	//------------
	//  Operations

	public:

	    Too_Big(const Input::Formatted_Value & input_value,
		    const std::string &		   bad_value);

	    Multi_Line_Text message() const;
    };

    //-------------------------------------------------------------------------

    //	Class:  Not_In_Range
    //
    //	This class represents the error where an input value is not in the
    //	range of acceptable values (for a numeric input value).

    class Not_In_Range
	: public Bad_Value
    {
	//------------
	//  Attributes

	public:

	    const std::string & range() const;

	//------------
	//  Operations

	    Not_In_Range(const Input::Formatted_Value & input_value,
			 const std::string &		bad_value,
			 const std::string &		range);

	    Multi_Line_Text message() const;

	//---------------------------------------------------------------------

	private:
	    std::string range_;
    };

    //-------------------------------------------------------------------------
};

//-----------------------------------------------------------------------------

#include "Input_Value_Format_Error.inl"

//-----------------------------------------------------------------------------

#endif
