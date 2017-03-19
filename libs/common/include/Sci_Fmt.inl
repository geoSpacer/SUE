//-----------------------------------------------------------------------------
//  Inline function definitions:  Sci_Fmt class
//-----------------------------------------------------------------------------

inline
int Sci_Fmt::digits_after() const
{
    return digits_after_;
}

//-----------------------------------------------------------------------------

inline
const Exp_Fmt & Sci_Fmt::exponent() const
{
    return exp_fmt_;
}
