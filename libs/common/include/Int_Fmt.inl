//-----------------------------------------------------------------------------
//  Inline function definitions:  Int_Fmt class
//-----------------------------------------------------------------------------

inline
int Int_Fmt::num_digits() const
{
    return num_digits_;
}

//-----------------------------------------------------------------------------

inline
bool Int_Fmt::leading_zeroes() const
{
    return leading_0s_;
}

//-----------------------------------------------------------------------------

inline
int Int_Fmt::width() const
{
    return show_pos_sign() ? num_digits() + 1 : num_digits();
}

//-----------------------------------------------------------------------------

inline
std::string Int_Fmt::operator()(int i) const
{
    return operator()(long(i));
}

//-----------------------------------------------------------------------------

inline
std::string Int_Fmt::operator()(unsigned int i) const
{
    return operator()(unsigned long(i));
}

//-----------------------------------------------------------------------------
//  Inline operator definitions:  operator<<
//-----------------------------------------------------------------------------

inline
std::string operator<<(const Int_Fmt & fmt,
		       long	       i)
{
    return fmt(i);
}

//-----------------------------------------------------------------------------

inline
std::string operator<<(const Int_Fmt & fmt,
		       int	       i)
{
    return fmt(long(i));
}

//-----------------------------------------------------------------------------

inline
std::string operator<<(const Int_Fmt & fmt,
		       unsigned long   i)
{
    return fmt(i);
}

//-----------------------------------------------------------------------------

inline
std::string operator<<(const Int_Fmt & fmt,
		       unsigned int    i)
{
    return fmt(unsigned long(i));
}
