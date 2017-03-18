//-----------------------------------------------------------------------------
//  Inline function definitions:  File::Stat class
//-----------------------------------------------------------------------------

inline
const File::Path & File::Stat::path() const
{
    return path_;
}

//-----------------------------------------------------------------------------

inline
File_Type File::Stat::type() const
{
    return type_;
}

//-----------------------------------------------------------------------------

inline
const Date_Time & File::Stat::mod_time() const
{
    return mod_time_;
}
