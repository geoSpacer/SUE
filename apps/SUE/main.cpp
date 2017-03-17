#include "pragmas.h"

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cmath>
#include <vector>

#include "common/Error.h"
#include "common/File_Error.h"

#include "progInfo.h"
#include "process_cmd_line.h"
#include "prog_parms.h"
#include "ComputationEngine.h"
#include "actions.h"
#include "parser/parse_action.h"
#include "parser/Parser_Error.h"

#include "common/Academic_Free_License.h"
#include "common/Input_Text_File.h"
#include "common/Input_Title.h"
#include "common/input_vars.h"
#include "common/Input_Value_Line.h"
#include "common/Input_Value_read.h"
#include "common/Required_or_Optional.h"
#include "common/no_lines_after.h"



using namespace std;


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// Here's driver/main - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------


int main(int argc, char* argv[])
{
    try {
	std::cout << Program::name << " version " << Program::version.str()
				   << " - " << Program::buildDate << "\n"
		     "Copyright (C) 2002-2004, Oregon State University\n"
		  << Academic_Free_License::notice << "\n"
		     "\n";

	switch (process_cmd_line(argc, argv)) 
	{
	    case Arg_Action_Done:
	    return 0;

	    case Arg_Error:
	    return 1;

	    default:   //  Args_OK
	    break;
	} // end switch
    
	// "file" is our Input::Text_File object which will
	// take care of reading from the actual input file.
	Input::Text_File file(Program_Parms::file, "actions");
	file.blank_lines(Skip);
	file.comment_lines(Skip);
	file.end_of_line_comments(Remove);

	std::ostringstream mesg;    ///  for error messages

	try {
	    Input_Value::Line input_line;

	    //	-----------------
	    //	Seed
	    input_line.read(file);
	    Input_Var::Int seed("Seed", 1 <= Range<int>() <= 1000000);
	    // look for Seed in input_line
	    ::read(seed, input_line, Required);
	    if ((seed.value() & 0x01) == 0) 
	    {
		mesg << "The value \"" << seed.value() << "\" is not an odd integer.";
		throw Input_Value_Error::Custom(seed, mesg);
	    }

	    //	-----------------
	    //	SampleSpaceSize
	    input_line.read(file);
	    Input_Var::Int sampleSpaceSize("SampleSpaceSize", 2 <= Range<int>() <= 1000000);
	    // look for SampleSpaceSize in input_line
	    ::read(sampleSpaceSize, input_line, Required);
	    if (sampleSpaceSize.value() < 1) 
	    {
		mesg << "The value \"" << sampleSpaceSize.value() << "\" is < 1.";
		throw Input_Value_Error::Custom(sampleSpaceSize, mesg);
	    }

	    // -------------------------------------
	    // Here's our computation engine object:
	    // -------------------------------------
	    ComputationEngine comp_eng(sampleSpaceSize.value(),
				       seed.value());

	    std::string line;
	    while (file.read_line(line))
	    {
		Action * axshun;
		try {
		    axshun = parse_action(line);
		}
		catch (Parser_Error & e) {
		    std::ostringstream mesg;
		    mesg << "Error in action:\n"
			 << "  Action: " << line << "\n"
			 << "  Error --";
		    int i;
		    for (i = e.token_position; i > 0; i--)
			mesg << "-";
		    for (i = e.current_token.size() - 1; i > 0; i--)
			mesg << "^";
		    mesg << "^\n";
		    mesg << "  " << e.description;
		    throw file.error(mesg);
		}
		std::string response;
		response = axshun->performAction(comp_eng);
		cout << response << endl;
		delete axshun;
	    }

	}
	catch (const Input_Value::Error & e) 
	{
	    // need to rebundle as file error
	    throw file.error(Message::error_with_value(e));
	}
    } // main try loop.
    catch (File::Error & e) 
    {
	print(e, std::cerr);
    }
    catch (Error & e) 
    {
	for (int i = 0; i < e.message().line_count(); i++)
	    std::cerr << e.message().line(i) << "\n";
    }
    return 0;
}
