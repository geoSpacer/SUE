#ifndef COMMON_LIB__COLUMN_GROUP_H
#define COMMON_LIB__COLUMN_GROUP_H

//-----------------------------------------------------------------------------

#include <vector>
#include <string>

#include "Column_or_Group.h"
#include "Multi_Line_Text.h"

//-----------------------------------------------------------------------------

//  Class:  Column_Group
//
//  This class represents a group of output columns.

class Column_Group
{
    public:
	//------------
	//  Operations

	Column_Group(const Multi_Line_Text & title);
	    //	Construct an empty column group with the given title.

	void includes(const Column_or_Group & member);
	    //	Add a new member to the group.

	//------------
	//  Attributes

	const Multi_Line_Text & title() const;
	    //	The group's title.

	const std::vector<Column_or_Group> & members() const;
	    //	The members of the group.

    //-------------------------------------------------------------------------

    private:
	Multi_Line_Text		     title_;
	std::vector<Column_or_Group> members_;
};

//-----------------------------------------------------------------------------

#include "Column_Group.inl"

//-----------------------------------------------------------------------------

#endif
