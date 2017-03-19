#include "read_chars.h"

//----------------------------------------------------------------------------

std::string read_chars(std::istringstream & strm,
		       unsigned int	    num_chars)
{
    std::string str;
    if (num_chars > 0) {
	try {
	    char * buffer = new char[num_chars + 1]; //	"+ 1" is for the '\0'
	    strm.get(buffer, num_chars + 1);
	    str = buffer;
	    delete[] buffer;
	}
	catch (std::bad_alloc) {
	    //	Do nothing; just return an empty string.
	}
    }
    return str;
}
