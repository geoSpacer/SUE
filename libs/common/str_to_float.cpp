#include <sstream>
#include <limits>

#include "str_to_float.h"

//-----------------------------------------------------------------------------

bool str_to_float(const std::string & str,
		  float &	      value)
{
    if (str.size() == 0)
	return false;
    if (str[0] != '+' && str[0] != '-' && ! isdigit(str[0]) && str[0] != '.')
	return false;

    std::istringstream strm(str);
    float temp;
    if (strm >> temp) {
	if (strm.get() == EOF) {
	    if (std::numeric_limits<float>::has_infinity) {
		float infinity = std::numeric_limits<float>::infinity();
		if (temp < 0 && temp == -infinity)
		    return false;
		if (temp > 0 && temp == infinity)
		    return false;
	    }
	    value = temp;
	    return true;
	}
	else
	    return false;
    }
    else
	return false;
}
