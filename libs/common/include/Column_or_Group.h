#ifndef COMMON_LIB__COLUMN_OR_GROUP_H
#define COMMON_LIB__COLUMN_OR_GROUP_H

//-----------------------------------------------------------------------------

#include <vector>
#include <string>

//-----------------------------------------------------------------------------

//  Class:  Column_or_Group
//
//  This class represents either an individual output column or a group of
//  columns.

class Output_Column;
class Column_Group;

class Column_or_Group
{
    public:
	//------------
	//  Operations

	Column_or_Group(const Output_Column & column);
	    //	Construct with an output column.

	Column_or_Group(const Column_Group & group);
	    //	Construct with a column group.

	const Output_Column * column() const;
	    //	Access as an output column.  0 returned if not a column.

	const Column_Group * group() const;
	    //	Access as a column group.  0 returned if not a group.

    //-------------------------------------------------------------------------

    private:
	const Output_Column * column_;
	const Column_Group *  group_;
};

//-----------------------------------------------------------------------------

#include "Column_or_Group.inl"

//-----------------------------------------------------------------------------

#endif
