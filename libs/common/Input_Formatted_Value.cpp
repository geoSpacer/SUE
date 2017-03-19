//-----------------------------------------------------------------------------
//  Class implementation:  Input::Formatted_Value
//-----------------------------------------------------------------------------

#include "Input_Value.h"
#include "Input_Formatted_Value.h"

//-----------------------------------------------------------------------------

Input::Formatted_Value::Formatted_Value(const std::string & name,
					const std::string & description)
    : Input::Value(name),
      description_(description),
      str_("")
{
}
