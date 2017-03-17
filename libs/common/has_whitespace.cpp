#include <cctype>

#include "has_whitespace.h"

//-----------------------------------------------------------------------------

bool has_whitespace(const std::string & str)
{
    for (unsigned int i = 0; i < str.size(); i++)
	if (isspace(str[i]))
	    return true;

    return false;
}
