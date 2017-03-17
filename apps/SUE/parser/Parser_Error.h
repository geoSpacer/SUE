#ifndef PARSER_ERROR_H
#define PARSER_ERROR_H

//-----------------------------------------------------------------------------

//  This struct represents an error when parsing an action.  It's thrown as
//  an exception.

struct Parser_Error
{
    std::string description;
	//  A message describing the error.

    std::string current_token;
	//  The current token where the error was detected.

    int token_position;
	//  The token's position in the input string.

    Parser_Error(const std::string & desc,
		 const std::string & token,
		 int		     position);
	//  Constructs an error.
};

//-----------------------------------------------------------------------------

#include "Parser_Error.inl"

//-----------------------------------------------------------------------------

#endif
