#ifndef TRIM_WHITESPACE_H
#define TRIM_WHITESPACE_H

//-----------------------------------------------------------------------------

#include <string>

//-----------------------------------------------------------------------------

enum Trim_Flags {
    Leading =  0x01,
    Trailing = 0x02
};

std::string trim_whitespace(const std::string & str,
			    Trim_Flags          flags = Trim_Flags(Leading |
								   Trailing));
    //	Trim any leading and/or trailing whitespace from a string.

//-----------------------------------------------------------------------------

#endif
