#ifndef ENUM_SEQUENCE_H
#define ENUM_SEQUENCE_H

//-----------------------------------------------------------------------------

//  Class:  Enum::Sequence<class Enum_Type>
//
//  This template class encapsulates some specific information about the
//  sequence of values for an enumerated type.

namespace Enum
{
    //-------------------------------------------------------------------------

    template<class Enum_Type>
    class Sequence
    {
	public:

	    static unsigned int count();
		//  The # of values in the sequence.

	    static unsigned int position(Enum_Type value);
		//  Returns the position of the value in the sequence.
		//  Positions are numbered from 0 upto count() - 1.
    };

    //-------------------------------------------------------------------------
};

//-----------------------------------------------------------------------------

#endif
