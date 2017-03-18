#ifndef COMMON_LIB__INPUT_VALUE_STR_H
#define COMMON_LIB__INPUT_VALUE_STR_H

//-----------------------------------------------------------------------------

#include <string>
#include <sstream>

#include "Input_Value.h"
#include "Input_Value_Location.h"
#include "Input_Value_Error.h"

//-----------------------------------------------------------------------------

//  Class:  Input_Value::Str
//
//  This class represents a string input value, which is a sequence of one or
//  more non-whitespace characters.

namespace Input_Value
{
    //-------------------------------------------------------------------------

    class Str
	: public Input::Value,
	  public Input_Value::Location<std::string>
    {
	public:
	    //------------
	    //  Operations

	    Str(std::string &	    location,
		const std::string & name);
		//  Construct a string input-value with the given location and
		//  name.

	    void read(std::istringstream & strm)
		    throw(Input_Value::Error);
		//  Read a string input-value from a string stream.
    };

    //-------------------------------------------------------------------------
};

//-----------------------------------------------------------------------------

#endif
