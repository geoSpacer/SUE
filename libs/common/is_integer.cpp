#include <cctype>

#include "is_integer.h"

//-----------------------------------------------------------------------------

bool is_integer(const std::string & str)
{
    const char * p = str.c_str();

    if (*p == '-' || *p == '+')
	p++;

    //	Look for first digit.
    if (! isdigit(*p))
	return false;

    while (isdigit(*p))
	p++;

    return *p == '\0';
}
