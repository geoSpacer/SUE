//-----------------------------------------------------------------------------
//  Inline function definitions:  Ignore_Case class
//-----------------------------------------------------------------------------

inline
bool Ignore_Case::eq(const std::string & x,
		     const std::string & y)
{
    return cmp(x, y) == 0;
}

//-----------------------------------------------------------------------------

inline
bool Ignore_Case::operator() (const std::string & x,
			      const std::string & y) const
{
    return cmp(x, y) == -1;
}
