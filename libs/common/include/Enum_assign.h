#ifndef COMMON_LIB__ENUM_ASSIGN_H
#define COMMON_LIB__ENUM_ASSIGN_H

//-----------------------------------------------------------------------------

#include <map>

//-----------------------------------------------------------------------------

//  Function:  Enum::assign
//
//  This template function assigns an object of an enumerated type by looking
//  for a particular key in a map.  If the key is in the map, then the
//  enumerated value associated with the key is assigned to the object, and
//  the function returns true.  If the key is not in the map, the function
//  returns false.

namespace Enum
{

    template<class Enum_T,	//  enumerated type
	     class Key_T,	//  key type in map
	     class Cmp_T>	//  comparison type for map's keys
    bool assign(Enum_T &			       obj,
		const Key_T &			       key,
		const std::map<Key_T, Enum_T, Cmp_T> & map)
    {
	std::map<Key_T, Enum_T, Cmp_T>::const_iterator p = map.find(key);
	if (p == map.end())
	    return false;

	obj = p->second;
	return true;
    }

};

//-----------------------------------------------------------------------------

#endif
