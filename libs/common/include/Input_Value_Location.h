#ifndef COMMON_LIB__INPUT_VALUE_LOCATION_H
#define COMMON_LIB__INPUT_VALUE_LOCATION_H

//-----------------------------------------------------------------------------

//  Class template:  Input_Value::Location
//
//  Template parameters:
//	Value_Type = input value's type
//
//  This class represents the location where an input value is stored.
//  Class for input-value's location (where it will be stored)

namespace Input_Value
{
    //-------------------------------------------------------------------------

    template<class Value_Type>
    class Location
    {
	public:
	    //------------
	    //  Operations

	    Location(Value_Type & location);
		//  Construct with a reference to the given location.

	protected:
	    //------------
	    //  Attributes

	    Value_Type & location_;
    };

    //-------------------------------------------------------------------------
};

//-----------------------------------------------------------------------------

#include "Input_Value_Location.inl"

//-----------------------------------------------------------------------------

#endif
