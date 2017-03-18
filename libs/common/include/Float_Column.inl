//-----------------------------------------------------------------------------
//  Inline function definitions:  Operator<<
//-----------------------------------------------------------------------------

inline
std::string operator<<(const Float_Column & column,
		       double		    value)
{
    return column(value);
}
