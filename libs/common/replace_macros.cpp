#include "pragmas.h"

#include "replace_macros.h"

//-----------------------------------------------------------------------------

std::string replace_macros(const std::string &	     str,
			   const Macro_Definitions & macros,
			   Leave_or_Remove           undefined)
{
    std::string result;

    std::string::size_type i = 0;
    while (i < str.size()) {
	//  Look for the start of the next macro.
	std::string::size_type start = str.find_first_of("{^", i);
	if (start == std::string::npos) {
	    result += str.substr(i);
	    i = str.size();
	}
	else {
	    result += str.substr(i, start - i);
	    if (str[start] == '^' && start < str.size() - 1
				  && str[start+1] == '{') {
		//  Escaped "{".
		result += '{';
		i = start + 2;
	    }
	    else {
		//  Rename macro's name (upto the right brace)
		std::string::size_type end = str.find_first_of("}", start+1);
		if (end == std::string::npos) {
		    result += str.substr(start);
		    i = str.size();
		}
		else {
		    std::string macro = str.substr(start+1, end - start - 1);
		    Macro_Definitions::const_iterator p = macros.find(macro);
		    if (p != macros.end())
			result += p->second;
		    else if ((bool) undefined == (bool) Leave)
			result += str.substr(start, end - start + 1);
		    i = end + 1;
		}
	    }
	}
    }

    return result;
}
