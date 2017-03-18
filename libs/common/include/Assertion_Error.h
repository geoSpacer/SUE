#ifndef COMMON_LIB__ASSERTION_ERROR_H
#define COMMON_LIB__ASSERTION_ERROR_H

//-----------------------------------------------------------------------------

#include <string>
#include <iostream>

//-----------------------------------------------------------------------------

//  Class:  Assertion_Error
//
//  This class represents an error due to an assertion that failed.

class Assertion_Error
{
    public:
	//------------
	//  Operations

	Assertion_Error(const std::string & condition,
			const std::string & file,
			int		    line);
	    //	Construct a new assertion error that happened when the given
	    //	condition failed at the specified line in the named source
	    //	file.

	//------------
	//  Attributes

	const std::string & condition() const;
	    //	The condition that failed.

	const std::string & file() const;
	    //	The source file where the assertion failed.

	int line() const;
	    //	The line number in the source file where the assertion failed.

    //-------------------------------------------------------------------------

    private:
	std::string condition_;
	std::string file_;
	int	    line_;
};

//-----------------------------------------------------------------------------

#include "Assertion_Error.inl"

//-----------------------------------------------------------------------------

void print(const Assertion_Error & error,
	   std::ostream &	   strm);
    //	Print a message describing the assertion error to an output stream.

//-----------------------------------------------------------------------------

#endif
