#ifndef COMMON_LIB__ERROR_H
#define COMMON_LIB__ERROR_H

//-----------------------------------------------------------------------------

#include "Multi_Line_Text.h"

//-----------------------------------------------------------------------------

//  Class:  Error
//
//  This class represents a program error.

class Error
{
    public:
	//------------
	//  Operations

        Error(const Multi_Line_Text & message);
	    //  Construct with the given message that describes the error.

	//------------
	//  Attributes

	const Multi_Line_Text & message() const;
	    //	The message describing the error.

    //-------------------------------------------------------------------------

    private:
	Multi_Line_Text message_;
};

//-----------------------------------------------------------------------------

#include "Error.inl"

//-----------------------------------------------------------------------------

#endif
