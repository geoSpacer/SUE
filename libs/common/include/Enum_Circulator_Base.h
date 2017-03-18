#ifndef ENUM_CIRCULATOR_BASE_H
#define ENUM_CIRCULATOR_BASE_H

//----------------------------------------------------------------------------

#include "Forward_or_Reverse.h"

//----------------------------------------------------------------------------

namespace Enum
{
    class Circulator_Base;
};

bool with_each(Enum::Circulator_Base & circulator);

//----------------------------------------------------------------------------

//  Class:  Enum::Circulator_Base
//
//  This class is the base class for circulators for enumerated types (i.e.,
//  the Enum::Circulator template class).  It provides uniform handling of
//  a circulator whether it's stepping forward or backward through the
//  sequence of values for an enumerated type.  It accomplishes this by
//  maintaining a counter that is initialized when the circulator's range
//  is specified, and then decremented as the circulator steps through the
//  values in the range.

namespace Enum
{

    class Circulator_Base
    {
	public :
	    //------------
	    //	Operations

	    Circulator_Base();
		//  Construct a base circulator.

	protected :
	    void set_count(unsigned int	     start_pos,
			  unsigned int	     end_pos,
			  Forward_or_Reverse direction,
			  unsigned int	     num_values);
		//  Initialize the counter to the number of values in the
		//  specified range of values.  The range starts with the
		//  value at the given starting position in the sequence and
		//  goes in the given direction to the value at to the given
		//  ending position.  {num_values} is the total number of
		//  values in the whole sequence for the enumerated type.

	    bool is_first_pass();
		//  Return true if this is the first pass for the circulator;
		//  return false otherwise.  true is returned only one time
		//  after each call to the "set_count()" member.

	    bool go_to_next_value();
		//  Advance the circulator to the next value in the range.
		//  Returns true if the circulator has been advanced; returns
		//  false if the last value in the range has been done.

	    virtual void step_forward() = 0;
		//  Advance the circulator's value forward to the next value
		//  in the sequence.  (Used by the "go_to_next_value").

	    virtual void step_backward() = 0;
		//  Advance the circulator's value backward to the previous
		//  value in the sequence.  (Used by the "go_to_next_value").

	    friend bool ::with_each(Circulator_Base & circulator);
		//  This function is a friend so it access the two protected
		//  member functions "is_first_pass" and "go_to_next_value".

	private :
	    unsigned int count_;	//  # of values left in range
	    bool	 first_pass_;	//  is first pass for circulator?

	    void (Circulator_Base::* step_function_)();
		//  Pointer to the appropriate step function to advance the
		//  circulator's value.
    };

};

//-----------------------------------------------------------------------------

#endif
