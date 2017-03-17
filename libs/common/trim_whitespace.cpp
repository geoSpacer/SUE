#include <string>
#include <cctype>

#include "trim_whitespace.h"

//-----------------------------------------------------------------------------

std::string trim_whitespace(const std::string & str,
			    Trim_Flags          flags)
{
    std::string::size_type start = 0;
    if (flags & Leading) {
	while (start < str.size() && isspace(str[start]))
	    start++;
    }

    if (start == str.size())
	return "";

    std::string::size_type end = str.size() - 1;
    if (flags & Trailing) {
	while (end >= start && isspace(str[end]))
	    end--;
    }

    return str.substr(start, end - start + 1);
}
