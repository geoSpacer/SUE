//-----------------------------------------------------------------------------
//  Class implementation:  Input_Value::Str
//-----------------------------------------------------------------------------

#include "pragmas.h"

#include "Input_Value_Str.h"
#include "Input_Value_Error.h"

//-----------------------------------------------------------------------------

Input_Value::Str::Str(std::string &	  location,
		      const std::string & name)
    : Input::Value(name),
      Input_Value::Location<std::string>(location)
{
}

//-----------------------------------------------------------------------------

void Input_Value::Str::read(std::istringstream & strm)
    throw(Input_Value::Error)
{
    if (! (strm >> location_))
	throw Input_Value_Error::Missing(*this);
}
