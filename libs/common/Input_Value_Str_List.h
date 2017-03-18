#ifndef COMMON_LIB__INPUT_VALUE_STR_LIST_H
#define COMMON_LIB__INPUT_VALUE_STR_LIST_H

//-----------------------------------------------------------------------------

#include <string>
#include <vector>

#include "Input_Value_Location.h"
#include "Input_Value.h"
#include "Input_Value_Error.h"

//-----------------------------------------------------------------------------

//  Class:  Input_Value::Str_List
//
//  This represents an input value of a list of strings (words).

namespace Input_Value
{
    //-------------------------------------------------------------------------

    class Str_List
	: public Location< std::vector<std::string> >,
	  public Input::Value
    {
	public:
	    //------------
	    //  Operations

	    Str_List(std::vector<std::string> &	location,
		     const std::string &	name);
		//  Construct an input value for a list of strings with the
		//  with the given location and name.

	    void read(std::istringstream & strm)
		    throw(Input_Value::Error);
		//  Read a list of whitespace-separated string input values
		//  from a string stream.
    };

    //-------------------------------------------------------------------------
};

//-----------------------------------------------------------------------------

#endif
