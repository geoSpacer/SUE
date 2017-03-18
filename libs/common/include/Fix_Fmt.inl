//-----------------------------------------------------------------------------
//  Inline function definitions:  Fix_Fmt class
//-----------------------------------------------------------------------------

inline
int Fix_Fmt::digits_before() const
{
    return digits_before_;
}

//-----------------------------------------------------------------------------

inline
bool Fix_Fmt::leading_zeroes() const
{
    return leading_0s_;
}

//-----------------------------------------------------------------------------

inline
int Fix_Fmt::digits_after() const
{
    return digits_after_;
}
