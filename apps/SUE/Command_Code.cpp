#include "Command_Code.h"

//-----------------------------------------------------------------------------

namespace
{
    const char * names[] = {
#include "command_codes.c"
    };

    const int count = sizeof(names) / sizeof(const char *);
};

//-----------------------------------------------------------------------------

const char * name(Command_Code code)
{
    if (code >= 0 && code < count)
	return names[code];
    else
	return "(unknown)";
}
