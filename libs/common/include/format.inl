//-----------------------------------------------------------------------------
//  Inline function definitions:  format function
//-----------------------------------------------------------------------------

inline
std::string format(long		   i,
		   const Int_Fmt & fmt)
{
    return fmt(i);
}

//-----------------------------------------------------------------------------

inline
std::string format(int		   i,
		   const Int_Fmt & fmt)
{
    return fmt(long(i));
}

//-----------------------------------------------------------------------------

inline
std::string format(unsigned long   i,
		   const Int_Fmt & fmt)
{
    return fmt(i);
}

//-----------------------------------------------------------------------------

inline
std::string format(unsigned int	   i,
		   const Int_Fmt & fmt)
{
    return fmt(unsigned long(i));
}

//-----------------------------------------------------------------------------

inline
std::string format(double		d,
		   const Float_Format & fmt)
{
    return fmt(d);
}

//-----------------------------------------------------------------------------

inline
std::string format(double	   d,
		   const Fix_Fmt & fix_fmt,
		   const Sci_Fmt & sci_fmt)
{
    return Gen_Fmt(fix_fmt, sci_fmt)(d);
}
