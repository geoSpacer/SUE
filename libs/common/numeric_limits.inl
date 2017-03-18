//-----------------------------------------------------------------------------
//  Inline function definitions:  min_... and max_ functions
//-----------------------------------------------------------------------------

#include <limits>

//-----------------------------------------------------------------------------

inline
int max_int()
{
    return std::numeric_limits<int>::max();
}

//-----------------------------------------------------------------------------

inline
int min_int()
{
    return std::numeric_limits<int>::min();
}

//-----------------------------------------------------------------------------

inline
float max_float()
{
    return std::numeric_limits<float>::max();
}

//-----------------------------------------------------------------------------

inline
float min_float()
{
    return -std::numeric_limits<float>::max();
}
