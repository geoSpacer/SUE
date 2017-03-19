#ifndef COMMON_LIB__OUTPUT_COLUMN_H
#define COMMON_LIB__OUTPUT_COLUMN_H

//-----------------------------------------------------------------------------

#include <vector>
#include <string>

#include "Multi_Line_Text.h"
#include "Horizontal_Alignment.h"

//-----------------------------------------------------------------------------

//  Class:  Output_Column
//
//  This abstract class represents a column of output data.

class Output_Column
{
    public:
	//------------
	//  Operations

	Output_Column(int		      spacing,
		      const Multi_Line_Text & title,
		      Horizontal_Alignment    alignment,
		      int		      data_width);
	    //	Construct a column with the given spacing, title, and data
	    //	width.  The spacing is the # of spaces to the left of the
	    //	column.  The alignment specifies how the title should be
	    //	aligned relative to the data.

	//------------
	//  Attributes

	int spacing() const;
	    //	The column's spacing.

	const std::string & spacing_str() const;
	    //	The column's spacing as a string.

	const Multi_Line_Text & title() const;
	    //	The column's title.

	int width() const;
	    //	The width of the column (the maximum of the title's longest
	    //	line or the data width).

    //-------------------------------------------------------------------------

    private:
	int		spacing_;
	std::string	spacing_str_;
	Multi_Line_Text title_;
	int		width_;
};

//-----------------------------------------------------------------------------

#include "Output_Column.inl"

//-----------------------------------------------------------------------------

#endif
