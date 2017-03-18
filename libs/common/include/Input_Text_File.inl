//-----------------------------------------------------------------------------
//  Inline function definitions:  Input::Text_File class
//-----------------------------------------------------------------------------

inline
void Input::Text_File::blank_lines(Read_or_Skip read_or_skip)
{
    blank_lines_ = read_or_skip;
}

//-----------------------------------------------------------------------------

inline
void Input::Text_File::comment_lines(Read_or_Skip read_or_skip)
{
    comment_lines_ = read_or_skip;
}

//-----------------------------------------------------------------------------

inline
void Input::Text_File::end_of_line_comments(Leave_or_Remove leave_or_remove)
{
    eol_comments_ = leave_or_remove;
}

//-----------------------------------------------------------------------------

inline
Read_or_Skip Input::Text_File::blank_lines() const
{
    return blank_lines_;
}

//-----------------------------------------------------------------------------

inline
Read_or_Skip Input::Text_File::comment_lines() const
{
    return comment_lines_;
}

//-----------------------------------------------------------------------------

inline
Leave_or_Remove Input::Text_File::end_of_line_comments() const
{
    return eol_comments_;
}

//-----------------------------------------------------------------------------

inline
int Input::Text_File::line_num() const
{
    return line_num_;
}

//-----------------------------------------------------------------------------

inline
bool Input::Text_File::at_end() const
{
    return eof_reached_;
}
