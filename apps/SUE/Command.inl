//-----------------------------------------------------------------------------
//  Inline function definitions:  Command class
//-----------------------------------------------------------------------------

inline
Command_Code Command::code() const
{
    return code_;
}

//-----------------------------------------------------------------------------

inline
int Command::int_value() const
{
    return value_.i;
}

//-----------------------------------------------------------------------------

inline
double Command::double_value() const
{
    return value_.d;
}

//-----------------------------------------------------------------------------

inline
const std::string & Command::str_value() const
{
    return value_.s;
}
