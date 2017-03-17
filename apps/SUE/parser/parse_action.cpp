#include "../pragmas.h"

#include "myparser.h"
#include "parser_impl.h"
    using namespace Action_Parser;

//-----------------------------------------------------------------------------

Action * parse_action(const std::string & line)
{
    action = 0;
    command_sequence.clear();
    lexer.initialize(line);
    check_if_bad_token();

    myparser parser;
    if (parser.yycreate()) {
	int n = parser.yyparse();
	if (n)
	    //	This should an internal error.
	    error("Error happened in parser");
    } else {
	//  This should an internal error.
	error("Cannot initialize parser.");
    }

    return action;
}
