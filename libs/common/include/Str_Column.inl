//-----------------------------------------------------------------------------
//  Inline function definitions:  Operator<<
//-----------------------------------------------------------------------------

inline
std::string operator<<(const Str_Column &  column,
		       const std::string & str)
{
    return column(str);
}
