#ifndef COMMON_LIB__INPUT_FORMATTED_VALUE_H
#define COMMON_LIB__INPUT_FORMATTED_VALUE_H

//-----------------------------------------------------------------------------

#include <string>

#include "Input_Value.h"

//-----------------------------------------------------------------------------

//  Class:  Input::Formatted_Value
//
//  This abstract class represents a formatted input-value, i.e., it has a
//  certain format, so only a limited set of strings are valid values (e.g.,
//  numeric types or enumerated types).

namespace Input
{
    //-------------------------------------------------------------------------

    class Formatted_Value
	: public Value
    {
	public:
	    //------------
	    //  Operations

	    Formatted_Value(const std::string & name,
			    const std::string & description);
		//  Construct an object with the given description of the
		//  input-value expected (= a brief phrase).

	    //------------
	    //  Attributes

	    const std::string & description() const;
		//  The description of the input value (a brief phrase for user
		//  messages).

	    const std::string & str() const;
		//  The input value as a string.

	//---------------------------------------------------------------------

	protected :
	    std::string str_;

	private :
	    std::string description_;
    };

    //-------------------------------------------------------------------------
};

//-----------------------------------------------------------------------------

#include "Input_Formatted_Value.inl"

//-----------------------------------------------------------------------------

#endif
