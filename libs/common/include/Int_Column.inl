//-----------------------------------------------------------------------------
//  Inline function definitions:  Operator<<
//-----------------------------------------------------------------------------

inline
std::string operator<<(const Int_Column & column,
		       int		  value)
{
    return column(value);
}

//-----------------------------------------------------------------------------

inline
std::string operator<<(const Int_Column & column,
		       unsigned int	  value)
{
    return column(value);
}
