//-----------------------------------------------------------------------------
//  Class implementation:  Int_Column
//-----------------------------------------------------------------------------

#include "pragmas.h"

#include "Int_Column.h"

//-----------------------------------------------------------------------------

Int_Column::Int_Column(int		       spacing,
		       const Multi_Line_Text & title,
		       const Int_Fmt &	       format)
   : Output_Column(spacing, title, Right_Aligned, format.width()),
     format_(format)
{
}

//-----------------------------------------------------------------------------

std::string Int_Column::operator()(int value) const
{
    std::string str = format_ << value;
    if (str.size() >= (unsigned int) width())
	return spacing_str() + str;
    else
	return spacing_str() + std::string(width() - str.size(), ' ') + str;
}

//-----------------------------------------------------------------------------

std::string Int_Column::operator()(unsigned int value) const
{
    std::string str = format_ << value;
    if (str.size() >= (unsigned int) width())
	return spacing_str() + str;
    else
	return spacing_str() + std::string(width() - str.size(), ' ') + str;
}
