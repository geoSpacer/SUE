//-----------------------------------------------------------------------------
//  Class implementation:  Enum::Circulator_Base
//-----------------------------------------------------------------------------

#include "Forward_or_Reverse.h"
#include "Enum_Circulator_Base.h"

//-----------------------------------------------------------------------------

Enum::Circulator_Base::Circulator_Base()
    : count_(0),
      first_pass_(false),
      step_function_(&Circulator_Base::step_forward)
{
}

//-----------------------------------------------------------------------------

void Enum::Circulator_Base::set_count(unsigned int       start_pos,
				      unsigned int       end_pos,
				      Forward_or_Reverse direction,
				      unsigned int       num_pos)
{
    first_pass_ = true;

    if ((bool) direction == (bool) Forward)
    {
	step_function_ = &Circulator_Base::step_forward;

	if (start_pos <= end_pos)
	    count_ = end_pos - start_pos + 1;
	else
	    //	Specified range:  start_pos .. lastPosition, then 0 .. end_pos
	    //	where lastPosition = num_pos - 1
	    count_ = (num_pos - start_pos)  //  count of [start_pos .. lastPos]
		     + (end_pos + 1);	    //  count of [0 .. end_pos]
    }
    else
    {
	// direction is Reverse
	step_function_ = &Circulator_Base::step_backward;

	if (end_pos <= start_pos)
	    count_ = start_pos - end_pos + 1;
	else
	    //	Specified range:  start_pos .. 0, then lastPosition .. end_pos
	    //	where lastPosition = num_pos - 1
	    count_ = (start_pos + 1)	     //  count of [start_pos .. 0]
		     + (num_pos - end_pos);  //  count of [lastPos .. end_pos]
    }
}

//-----------------------------------------------------------------------------

bool Enum::Circulator_Base::is_first_pass()
{
    if (first_pass_)
    {
	first_pass_ = false;
	return true;
    }
    return false;
}

//-----------------------------------------------------------------------------

bool Enum::Circulator_Base::go_to_next_value()
{
    if (count_ > 0)
    {
	--count_;
	if (count_ > 0)
	    (this->*step_function_)();
    }
    return count_ > 0;
}
