//-----------------------------------------------------------------------------
//  Inline function definitions:  Time_Of_Day class
//-----------------------------------------------------------------------------

inline
unsigned int Time_Of_Day::hours() const
{
    return hours_;
}

//-----------------------------------------------------------------------------

inline
unsigned int Time_Of_Day::mins() const
{
    return mins_;
}

//-----------------------------------------------------------------------------

inline
float Time_Of_Day::secs() const
{
    return secs_;
}

//-----------------------------------------------------------------------------

inline
bool operator>(const Time_Of_Day & X,
	       const Time_Of_Day & Y)
{
    return Y < X;
}

//-----------------------------------------------------------------------------

inline
bool operator!=(const Time_Of_Day & X,
	        const Time_Of_Day & Y)
{
    return ! (X == Y);
}

//-----------------------------------------------------------------------------

inline
bool operator<=(const Time_Of_Day & X,
	        const Time_Of_Day & Y)
{
    return X < Y || X == Y;
}

//-----------------------------------------------------------------------------

inline
bool operator>=(const Time_Of_Day & X,
	        const Time_Of_Day & Y)
{
    return Y <= X;
}
