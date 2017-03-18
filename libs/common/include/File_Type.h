#ifndef COMMON_LIB__FILE_TYPE_H
#define COMMON_LIB__FILE_TYPE_H

//-----------------------------------------------------------------------------

#include <string>

#include "File_Stat.h"	//  for File_Type

//-----------------------------------------------------------------------------

File_Type get_file_type(const std::string & path);
    //	Return the type of the specified file.

//-----------------------------------------------------------------------------

#endif
