#ifndef PARSER_IMPL_H
#define PARSER_IMPL_H

//-----------------------------------------------------------------------------

#include <vector>
#include <string>

#include "Action_Lexer.h"
#include "Parser_Error.h"

#include "../Command.h"
#include "../Action.h"

//-----------------------------------------------------------------------------

//  Types and functions to implement the action parser.

namespace Action_Parser
{
    extern Action * action;
	//  The action that was parsed.

    extern Action_Lexer lexer;
	//  The lexical analyzer for the action.

    void check_if_bad_token();
	//  Checks to see if the current token is a bad token.  If so, an
	//  error is reported.

    extern std::vector<Command> command_sequence;
	//  The sequence of commands that implement an expression associated
	//  with an action.

    int put_command(Command_Code command);
	//  Adds a command without an argument to the end of the command
	//  sequence.  Returns the command's position in the sequence.

    int put_command(Command_Code command,
		    int		 argument);
	//  Adds a command with an integer argument to the end of the command
	//  sequence.  Returns the command's position in the sequence.

    int put_command(Command_Code command,
		    float	 argument);
	//  Adds a command with a float argument to the end of the command
	//  sequence.  Returns the command's position in the sequence.

    int put_command(Command_Code	command,
		    const std::string &	argument);
	//  Adds a command with a string argument to the end of the command
	//  sequence.  Returns the command's position in the sequence.

    void error(const std::string & message);
	//  Throw a Parser_Error exception with the given message and the
	//  current token.
};

//-----------------------------------------------------------------------------

#endif
