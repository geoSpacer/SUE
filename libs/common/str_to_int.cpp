#include <sstream>

#include "str_to_int.h"

//-----------------------------------------------------------------------------

bool str_to_int(const std::string & str,
		int &		    value)
{
    if (str.size() == 0)
	return false;
    if (str[0] != '+' && str[0] != '-' && ! isdigit(str[0]))
	return false;

    std::istringstream strm(str);
    int temp;
    if (strm >> temp) {
	if (strm.get() == EOF) {
	    value = temp;
	    return true;
	}
	else
	    return false;
    }
    else
	return false;
}
