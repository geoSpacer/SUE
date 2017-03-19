#ifndef COMMON_LIB__INT_COLUMN_H
#define COMMON_LIB__INT_COLUMN_H

//-----------------------------------------------------------------------------

#include "Output_Column.h"
#include "Int_Fmt.h"

//-----------------------------------------------------------------------------

//  Class:  Int_Column
//
//  This class represents an output column with integer data.

class Int_Column
    : public Output_Column
{
    public:
	//------------
	//  Operations

	Int_Column(int			   spacing,
		   const Multi_Line_Text & title,
		   const Int_Fmt &	   format);
	    //	Construct a column with the given spacing, title, and format.
	    //	Data values are right-justified.  If the title is wider than
	    //	the format, values are padded on left with spaces.

	std::string operator()(int value) const;
	std::string operator()(unsigned int value) const;
	    //	Format the given integer for the column.

    //-------------------------------------------------------------------------

    private:
	Int_Fmt format_;
};

//-----------------------------------------------------------------------------

//  Operator:  <<
//
//  This operator is provided as a shorthand notation for using the operator()
//  of the Int_Column class, e.g.,
//
//	Int_Column column(...);
//	std::cout << ( column << 123 );

std::string operator<<(const Int_Column & column,
		       int		  value);

std::string operator<<(const Int_Column & column,
		       unsigned int	  value);

//-----------------------------------------------------------------------------

#include "Int_Column.inl"

//-----------------------------------------------------------------------------

#endif
