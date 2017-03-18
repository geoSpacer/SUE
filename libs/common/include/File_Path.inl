//-----------------------------------------------------------------------------
//  Inline function definitions:  File::Path class
//-----------------------------------------------------------------------------

inline
const std::string & File::Path::drive() const
{
    return drive_;
}

//-----------------------------------------------------------------------------

inline
bool File::Path::is_absolute() const
{
    return is_absolute_;
}

//-----------------------------------------------------------------------------

inline
unsigned int File::Path::count() const
{
    return components_.size();
}

//-----------------------------------------------------------------------------

inline
File::Path::operator std::string() const
{
    return str();
}

//-----------------------------------------------------------------------------

inline
File::Path::Path(char				  drive,
		 bool				  is_absolute,
		 const std::vector<std::string> & components)
{
    File::Path(std::string(1, drive), is_absolute, components);
}
