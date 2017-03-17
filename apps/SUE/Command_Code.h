#ifndef COMMAND_CODE_H
#define COMMAND_CODE_H

//-----------------------------------------------------------------------------

enum Command_Code {
#include "command_codes.h"
};

const char * name(Command_Code code);
    //	Returns the name of the command code.

//-----------------------------------------------------------------------------

#endif
