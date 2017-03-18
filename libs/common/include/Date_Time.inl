//-----------------------------------------------------------------------------
//  Inline function definitions:  Date_Time class
//-----------------------------------------------------------------------------

inline
const Date & Date_Time::date() const
{
    return date_;
}

//-----------------------------------------------------------------------------

inline
unsigned int Date_Time::year() const
{
    return date_.year();
}

//-----------------------------------------------------------------------------

inline
Month Date_Time::month() const
{
    return date_.month();
}

//-----------------------------------------------------------------------------

inline
unsigned int Date_Time::day() const
{
    return date_.day();
}

//-----------------------------------------------------------------------------

inline
const Time_Of_Day & Date_Time::time() const
{
    return time_;
}

//-----------------------------------------------------------------------------

inline
unsigned int Date_Time::hours() const
{
    return time_.hours();
}

//-----------------------------------------------------------------------------

inline
unsigned int Date_Time::mins() const
{
    return time_.mins();
}

//-----------------------------------------------------------------------------

inline
float Date_Time::secs() const
{
    return time_.secs();
}

//-----------------------------------------------------------------------------

inline
bool operator>(const Date_Time & X,
	       const Date_Time & Y)
{
    return Y < X;
}

//-----------------------------------------------------------------------------

inline
bool operator!=(const Date_Time & X,
	        const Date_Time & Y)
{
    return ! (X == Y);
}

//-----------------------------------------------------------------------------

inline
bool operator<=(const Date_Time & X,
	        const Date_Time & Y)
{
    return X < Y || X == Y;
}

//-----------------------------------------------------------------------------

inline
bool operator>=(const Date_Time & X,
	        const Date_Time & Y)
{
    return Y <= X;
}
