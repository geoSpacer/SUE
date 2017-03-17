//-----------------------------------------------------------------------------
//  Class implementation:  Assertion_Error
//-----------------------------------------------------------------------------

#include <iostream>

#include "Assertion_Error.h"

//-----------------------------------------------------------------------------

Assertion_Error::Assertion_Error(const std::string & condition,
				 const std::string & file,
				 int		     line)
    : condition_(condition),
      file_(file),
      line_(line)
{
}

//-----------------------------------------------------------------------------

void print(const Assertion_Error & error,
	   std::ostream &	   strm)
{
    strm << "A logic error internal to the program has been detected.\n"
	    "The condition:\n"
	    "\n"
	    "    " << error.condition() << "\n"
	    "\n"
	    "is not true";
    if (error.file() != "")
	strm << " at line " << error.line() << " in the file:\n"
		"\n"
		"    " << error.file() << "\n";
    else
    	strm << ".\n";
}
