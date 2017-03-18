#ifndef COMMON_LIB__FLOAT_COLUMN_H
#define COMMON_LIB__FLOAT_COLUMN_H

//-----------------------------------------------------------------------------

#include "Output_Column.h"

#include "Fix_Fmt.h"
#include "Sci_Fmt.h"
#include "Gen_Fmt.h"

//-----------------------------------------------------------------------------

//  Class:  Float_Column
//
//  This class represents an output column with floating-point data.

class Float_Column
    : public Output_Column
{
    public:
	//------------
	//  Operations

	Float_Column(int		     spacing,
		     const Multi_Line_Text & title,
		     const Fix_Fmt &	     format);

	Float_Column(int		     spacing,
		     const Multi_Line_Text & title,
		     const Sci_Fmt &	     format);

	Float_Column(int		     spacing,
		     const Multi_Line_Text & title,
		     const Gen_Fmt &	     format);
	    //	Construct a column with the given spacing, title, and format.
	    //	Data values are right-justified.  If the title is wider than
	    //	the format, values are padded on left with spaces.

	std::string operator()(double value) const;
	    //	Format the given floating-point value for the column.

	~Float_Column();
	    //	Destroy the column.

    //-------------------------------------------------------------------------

    private:
	Float_Format * format_;
};

//-----------------------------------------------------------------------------

//  Operator:  <<
//
//  This operator is provided as a shorthand notation for using the operator()
//  of the Float_Column class, e.g.,
//
//	Float_Column column(...);
//	std::cout << ( column << 123.45 );

std::string operator<<(const Float_Column & column,
		       double		    value);

//-----------------------------------------------------------------------------

#include "Float_Column.inl"

//-----------------------------------------------------------------------------

#endif
