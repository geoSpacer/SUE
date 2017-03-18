#ifndef COMMON_LIB__MAP_MERGE_H
#define COMMON_LIB__MAP_MERGE_H

//-----------------------------------------------------------------------------

#include <map>

//-----------------------------------------------------------------------------

//  Function:  merge
//
//  This function merges two maps into a single map.

template<class Index_T, class Elem_T, class Cmp_T>
std::map<Elem_T, Index_T, Cmp_T>merge(
				const std::map<Elem_T, Index_T, Cmp_T> & map1,
				const std::map<Elem_T, Index_T, Cmp_T> & map2);

//----------------------------------------------------------------------------

#include "map_merge.inl"

//----------------------------------------------------------------------------

#endif
