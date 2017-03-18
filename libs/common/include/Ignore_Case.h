#ifndef COMMON_LIB__IGNORE_CASE_H
#define COMMON_LIB__IGNORE_CASE_H

//-----------------------------------------------------------------------------

#include <string>

//-----------------------------------------------------------------------------

//  Class:  Ignore_Case
//
//  This class represents case-insensitive string comparison.

class Ignore_Case
{
    public:
	//------------
	//  Operations

	static int cmp(const std::string & x,
		       const std::string & y);
	    //	Return -1 if x is lexicographically < y (ignoring case),
	    //		0 if x is equal to y (ignoring case), or
	    //	        1 if x is lexicographically > y (ignoring case),

	static bool eq(const std::string & x,
		       const std::string & y);
	    //	Return true if x is equal to y (ignoring case).

	bool operator() (const std::string & x,
			 const std::string & y) const;
	    //  Return true if x is lexicographically < y (ignoring case).
	    //	This function is used when this class is the comparison class
	    //  class in container classes (e.g., maps).
};

//-----------------------------------------------------------------------------

#include "Ignore_Case.inl"

//-----------------------------------------------------------------------------

#endif
