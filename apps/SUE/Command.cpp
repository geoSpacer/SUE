
#include <string>
#include "Command.h"

//-----------------------------------------------------------------------------

Command::Command(Command_Code code)
    : code_(code)
{
}

//-----------------------------------------------------------------------------

Command::Command(Command_Code code,
		 int	      value)
    : code_(code)
{
    value_.i = value;
}

//-----------------------------------------------------------------------------

Command::Command(Command_Code code,
		 double	      value)
    : code_(code)
{
    value_.d = value;
}

//-----------------------------------------------------------------------------

Command::Command(Command_Code	     code,
		 const std::string & value)
    : code_(code)
{
    value_.s = value;
}

//-----------------------------------------------------------------------------
