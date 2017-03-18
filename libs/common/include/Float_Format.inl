//-----------------------------------------------------------------------------
//  Inline function definitions:  Float_Format class
//-----------------------------------------------------------------------------

inline
Float_Format::Float_Format(bool show_pos_sign,
			   char pos_sign)
    : Numeric_Format(show_pos_sign, pos_sign)
{
}

//-----------------------------------------------------------------------------

inline
std::string operator<<(const Float_Format & fmt,
		       double		    d)
{
    return fmt(d);
}
