#ifndef COMMON_LIB__READ_CHARS_H
#define COMMON_LIB__READ_CHARS_H

//-----------------------------------------------------------------------------

#include <string>
#include <sstream>

//-----------------------------------------------------------------------------

std::string read_chars(std::istringstream & strm,
		       unsigned int	    num_chars);

    //  Reads characters from a string stream up to a specified number.

//-----------------------------------------------------------------------------

#endif

