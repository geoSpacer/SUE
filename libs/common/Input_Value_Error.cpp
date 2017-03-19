//-----------------------------------------------------------------------------
//  Class implementation:  Input_Value::Error
//			   Input_Value_Error::Missing
//-----------------------------------------------------------------------------

#include "pragmas.h"

#include "Input_Value.h"
#include "Input_Value_Error.h"
#include "Multi_Line_Text.h"

//-----------------------------------------------------------------------------
//  Input_Value::Error
//-----------------------------------------------------------------------------

Input_Value::Error::Error(const Input::Value & value)
    : name_(value.name())
{
}

//-----------------------------------------------------------------------------

Input_Value::Error::Error(const std::string & value_name)
    : name_(value_name)
{
}

//-----------------------------------------------------------------------------

namespace Input_Value_Error
{
    //-------------------------------------------------------------------------
    //  Missing
    //-------------------------------------------------------------------------

    Missing::Missing(const Input::Value & value)
	: Input_Value::Error(value)
    {
    }

    //-------------------------------------------------------------------------

    Multi_Line_Text Missing::message() const
    {
	return Multi_Line_Text("Missing value.");
    }

    //-------------------------------------------------------------------------
    //  Custom
    //-------------------------------------------------------------------------

    Custom::Custom(const Input::Value &	   value,
		   const Multi_Line_Text & message)
	: Input_Value::Error(value),
	  message_(message)
    {
    }

    //-------------------------------------------------------------------------

    Custom::Custom(const std::string &	   name,
		   const Multi_Line_Text & message)
	: Input_Value::Error(name),
	  message_(message)
    {
    }

    //-------------------------------------------------------------------------
};
