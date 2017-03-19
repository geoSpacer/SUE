//-----------------------------------------------------------------------------
//  Class implementation:  Float_Column
//-----------------------------------------------------------------------------

#include "pragmas.h"

#include "Float_Column.h"

//-----------------------------------------------------------------------------

Float_Column::Float_Column(int			   spacing,
			   const Multi_Line_Text & title,
			   const Fix_Fmt &	   format)
   : Output_Column(spacing, title, Right_Aligned, format.width())
{
    format_ = new Fix_Fmt(format);
}

//-----------------------------------------------------------------------------

Float_Column::Float_Column(int			   spacing,
			   const Multi_Line_Text & title,
			   const Sci_Fmt &	   format)
   : Output_Column(spacing, title, Right_Aligned, format.width())
{
    format_ = new Sci_Fmt(format);
}

//-----------------------------------------------------------------------------

Float_Column::Float_Column(int			   spacing,
			   const Multi_Line_Text & title,
			   const Gen_Fmt &	   format)
   : Output_Column(spacing, title, Right_Aligned, format.width())
{
    format_ = new Gen_Fmt(format);
}

//-----------------------------------------------------------------------------

std::string Float_Column::operator()(double value) const
{
    std::string str = (*format_)(value);
    if (str.size() >= (unsigned int) width())
	return spacing_str() + str;
    else
	return spacing_str() + std::string(width() - str.size(), ' ') + str;
}

//-----------------------------------------------------------------------------

Float_Column::~Float_Column()
{
    delete format_;
}
