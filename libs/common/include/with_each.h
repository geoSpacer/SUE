#ifndef WITH_EACH_H
#define WITH_EACH_H

//-----------------------------------------------------------------------------

#include "Enum_Circulator_Base.h"

//-----------------------------------------------------------------------------

inline
bool with_each(Enum::Circulator_Base & circulator)
{
    return circulator.is_first_pass() || circulator.go_to_next_value();
}

//-----------------------------------------------------------------------------

#endif
