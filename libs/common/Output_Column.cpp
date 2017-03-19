//-----------------------------------------------------------------------------
//  Class implementation:  Output_Column
//-----------------------------------------------------------------------------

#include "pragmas.h"

#include <string>

#include "Output_Column.h"

//-----------------------------------------------------------------------------

Output_Column::Output_Column(int		     spacing,
			     const Multi_Line_Text & title,
			     Horizontal_Alignment    alignment,
			     int		     data_width)
    : spacing_(spacing),
      spacing_str_(spacing, ' '),
      width_(data_width)
{
    int title_width = 0;
    int i;
    for (i = 0; i < title.line_count(); i++)
	if (title[i].size() > (unsigned int) title_width)
	    title_width = title[i].size();

    if (title_width > width_)
	width_ = title_width;

    int indent;	//  # of spaces to indent the title to align it.
    switch (alignment) {
	case Left_Aligned:
	    indent = 0;
	    break;

	case Centered:
	    indent = (width_ - title_width) / 2;
	    break;

	default:    //	Right_Aligned
	    indent = width_ - title_width;
	    break;
    }

    for (i = 0; i < title.line_count(); i++)
	title_ += std::string(indent, ' ') + title[i];
}
