//-----------------------------------------------------------------------------
//  Inline function definitions:  Assertion_Error
//-----------------------------------------------------------------------------

inline
const std::string & Assertion_Error::condition() const
{
    return condition_;
}

//-----------------------------------------------------------------------------

inline
const std::string & Assertion_Error::file() const
{
    return file_;
}

//-----------------------------------------------------------------------------

inline
int Assertion_Error::line() const
{
    return line_;
}
