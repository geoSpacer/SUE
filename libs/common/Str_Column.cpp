//-----------------------------------------------------------------------------
//  Class implementation:  Str_Column
//-----------------------------------------------------------------------------

#include "pragmas.h"

#include "Str_Column.h"
#include "Assert_That.h"

//-----------------------------------------------------------------------------

Str_Column::Str_Column(int		       spacing,
		       const Multi_Line_Text & title,
		       int		       data_width)
    : Output_Column(spacing, title, Left_Aligned, data_width),
      data_width_(data_width)
{
    ASSERT_THAT(data_width > 0)
}

//-----------------------------------------------------------------------------

Str_Column::Str_Column(int		       spacing,
		       const Multi_Line_Text & title)
    : Output_Column(spacing, title, Left_Aligned, 0),
      data_width_(-1)
{
}

//-----------------------------------------------------------------------------

std::string Str_Column::operator()(const std::string & str) const
{
    if (data_width_ < 0 || str.size() >= (unsigned int) width())
	return spacing_str() + str;

    return spacing_str() + str + std::string(width() - str.size(), ' ');
}
