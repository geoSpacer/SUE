//-----------------------------------------------------------------------------
//  Class implementation:  Column_or_Group
//-----------------------------------------------------------------------------

#include "pragmas.h"

#include "Output_Column.h"
#include "Column_Group.h"
#include "Column_or_Group.h"

//-----------------------------------------------------------------------------

Column_or_Group::Column_or_Group(const Output_Column & column)
    : column_(&column),
      group_(0)
{
}

//-----------------------------------------------------------------------------

Column_or_Group::Column_or_Group(const Column_Group & group)
    : column_(0),
      group_(&group)
{
}
