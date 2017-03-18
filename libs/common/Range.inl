//-----------------------------------------------------------------------------
//  Inline function definitions:  Range<Num_Type> class
//				  and related operator functions
//-----------------------------------------------------------------------------

#include <sstream>

#include "Assert_That.h"

//-----------------------------------------------------------------------------

template<class Num_Type>
Range<Num_Type>::Range()
{
    lower_bound_.set = false;
    upper_bound_.set = false;
}

//-----------------------------------------------------------------------------

template<class Num_Type>
void Range<Num_Type>::set_lower_bound(Num_Type lower_bound,
				      bool     include_bound)
{
    ASSERT_THAT(lower_bound_.set == false)
    if (upper_bound_.set)
	ASSERT_THAT(lower_bound <= upper_bound_.value)

    lower_bound_.set	  = true;
    lower_bound_.value    = lower_bound;
    lower_bound_.included = include_bound;
}

//-----------------------------------------------------------------------------

template<class Num_Type>
void Range<Num_Type>::set_upper_bound(Num_Type upper_bound,
				      bool     include_bound)
{
    ASSERT_THAT(upper_bound_.set == false)
    if (lower_bound_.set)
	ASSERT_THAT(lower_bound_.value <= upper_bound)

    upper_bound_.set	  = true;
    upper_bound_.value    = upper_bound;
    upper_bound_.included = include_bound;
}

//-----------------------------------------------------------------------------

template<class Num_Type>
bool Range<Num_Type>::contains(Num_Type value) const
{
    bool above_lower;	//  is value above the lower bound?
    bool below_upper;	//  is value below the upper bound?

    if (lower_bound_.set)
	if (lower_bound_.included)
	    above_lower = (lower_bound_.value <= value);
	else
	    above_lower = (lower_bound_.value < value);
    else
	above_lower = true;

    if (upper_bound_.set)
	if (upper_bound_.included)
	    below_upper = (value <= upper_bound_.value);
	else
	    below_upper = (value < upper_bound_.value);
    else
	below_upper = true;

    return above_lower && below_upper;
}

//-----------------------------------------------------------------------------

template<class Num_Type>
bool Range<Num_Type>::has_lower_bound(Num_Type & bound,
				      bool     & include_bound) const
{
    if (lower_bound_.set)
    {
	bound = lower_bound_.value;
	include_bound = lower_bound_.included;
    }
    return lower_bound_.set;
}

//-----------------------------------------------------------------------------

template<class Num_Type>
bool Range<Num_Type>::has_upper_bound(Num_Type & bound,
				      bool     & include_bound) const
{
    if (upper_bound_.set)
    {
	bound = upper_bound_.value;
	include_bound = upper_bound_.included;
    }
    return upper_bound_.set;
}

//-----------------------------------------------------------------------------

template<class Num_Type>
std::string Range<Num_Type>::str(const std::string & variable) const
{
    std::ostringstream strm;
    if (lower_bound_.set && upper_bound_.set) {
	strm << lower_bound_.value << " "
	     << (lower_bound_.included ? "<=" : "<") << " " << variable << " "
	     << (upper_bound_.included ? "<=" : "<") << " "
	     << upper_bound_.value;
    }
    else if (lower_bound_.set) {
	strm << variable << " " << (lower_bound_.included ? "=>" : ">")
	     << " " << lower_bound_.value;
    }
    else if (upper_bound_.set) {
	strm << variable << " " << (upper_bound_.included ? "<=" : "<")
	     << " " << upper_bound_.value;
    }
    return strm.str();
}

//-----------------------------------------------------------------------------
//  Operator functions to help set a range's bounds.
//-----------------------------------------------------------------------------

template<class Num_Type>
inline
Range<Num_Type> & operator<(Num_Type	      lower_bound,
			    Range<Num_Type> & range)
{
    range.set_lower_bound(lower_bound, false);
    return range;
}

//-----------------------------------------------------------------------------

template<class Num_Type>
inline
Range<Num_Type> & operator<=(Num_Type	       lower_bound,
			     Range<Num_Type> & range)
{
    range.set_lower_bound(lower_bound, true);
    return range;
}

//-----------------------------------------------------------------------------

template<class Num_Type>
inline
Range<Num_Type> & operator<(Range<Num_Type> & range,
			    Num_Type	      upper_bound)
{
    range.set_upper_bound(upper_bound, false);
    return range;
}

//-----------------------------------------------------------------------------

template<class Num_Type>
inline
Range<Num_Type> & operator<=(Range<Num_Type> & range,
			     Num_Type	       upper_bound)
{
    range.set_upper_bound(upper_bound, true);
    return range;
}

//-----------------------------------------------------------------------------

//  The following 4 specializations of the "<" and "<=" operators for
//  "const double" and "Range<float>" are to address the situations when
//  floating point literals are used with Range<float>, e.g.,
//
//	0.0 <= Range<float>() < 1.0
//
//  Since the compiler treats the literals as of type "const double", an
//  ambiguity arise regarding the template parameters for these operators.

//-----------------------------------------------------------------------------

inline
Range<float> & operator<(const double   lower_bound,
			 Range<float> & range)
{
    return operator<(float(lower_bound), range);
}

//-----------------------------------------------------------------------------

inline
Range<float> & operator<=(const double	 lower_bound,
			  Range<float> & range)
{
    return operator<=(float(lower_bound), range);
}

//-----------------------------------------------------------------------------

inline
Range<float> & operator<(Range<float> & range,
			 const double   upper_bound)
{
    return operator<(range, float(upper_bound));
}

//-----------------------------------------------------------------------------

inline
Range<float> & operator<=(Range<float> & range,
			  const double   upper_bound)
{
    return operator<=(range, float(upper_bound));
}
