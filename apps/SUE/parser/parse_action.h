#ifndef PARSE_ACTION_H
#define PARSE_ACTION_H

//-----------------------------------------------------------------------------

#include <string>

class  Action;
struct Parser_Error;

Action * parse_action(const std::string & line)
	    throw(Parser_Error);

//-----------------------------------------------------------------------------

#endif
