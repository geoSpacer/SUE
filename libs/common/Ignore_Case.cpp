//-----------------------------------------------------------------------------
//  Class implementation:  Ignore_Case
//-----------------------------------------------------------------------------

#include <cctype>

#include "Ignore_Case.h"

//-----------------------------------------------------------------------------

//  (Based on the function "cmp_nocase" on page 591 of "The C++ Programming
//   Language", 3rd edition, by Bjarne Stroustrup).

int Ignore_Case::cmp(const std::string & x,
		     const std::string & y)
{
    std::string::const_iterator p = x.begin();
    std::string::const_iterator q = y.begin();

    while (p != x.end() && q != y.end()) {
	if (toupper(*p) != toupper(*q))
	    return (toupper(*p) < toupper(*q)) ? -1 : 1;
	++p;
	++q;
    }
    return (x.size() == y.size()) ? 0
				  : (x.size() < y.size()) ? -1 : 1;
}
