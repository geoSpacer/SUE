#ifndef ENUM_CIRCULATOR_H
#define ENUM_CIRCULATOR_H

//----------------------------------------------------------------------------

#include "Forward_or_Reverse.h"
#include "Enum_Circulator_Base.h"
#include "with_each.h"

//----------------------------------------------------------------------------

//  Class:  Enum::Circulator<class Enum_Type>
//
//  This template class represents a circulator for an enumerated type.  A
//  circulator is a special type of iterator for those enumerated type whose
//  values represent a sequence that is naturally circular, i.e., that repeats
//  itself.  For example, consider this enumerated type that represents the
//  days of the week:
//
//	enum Day { Sun, Mon, Tue, Wed, Thu, Fri, Sat};
//
//  The first value (Sunday) is considered to follow the last value (Saturday)
//  so the operator++() for this type could be defined as:
//
//	Day & operator++(Day & day)
//	{
//	    if (day == Sat)
//		day = Sun;
//	    else
//		day = Day(day + 1);
//	    return day;
//	}
//
//  Unfortunately, we can't write a simple "for" loop to go each day of the
//  week:
//
//	Day d;
//	for (d = Sun; d <= Sat; ++d)	//  never exits!
//	{
//	    //	body of loop
//	}
//
//  The example loop above never exits because after the pass through the loop
//  with d = Sat, d is then advanced by the operator++() to Sun, which is still
//  less or equal to Sat.  And so the loop endlessly goes through the days in
//  sequence, and then starts all over after Saturday.
//
//  The problem is that the "for" loop requires a sentinel value (i.e., a value
//  to mark the end of the sequence).  Now for a subset of a type's values,
//  there's no problem, for example, suppose we just wanted to go through the
//  weekdays:
//
//	Day weekDay;
//	for (weekDay = Mon; weekDay <= Fri; ++weekDay)
//	    //	...
//
//  The loop above works because there's a value (i.e., Sat) that's outside the
//  range of values we're interested in.  But we can't loop through the whole
//  sequence so easily.
//
//  Circulators were designed to address this issue.  A circulator is a special
//  type of iterator for an enumerated type.  Using the Day example above, all
//  the days in the week could be looped through with a circulator as follows:
//
//	Enum::Circulator<Day> day;
//	for (day.from(Sun, To, Sat); with_each(day); )
//	    if (Mon <= day && day <= Fri)
//		//  go to work
//	    else
//		//  it's the weekend!
//
//  The first and third arguments to the member function "from()" specify the
//  start and end of the range of values within the enumerated type's sequence.
//  The second argument specifies the direction the circulator steps through
//  the values in the type's sequence -- either forward or backward.  This
//  argument is of the boolean type called "Forward_or_Reverse", and there
//  are constants that are aliases for this boolean type's constants to make
//  the code more readable.

const Forward_or_Reverse Forward_To  = Forward;
const Forward_or_Reverse Reverse_To  = Reverse;

const Forward_or_Reverse To          = Forward;
const Forward_or_Reverse Back_To     = Reverse;
const Forward_or_Reverse Backward_To = Reverse;

//  Of course, if a different pair of aliases would be appropriate, they could
//  be defined locally as needed.
//
//  In order to use this template class for an enumerated type {Enum_Type},
//  there must be 4 functions defined for the type:
//
//	unsigned int Enum::Sequence<Enum_Type>::count();
//	    //	Returns the total number of distinct values in the sequence
//	    //	for the enumerated type.
//
//	unsigned int Enum::Sequence<Enum_Type>::position(Enum_Type value);
//	    //	Returns the position of the given value in the sequence of
//	    //	values for the type.  Positions are numbered from 0 on, so]
//	    //	the first value in the sequence has position 0, the second
//	    //	value has position 1, etc.
//
//	Enum_Type & operator++(Enum_Type & var);
//	    //	Advance the enumerated-type variable to the next value in the
//	    //	type's sequence.  If the variable has the last value in the
//	    //	sequence, it's assigned the first value.
//
//	Enum_Type & operator--(Enum_Type & var);
//	    //	Move the enumerated-type variable to the previous value in the
//	    //	type's sequence.  If the variable has the first value in the
//	    //	sequence, it's assigned the last value.
//
//  The first two functions are already declared by using the Enum::Sequence
//  template class, so the programmer need only include that header file in
//  the source file where the code for those two functions resides.  These two
//  functions are also required for the template class Enum::Vector.
//
//  Declarations for the last two functions should be specified in the header
//  file where the enumerated type is defined:
//
//
//	//  header file for enumerated type Day
//
//	enum Day { ... };
//
//	Day & operator++(Day & day);
//
//	Day & operator--(Day & day);
//
//
//  Notes:  1)	The constants for an enumerated type need not represent
//		contiguous integer values.  The only requirement is that the
//		two prefix operator functions above ("++var" and "--var")
//		properly to step through the values in order.
//
//	    2)	An enumerated type may have more than one constant
//		representing a particular value in its sequence.  For
//		example,
//
//		    enum Day
//		    {
//			Sunday	  = 1,	Sun = Sunday,
//			Monday	  = 2,	Mon = Monday,
//			Tuesday	  = 3,	Tue = Tuesday,
//			Wednesday = 4,	Wed = Wednesday,
//			Thursday  = 5,	Thu = Thursday,
//			Friday	  = 6,	Fri = Friday,
//			Saturday  = 7,  Sat = Saturday
//		    };
//	    
//		For this example, the first two required functions could be
//		defined as such:
//
//		    unsigned int Enum::Sequence<Day>::count()
//		    {
//			return 7;
//		    }
//
//		    unsigned int Enum::Sequence<Day>::position(Day day)
//		    {
//			ASSERT_THAT(1 <= day && day <= 7)
//			return day - 1;
//		    }

namespace Enum
{

    template<class Enum_Type>
    class Circulator
	: public Circulator_Base
    {
	public :
	    Circulator();
		//  Construct a circulator.

	    void from(Enum_Type		 start,
		      Forward_or_Reverse direction,
		      Enum_Type		 end);
		//  Specify the range (i.e, from {start} value to {end}
		//  value in the given direction) for the circulator.  The
		//  circulator's value is initialized to {start}.

	    operator Enum_Type() const;
		//  Return the circulator's current value.

	//---------------------------------------------------------------------

	protected:
	    void step_forward();
		//  Advance the circulator's value forward to the next value
		//  in the sequence.

	    void step_backward();
		//  Advance the circulator's value backward to the previous
		//  value in the sequence.


	//---------------------------------------------------------------------

	private:
	    Enum_Type value_;	//  Circulator's current value;
    };

};

//-----------------------------------------------------------------------------

#include "Enum_Circulator.inl"

//-----------------------------------------------------------------------------

#endif
