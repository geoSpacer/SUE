#include "pragmas.h"

#include "File_Type.h"

//-----------------------------------------------------------------------------

File_Type get_file_type(const std::string & path)
{
    File::Stat * stat = File::Stat::get(path);
    if (stat) {
	File_Type type = stat->type();
	delete stat;
	return type;
    }
    else
	return Not_Exist;
}
