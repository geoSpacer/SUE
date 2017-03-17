#include "../pragmas.h"

#include <sstream>

#include "parser_impl.h"

//-----------------------------------------------------------------------------

Action * Action_Parser::action = 0;

//-----------------------------------------------------------------------------

Action_Lexer Action_Parser::lexer;

//-----------------------------------------------------------------------------

std::vector<Command> Action_Parser::command_sequence;

//-----------------------------------------------------------------------------

void Action_Parser::check_if_bad_token()
{
    if (lexer.token_type() == Token::Bad_Number
	    || lexer.token_type() == Token::Bad_Char
	    || lexer.token_type() == Token::Bad_String) {
	std::ostringstream mesg;
	mesg << "\"" << lexer.token() << "\" is not ";
	switch (lexer.token_type())
	{
	    case Token::Bad_Number:
		mesg << "a valid number.";
		break;
	    case Token::Bad_Char:
		mesg << "a valid operator or punctuation symbol.";
		break;
	    case Token::Bad_String:
		mesg << "a valid string (no ending quote)";
		break;
	}
	error(mesg.str());
    }
}

//-----------------------------------------------------------------------------

int Action_Parser::put_command(Command_Code command)
{
    command_sequence.push_back(Command(command));
    return command_sequence.size() - 1;
}

//-----------------------------------------------------------------------------

int Action_Parser::put_command(Command_Code command,
			       int	    argument)
{
    command_sequence.push_back(Command(command, argument));
    return command_sequence.size() - 1;
}

//-----------------------------------------------------------------------------

int Action_Parser::put_command(Command_Code command,
			       float	    argument)
{
    command_sequence.push_back(Command(command, argument));
    return command_sequence.size() - 1;
}

//-----------------------------------------------------------------------------

int Action_Parser::put_command(Command_Code	   command,
			       const std::string & argument)
{
    command_sequence.push_back(Command(command, argument));
    return command_sequence.size() - 1;
}

//-----------------------------------------------------------------------------

void Action_Parser::error(const std::string & message)
{
    throw Parser_Error(message, lexer.token(), lexer.token_position());
}
