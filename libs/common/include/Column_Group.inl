//-----------------------------------------------------------------------------
//  Inline function definitions:  Column_Group class
//-----------------------------------------------------------------------------

inline
const Multi_Line_Text & Column_Group::title() const
{
    return title_;
}

//-----------------------------------------------------------------------------

inline
const std::vector<Column_or_Group> & Column_Group::members() const
{
    return members_;
}
