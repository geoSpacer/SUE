#ifndef COMMON_LIB__RANGE_H
#define COMMON_LIB__RANGE_H

//-----------------------------------------------------------------------------

#include <string>

//-----------------------------------------------------------------------------

//  Class:  Range<class Num_Type>
//
//  Template parameters:
//	Num_Type = a numeric type (e.g., int, float)
//
//  This class represents a range for a numeric type.  A range may have a
//  lower bound and/or an upper bound.  A range with neither a lower nor an
//  upper bound represents the whole range of possible value for the numeric
//  type.
//
//  For either a lower bound or an upper bound, there are possible situations:
//
//	1)  The bound itself is included in the range (e.g., all integers
//	    less than or equal to 100), or
//	2)  The bound is not part of the range (e.g., all floats greater than
//	    0.0).
//
//
//  The "<" and "<=" operators have been defined for this class to allow a
//  range's bounds to be specified in a manner similiar to this common
//  notation:
//
//	a <= x < b
//
//  which represents the range from "a" up to but not including "b".
//
//  Examples:
//
//	Range<int>		    //  all possible integers
//
//	0 < Range<int>		    //  all integers > 0
//
//	1 <= Range<int>		    //  all integers = or > 1 (which is
//				    //  the same as the previous example)
//
//	100 <= Range<int> <= 999    //  all unsigned 3-digit integers
//
//	Range<float> < 0.0	    //  all negative floats
//
//	0.0 <= Range<float> < 1.0   //  all floats between 0 and 1
//				    //  excluding 1 itself

template<class Num_Type>
class Range
{
    public:
	//------------
	//  Operations

	Range();
	    //	Construct an Range object with no bounds.

	void set_lower_bound(Num_Type bound,
			     bool     include_bound);
	    //	Set the range's lower bound.

	void set_upper_bound(Num_Type bound,
			     bool     include_bound);
	    //	Set the range's upper bound.

	bool contains(Num_Type value) const;
	    //	Return "true" if the range contains the given value.

	bool has_lower_bound(Num_Type & bound,
			     bool     & include_bound) const;
	    //	Return "true" if the range has a lower bound endpoint.  If so,
	    //	the bound's value is assigned to {bound}, and {include_bound}
	    //	is assigned "true" if the bound is included in the range.

	bool has_upper_bound(Num_Type & bound,
			     bool     & include_bound) const;
	    //	Return "true" if the range has an upper bound endpoint.  If so,
	    //	the bound's value is assigned to {bound}, and {include_bound}
	    //	is assigned "true" if the bound is included in the range.

	std::string str(const std::string & variable) const;
	    //	Return a string representation of the range in one of these
	    //	formats:
	    //
	    //	    lower_bound <= variable <= upper_bound
	    //
	    //	    variable => lower_bound
	    //
	    //	    variable <= upper_bound
	    //
	    //	If a bound is not included, then its adjacent operator is "<"
	    //	or ">".  If both bounds are not set, then "" is returned.

    //-------------------------------------------------------------------------

    private:
	struct Bound
	{
	    bool     set;	//  has the bound been set?
	    Num_Type value;	//  the bound's value
	    bool     included;	//  is the bound included in the range?
	};

	Bound lower_bound_;
	Bound upper_bound_;
};

//-----------------------------------------------------------------------------

template<class Num_Type>
Range<Num_Type> & operator<(Num_Type	      lower_bound,
			    Range<Num_Type> & range);
    //	Set a range's lower bound; the bound is not included in the range.

template<class Num_Type>
Range<Num_Type> & operator<=(Num_Type	       lower_bound,
			     Range<Num_Type> & range);
    //	Set a range's lower bound; the bound is included in the range.

template<class Num_Type>
Range<Num_Type> & operator<(Range<Num_Type> & range,
			    Num_Type	      upper_bound);
    //	Set a range's upper bound; the bound is not included in the range.

template<class Num_Type>
Range<Num_Type> & operator<=(Range<Num_Type> & range,
			     Num_Type	       upper_bound);
    //	Set a range's upper bound; the bound is included in the range.

//-----------------------------------------------------------------------------

#include "Range.inl"

//-----------------------------------------------------------------------------

#endif
