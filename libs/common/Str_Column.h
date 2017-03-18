#ifndef COMMON_LIB__STR_COLUMN_H
#define COMMON_LIB__STR_COLUMN_H

//-----------------------------------------------------------------------------

#include "Output_Column.h"

//-----------------------------------------------------------------------------

//  Class:  Str_Column
//
//  This class represents an output column with string data.

class Str_Column
    : public Output_Column
{
    public:
	//------------
	//  Operations

	Str_Column(int			   spacing,
		   const Multi_Line_Text & title,
		   int			   data_width);
	    //	Construct a column with the given spacing, title, and width
	    //	of data.  Data values are padded on the right with spaces
	    //	to the given width.

	Str_Column(int			   spacing,
		   const Multi_Line_Text & title);
	    //	Construct a column with the given spacing and title.  Data
	    //	values are not padded on the right because it's assumed that
	    //	this column is the last column.

	std::string operator()(const std::string & str) const;
	    //	Format the given string for the column.

    //-------------------------------------------------------------------------

    private:
	int data_width_;
};

//-----------------------------------------------------------------------------

//  Operator:  <<
//
//  This operator is provided as a shorthand notation for using the operator()
//  of the Str_Column class, e.g.,
//
//	Str_Column column(...);
//	std::cout << ( column << "hello mom!" );

std::string operator<<(const Str_Column &  column,
		       const std::string & str);

//-----------------------------------------------------------------------------

#include "Str_Column.inl"

//-----------------------------------------------------------------------------

#endif
