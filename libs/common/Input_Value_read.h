#ifndef COMMON_LIB__INPUT_VALUE_READ_H
#define COMMON_LIB__INPUT_VALUE_READ_H

//-----------------------------------------------------------------------------

#include <string>
#include <list>

#include "Str_Equal_Func.h"
#include "Ignore_Case.h"
#include "Input_Value.h"
#include "Input_Value_Error.h"

namespace Input_Value
{
    class Line;
};

enum Required_or_Optional;

//-----------------------------------------------------------------------------

//  Additional errors for input values when reading from a line in an
//  input text file.

namespace Input_Value_Error
{
    //-------------------------------------------------------------------------

    //	Class:  Name
    //
    //	This class represents an error with the name of an input value:
    //	a)  A name other than one of the expected names was found on the line,
    //	    or
    //	b)  No value name was found, (i.e., end of file or the line was blank)

    class Name
	: public Input_Value::Error
	    //	The above is a base class so that we can catch all input value
	    //	errors together.
    {
	public:
	    //------------
	    //	Operations

	    Name(const std::list<std::string> & expected_names,
		 const std::string &	        name_found);
		//  Construct an error with the list of expected names.

	    Name(const std::string & expected_name,
		 const std::string & name_found);
		//  Construct an error with a single expected name.

	    Multi_Line_Text message() const;
		//  Construct a message explaining the error.

	    //------------
	    //	Attributes

	    const std::list<std::string> & expected_names() const;
		//  The list of names that were expected.

	    const std::string & name_found() const;
		//  The name that was found on the line.

	//---------------------------------------------------------------------

	private:
	    std::list<std::string> expected_names_;
	    std::string		   name_found_;
    };

    //-------------------------------------------------------------------------

    //	Class:  Extra_Text
    //
    //	This class represents an error where there is extra text after the
    //	input value.

    class Extra_Text
	: public Input_Value::Error
    {
	public:
	    //------------
	    //	Operations

	    Extra_Text(const Input::Value & input_value,
		       const std::string & text);

	    Multi_Line_Text message() const;
		//  Construct a message explaining the error.

	    //------------
	    //	Attributes

	    const std::string & text() const;
		//  The extra text that was found.

	//---------------------------------------------------------------------

	private:
	    std::string text_;
    };

    //-------------------------------------------------------------------------

};

//-----------------------------------------------------------------------------

//  This function reads a single input value from an input line of a text
//  file.  The value is expected to appear on the line by itself in this
//  format:
//
//	    value's_name    value
//
//  The value's name must not contain any whitespace characters.  The
//  parameter {reqd_or_opt} denotes whether the value is required (i.e.,
//  it is an error if it's not found) or optional (i.e., it is not an
//  error if the its name is not found).
//
//  The parameter {str_equal_func} is the function used to compare the value
//  name found on the line with the expected value name.  The default is a
//  case-insenstive comparison: Ignore::eq.  If a case-sensitive comparison
//  is desired, use "std::operator==".
//
//  The function returns "true" if the input value is read successfully.  It
//  returns "false" if the input value is optional and its name is not found.
//  Otherwise, an error occurs, and the function throw one of these
//  expections:
//
//  Input_Value_Error::Name
//	One of these conditions is true:
//	    a) a name other than the value's name was found on the line.
//	    b) the end of the file was found.
//	    c) a blank line was read (if the input file is configured to NOT
//	       skip blank lines).
//      Thrown only if the value is required; if the value is optional, the
//	function returns "false".
//
//  Input_Value_Error::Missing
//	No input value followed the value's name.
//
//  Input_Value_Error::Bad_Format
//	The input value requires a formatted value (e.g., enumerated or
//	numeric types), but a badly-formatted value was found.
//
//  Input_Value_Error::Too_Big
//	The input value requires a numeric value, and a properly-formatted
//	number was found, but it's too big to store internally.
//
//  Input_Value_Error::Not_In_Range
//	The input value accepts a numeric value, but a number was found that's
//	not in the acceptable range of values.
//
//  Input_Value_Error::Extra_Text
//	Extra text was found on the line after the input value.

bool read(Input::Value &       value,
	  Input_Value::Line &  input_line,
	  Required_or_Optional reqd_or_opt,
	  Str_Equal_Func       str_equal_func = Ignore_Case::eq)
    throw(Input_Value::Error);

//-----------------------------------------------------------------------------

#include "Input_Value_read.inl"

//-----------------------------------------------------------------------------

#endif
