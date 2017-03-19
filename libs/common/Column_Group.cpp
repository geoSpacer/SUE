//-----------------------------------------------------------------------------
//  Class implementation:  Column_Group
//-----------------------------------------------------------------------------

#include "pragmas.h"

#include "Output_Column.h"
#include "Column_Group.h"

//-----------------------------------------------------------------------------

Column_Group::Column_Group(const Multi_Line_Text & title)
    : title_(title)
{
}

//-----------------------------------------------------------------------------

void Column_Group::includes(const Column_or_Group & member)
{
    members_.push_back(member);
}
