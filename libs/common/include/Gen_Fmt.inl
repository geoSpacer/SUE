//-----------------------------------------------------------------------------
//  Inline function definitions:  Gen_Fmt class
//-----------------------------------------------------------------------------

inline
const Fix_Fmt & Gen_Fmt::fix_fmt() const
{
    return fix_fmt_;
}

//-----------------------------------------------------------------------------

inline
const Sci_Fmt & Gen_Fmt::sci_fmt() const
{
    return sci_fmt_;
}

//-----------------------------------------------------------------------------
//  Operator ||
//-----------------------------------------------------------------------------

inline
Gen_Fmt operator||(const Fix_Fmt & fix_fmt,
		   const Sci_Fmt & sci_fmt)
{
    return Gen_Fmt(fix_fmt, sci_fmt);
}
