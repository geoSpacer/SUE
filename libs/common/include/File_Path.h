#ifndef COMMON_LIB__FILE_PATH_H
#define COMMON_LIB__FILE_PATH_H

//-----------------------------------------------------------------------------

#include <string>
#include <vector>

//-----------------------------------------------------------------------------

//  Class:  File::Path
//
//  This class represents a path to a file.

namespace File
{

    class Path
    {
	//-----------
	//  Constants

	static const bool No_Extension;
	static const bool With_Extension;
	    //	to improve readability when using basename() operaton.

	//------------
	//  Attributes

	public:

	    const std::string & drive() const;
		//  The drive letter of the path.  If the path has no drive
		//  or the path is not for Windows, then this returns "".

	    bool is_absolute() const;
		//  Does the path start at the top of the directory structure,
		//  i.e., the root directory?

	    unsigned int count() const;
		//  The number of components in the path.  An empty path has 0
		//  components.

	    std::string basename(bool extension = true) const;
		//  The last component in the path.  Returns "" is there are 0
		//  components.  If {extension} is true, then the extension is
		//  left intact.  If it's false, the extension is removed.

	    const std::string & str() const;
		//  The path's representation as a string.

	    Path parent() const;
		//  The path to the parent directory.

	//------------
	//  Operations

	    Path(const std::string & path);
		//  Construct a path by parsing the given string.

	    Path(const std::string &		  drive,
		 bool				  absolute,
		 const std::vector<std::string> & components);
		//  Construct a path.  The drive must be a letter or "".

	    Path(char				  drive,
		 bool				  absolute,
		 const std::vector<std::string> & components);
		//  Construct a Windows path.  The drive must be a letter.

	    operator std::string() const;
		//  Access the path as a string (i.e., get its string
		//  representation).

	    const std::string & operator[](unsigned int position) const;
		//  Get the component at the specified position.  The position
		//  must be < count().

	    void operator+=(const Path & path);
		//  Append a path onto the current path.  The given path cannot
		//  be an absolute path or have a drive.

	//-------------------------------------------------------------------------

	private:

	    std::string drive_;
	    bool is_absolute_;

	    std::vector<std::string> components_;

	    std::string basename_;  //	without extension
	    std::string ext_;

	    mutable bool have_str_;
	    mutable std::string str_;

	    void set_basename_and_ext_();
    };

};

//-----------------------------------------------------------------------------

#include "File_Path.inl"

//-----------------------------------------------------------------------------

#endif
