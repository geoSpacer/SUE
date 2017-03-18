#ifndef COMMON_LIB__INPUT_VALUE_LINE_H
#define COMMON_LIB__INPUT_VALUE_LINE_H

//-----------------------------------------------------------------------------

#include <string>
#include <list>

#include "Str_Equal_Func.h"
    //	We include the above header so that the user need not do so if she
    //	simply specifies std::string::operator== as the 2nd parameter to
    //	"name_matches"(...).

namespace Input
{
    class Text_File;
};

//-----------------------------------------------------------------------------

//  Class:  Input_Value::Line
//
//  This class represents a line from an input text file that may have an input
//  value.  The value appears on the line by itself in this format:
//
//	value's_name	value
//
//  The value's name must not contain any whitespace characters.

namespace Input_Value
{
    //-------------------------------------------------------------------------

    class Line
    {
	public :
	    //------------
	    //  Operations

	    Line();
		//  Construct an input line, and initialize to an empty string.

	    bool read(Input::Text_File & file);
		//  Assign the input line by reading the next available line
		//  from the given input file.  The next available line is
		//  determined on how the input file is configured, i.e.,
		//  whether or not blank and comment lines are being skipped.
		//
		//  Return value:
		//	true	A line was read.
		//	false	No more lines are available from the file (i.e.,
		//		at the end of the file).  The input line's
		//		current value is set to an empty string.
		//
		//  Regardless of the function's return value, the line's
		//  list of unmatched names is reset to an empty list.

	    bool name_matches(const std::string & name,
			      Str_Equal_Func      function,
			      std::string &	  rest_of_line);
		//  Returns "true" if the input line starts with the name of an
		//  input value, and that name matches the specified name.  The
		//  given name and the name on the line are compared using the
		//  given string equality function.  For a case-sensitive
		//  comparsion, use "std::operator=="; for a case-insensitive
		//  comparison, use "Ignore_Case::eq".
		//
		//  If the given name matches the name on the input line, then
		//  the function also returns the text following the name in
		//  the parameter {rest_of_line}.  If names does not match, the
		//  given name is added to the line's list of unmatched names.

	    //------------
	    //  Attributes

	    std::string str() const;
		//  The current value of the input line as a string.

	    std::string value_name() const;
		//  The name of the input value at the beginning of the current
		//  value of the input line.  If the line has no name (i.e.,
		//  it's a blank line because the file has been configured to
		//  not skip blank lines), then the function returns "".

	    std::list<std::string> unmatched_names() const;
		//  The list of names that did not match the value name on the
		//  current value of the input line.

	//---------------------------------------------------------------------

	private:
	    std::string	str_;	    //	Current value of the input line
	    std::string	name_;	    //	Value name on the line
	    int		name_pos_;   //	Position on line where name starts

	    std::list<std::string> unmatched_;  //  List of unmatched name for
						//  the current value of line
    };

    //-------------------------------------------------------------------------
};

//-----------------------------------------------------------------------------

#include "Input_Value_Line.inl"

//-----------------------------------------------------------------------------

#endif
