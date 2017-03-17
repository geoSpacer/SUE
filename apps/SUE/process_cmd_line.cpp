#include "pragmas.h"

#include <iostream>
#include <sstream>

#include "common/Program_Options.h"
#include "common/Program_Arguments.h"
#include "common/Academic_Free_License.h"
#include "common/lib_info.h"
#include "common/str_to_int.h"

#include "process_cmd_line.h"
#include "prog_parms.h"

//-----------------------------------------------------------------------------

namespace
{
    //-------------------------------------------------------------------------

    enum Options
    {
	    Option_Help,
	    Option_Version,
	    Option_License
    };

    //-------------------------------------------------------------------------

    const char * const help_mesg =

"The program is executed in one of these ways:\n"
"\n"
"  SUE {input_file}\n"
"  SUE {option}\n"
"\n"
"where the arguments are:\n"
"\n"
"  input_file : text file with the actions the program should do\n"
"\n"
"Valid options are:\n"
"\n"
"  /version  : Display the program's version number, and then exit.\n"
"  /license  : Display the program's license.\n"
"  /help     : Display this help message.\n"
"\n"
"Any option may be abbreviated by omitting one or more characters from\n"
"the end of its name.  For example, the /help option may be abbreviated\n"
"as /h, /he, or /hel.\n"
;

    //-------------------------------------------------------------------------
};

//-----------------------------------------------------------------------------

Cmd_Line_Status process_cmd_line(int	 argc,
				 char ** argv)
{


    Program_Options options;

    //  /help
    options.define("help", Option_Help, Optional, No_Value);

    //  /version
    options.define("version", Option_Version, Optional, No_Value);

    //  /license
    options.define("license", Option_License, Optional, No_Value);

    int i;
    i = 1;

    unsigned int id;
    bool value_present;
    std::string value;

    while (i < argc && options.match(argv[i], id, value_present, value)) {
	switch (id)
	{
	    case Option_Help:
		std::cout << "\n"
			  << help_mesg;
		return Arg_Action_Done;

	    case Option_Version:
		std::cout << "\n"
			  << Common_Library::lib_info() << "\n";
		return Arg_Action_Done;

	    case Option_License:
		std::cout << "\n"
			  << Academic_Free_License::full_text;
		return Arg_Action_Done;
	}
	i++;
    }
    options.ensure_all_reqd_matched();


    //	Process operands.

    std::ostringstream mesg;	//  for creating error messages

    const int max_operands = 1;
    int first_operand = i;
    int num_operands = argc - first_operand;
    if (num_operands == 1) {
	Program_Parms::file = argv[first_operand];
    }
    else {
	switch (num_operands)
	{
	    case 0:
		mesg << "Missing name of program parameter file";
		break;
	    default:	//  = or > 2
		mesg << "Found extra argument"
		     << ( num_operands > (max_operands + 1) ? "s" : "" )
		     << ": \"" << argv[first_operand + max_operands] << "\""
		     << ( num_operands > (max_operands + 1) ? " ..." : "" ) ;
	}
	throw Program_Arguments::error(mesg);
    }

    return Args_OK;
}
