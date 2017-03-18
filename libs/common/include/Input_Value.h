#ifndef COMMON_LIB__INPUT_VALUE_H
#define COMMON_LIB__INPUT_VALUE_H

//-----------------------------------------------------------------------------

#include <string>
#include <sstream>

namespace Input
{
    class Value_Error;
};

//-----------------------------------------------------------------------------

//  Class:  Input::Value
//
//  This abstract class represents an input value.  Every input value has:
//	1) a name, and
//	2) a member function read() to read the value from a string stream.

namespace Input
{
    //-------------------------------------------------------------------------

    class Value
    {
	public:
	    //------------
	    //  Operations

	    Value(const std::string & name);
		//  Construct an input-value with the given name.

	    virtual
		void read(std::istringstream & strm)
			throw(Value_Error) = 0;
		//  Read an input value from a string stream.

	    //------------
	    //  Attributes

	    const std::string & name() const;
		//  The value's name.

	private:
	    const std::string name_;
    };

    //-------------------------------------------------------------------------
};

//-----------------------------------------------------------------------------

#include "Input_Value.inl"

//-----------------------------------------------------------------------------

#endif
