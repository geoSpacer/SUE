//-----------------------------------------------------------------------------
//  Class implementation:  Input_Var::Str
//-----------------------------------------------------------------------------

#include "pragmas.h"

#include "Input_Var_Str.h"

//----------------------------------------------------------------------------

Input_Var::Str::Str(const std::string & name)
    : Input::Var<std::string>(),
      Input_Value::Str(location(), name)
{
}
