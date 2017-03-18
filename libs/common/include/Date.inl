//-----------------------------------------------------------------------------
//  Inline function definitions:  Date class
//-----------------------------------------------------------------------------

inline
unsigned int Date::year() const
{
    return year_;
}

//-----------------------------------------------------------------------------

inline
Month Date::month() const
{
    return month_;
}

//-----------------------------------------------------------------------------

inline
unsigned int Date::day() const
{
    return day_;
}

//-----------------------------------------------------------------------------

inline
bool operator>(const Date & X,
	       const Date & Y)
{
    return Y < X;
}

//-----------------------------------------------------------------------------

inline
bool operator!=(const Date & X,
	        const Date & Y)
{
    return ! (X == Y);
}

//-----------------------------------------------------------------------------

inline
bool operator<=(const Date & X,
	        const Date & Y)
{
    return X < Y || X == Y;
}

//-----------------------------------------------------------------------------

inline
bool operator>=(const Date & X,
	        const Date & Y)
{
    return Y <= X;
}
