#ifndef COMMON_LIB__INPUT_VALUE_ERROR_H
#define COMMON_LIB__INPUT_VALUE_ERROR_H

//-----------------------------------------------------------------------------

#include <string>

#include "Multi_Line_Text.h"

//-----------------------------------------------------------------------------

//  Class:  Input_Value::Error
//
//  This abstract class represents an error with an input value.

namespace Input_Value
{
    //-------------------------------------------------------------------------

    class Error
    {
	public:
	    //------------
	    //  Operations

	    Error(const Input::Value & value);
		//  Construct an error for the given input value.

	    Error(const std::string & value_name);
		//  Construct an error for the input value with the given name.

	    virtual
	    Multi_Line_Text message() const = 0;
		//  Construct a message explaining the error.

	    //------------
	    //  Attributes

	    const std::string & name() const;
		//  The name of the input value that the error's associated
		//  with.

	//---------------------------------------------------------------------

	private:
	    std::string name_;
    };

    //-------------------------------------------------------------------------
};

//-----------------------------------------------------------------------------

namespace Input_Value_Error
{
    //-------------------------------------------------------------------------

    //	Class:  Missing
    //
    //	This class represents the error where an input value is missing.

    class Missing
	: public Input_Value::Error
    {
	public:
	    //------------
	    //	Operations

	    Missing(const Input::Value & value);

	    Multi_Line_Text message() const;
    };

    //-------------------------------------------------------------------------

    //	Class:  Custom
    //
    //	This class represents an error that's specific to a particular input
    //	value.

    class Custom
	: public Input_Value::Error
    {
	public:
	    //------------
	    //	Operations

	    Custom(const Input::Value &	   value,
		   const Multi_Line_Text & message);

	    Custom(const std::string &	   name,
		   const Multi_Line_Text & message);

	    Multi_Line_Text message() const;

	//---------------------------------------------------------------------

	private:
	    Multi_Line_Text message_;
    };

    //-------------------------------------------------------------------------
};

//-----------------------------------------------------------------------------

#include "Input_Value_Error.inl"

//-----------------------------------------------------------------------------

#endif
