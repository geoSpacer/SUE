//-----------------------------------------------------------------------------
//  Inline function definitions:  Column_or_Group class
//-----------------------------------------------------------------------------

inline
const Output_Column * Column_or_Group::column() const
{
    return column_;
}

//-----------------------------------------------------------------------------

inline
const Column_Group * Column_or_Group::group() const
{
    return group_;
}
