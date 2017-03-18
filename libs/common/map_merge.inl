//-----------------------------------------------------------------------------
//  Inline function definitions:  "merge" function template
//-----------------------------------------------------------------------------

template<class Index_T, class Elem_T, class Cmp_T>
std::map<Elem_T, Index_T, Cmp_T>merge(
				const std::map<Elem_T, Index_T, Cmp_T> & map1,
				const std::map<Elem_T, Index_T, Cmp_T> & map2)
{
    std::map<Elem_T, Index_T, Cmp_T> combined_map(map1);
    std::map<Elem_T, Index_T, Cmp_T>::const_iterator p;

    for (p = map2.begin(); p != map2.end(); ++p)
	combined_map[p->first] = p->second;
    return combined_map;
}
