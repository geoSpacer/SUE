#ifndef ACTION_LEXER_H
#define ACTION_LEXER_H

//-----------------------------------------------------------------------------

#include <string>
#include <sstream>

//-----------------------------------------------------------------------------

namespace Token
{
    const int Bad_Number = -1;
    const int Bad_Char   = -2;
    const int Bad_String = -3;
};

//-----------------------------------------------------------------------------

//  This class represents a lexical analyzer (i.e., tokenizer) for an
//  action.

class Action_Lexer
{
    public:
	//------------
	//  Operations

	Action_Lexer();
	    //	Constructs a lexer.

	~Action_Lexer();
	    //	Destroys a lexer.

	void initialize(const std::string & line);
	    //	Initializes the lexer with the given string.

	void get_next_token();
	    //	Reads the next token from the input line.

	void leading_minus(bool allow);
	    //	If {allow} is true, then a number token can have a leading
	    //	minus sign.  If false, then a number token cannot have a
	    //	leading minus sign.  When the lexer is first constructed,
	    //	leading signs are allowed.

	//------------
	//  Attributes

	std::string token() const;
	    //	Returns the current token.  If at the end of the expression,
	    //	then this operation returns "".

	int token_type() const;
	    //	Returns the type of the current token.  The type is one of
	    //	these:
	    //
	    //	    1) a TOKEN_... macro defined in myparser.h
	    //	    2) a Token::Bad... constant defined above
	    //	    3) 0 for the end of the string

	int token_position() const;
	    //	Returns the character position in the expression where the
	    //	token starts.  The first character is at position 0.

	int token_int_value() const;
	    //	Returns the token's integer value.  The current token type
	    //	must be Token_Integer.

	float token_float_value() const;
	    //	Returns the token's float value.  The current token type
	    //	must be Token_Float.

    //-------------------------------------------------------------------------

    private:
	std::istringstream * line_;
	    //	The input line being scanned.

	bool leading_minus_;
	    //	Can number tokens have leading minus signs?

	char current_char_;
	    //	The current character being examined in the expression.

	int current_pos_;
	    //	The position of the current character in the expression.
	    //	Positions start at 0.

	char next_char_;
	    //	The next character after the current character.

	void get_next_char();
	    //	Reads the next character from the expression.

	std::string token_;
	    //	The current token.

	int token_type_;
	    //	The type of the current token.

	int token_start_;
	    //	Position where the current token starts.

	int int_value_;
	    //	The integer value of the current token if it's type is
	    //	Token_Integer.

	float float_value_;
	    //	The float value of the current token if it's type is
	    //	Token_Float.
};

//-----------------------------------------------------------------------------

#include "Action_Lexer.inl"

//-----------------------------------------------------------------------------

#endif
