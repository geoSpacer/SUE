#include "../pragmas.h"

#include <sstream>
#include <map>

#include "common/Assert_That.h"
#include "common/Ignore_Case.h"
#include "common/str_to_int.h"
#include "common/str_to_float.h"

#include "myparser.h"

#include "Action_Lexer.h"

//-----------------------------------------------------------------------------

Action_Lexer::Action_Lexer()
    : line_(0),
      leading_minus_(true)
{
    initialize("");
}

//-----------------------------------------------------------------------------

Action_Lexer::~Action_Lexer()
{
    if (line_)
	delete line_;
}

//-----------------------------------------------------------------------------

void Action_Lexer::initialize(const std::string & expression)
{
    if (line_)
	delete line_;
    line_ = new std::istringstream(expression);

    current_char_ = line_->get();
    current_pos_ = 0;

    if (current_char_ == EOF)
	next_char_ = EOF;
    else
	next_char_ = line_->get();
    get_next_token();
}

//-----------------------------------------------------------------------------

void Action_Lexer::leading_minus(bool allow)
{
    leading_minus_ = allow;
}

//-----------------------------------------------------------------------------

int Action_Lexer::token_int_value() const
{
    ASSERT_THAT(token_type_ == TOKEN_INTEGER)
    return int_value_;
}

//-----------------------------------------------------------------------------

float Action_Lexer::token_float_value() const
{
    ASSERT_THAT(token_type_ == TOKEN_FLOAT)
    return float_value_;
}

//-----------------------------------------------------------------------------

namespace
{

    bool is_known_name(const std::string & name,
		       int &		   token_type)
	//  Determines if the given name is known, i.e., it is a predefined
	//  command or expression constant.
	//
	//  Returns:
	//	true	The name is known, and its associated token type was
	//		assigned to the "token_type" parameter.
	//
	//	false	The name is not known.
    {
	static bool initialize = true;
	typedef std::map<std::string, int, Ignore_Case> Name_Map;
	static Name_Map names;

	if (initialize) {
	    names["pi"]  = TOKEN_PI;
	    names["e"]   = TOKEN_E;
	    names["t"]   = TOKEN_T;

	    names["ln"]	   = TOKEN_LN;
	    names["log10"] = TOKEN_LOG10;

	    names["triangular"]		 = TOKEN_TRIANGULAR;
	    names["uniform"]		 = TOKEN_UNIFORM;
	    names["normal"]		 = TOKEN_NORMAL;
	    names["negativeExponential"] = TOKEN_NEG_EXPONENTIAL;
	    names["normalBivariates"]	 = TOKEN_NORMAL_BIVARIATES;

	    names["rankCorrelate"]  = TOKEN_RANK_CORRELATE;
	    names["grow"]	    = TOKEN_GROW;
	    names["decay"]	    = TOKEN_DECAY;

	    names["standardDeviation"] = TOKEN_STD_DEVIATION;
	    names["mean"]	       = TOKEN_MEAN;
	    names["median"]	       = TOKEN_MEDIAN;
	    names["correlation"]       = TOKEN_CORRELATION;
	    names["rankCorrelation"]   = TOKEN_RANK_CORRELATION;
	    names["percentileBounds"]  = TOKEN_PERCENTILE_BOUNDS;

	    names["regression"]		   = TOKEN_REGRESSION;
	    names["regressionPercentiles"] = TOKEN_REGRESSION_PERCENTILES;

	    names["valsToCSV"]	  = TOKEN_VALS_TO_CSV;
	    names["histogramize"] = TOKEN_HISTOGRAMIZE;

	    initialize = false;
	}

	Name_Map::const_iterator p = names.find(name);
	if (p == names.end())
	    return false;
	token_type = p->second;
	return true;
    }

};

//-----------------------------------------------------------------------------

void Action_Lexer::get_next_token()
{
    while (isspace(current_char_)) {
	get_next_char();
    }

    token_start_ = current_pos_;

    if (current_char_ == EOF) {
	token_ = "";
	token_type_ = 0;
	return;
    }

    //	Check for single-character tokens (e.g., operators, punctuation)
    token_ = current_char_;
    token_type_ = 0;
    switch (current_char_)
    {
	case '+' :
	    token_type_ = TOKEN_PLUS;
	    break;
//	case '-' :
//	    token_type_ = TOKEN_MINUS;
//	    break;
	case '/' :
	    token_type_ = TOKEN_SLASH;
	    break;
	case '*' :
	    token_type_ = TOKEN_STAR;
	    break;
	case '^' :
	    token_type_ = TOKEN_CARET;
	    break;

	case ',' :
	    token_type_ = TOKEN_COMMA;
	    break;
	case '(' :
	    token_type_ = TOKEN_LEFT_PAREN;
	    break;
	case ')' :
	    token_type_ = TOKEN_RIGHT_PAREN;
	    break;

	case '=' :
	    token_type_ = TOKEN_EQUAL;
	    break;
    }  //  switch
    if (token_type_ != 0)
    {
	get_next_char();
	return;
    }

    //	Minus sign ('-') which may be the leading sign of a number
    bool have_minus = (current_char_ == '-');
    if (have_minus) {
	get_next_char();
	if (leading_minus_ &&
		(isdigit(current_char_) || (current_char_ == '.'))) {
	    token_ += current_char_;
	} else {
	    token_type_ = TOKEN_MINUS;
	    return;
	}
    }

    //	Integer literal: digit ...
    bool have_int = false;
    if (isdigit(current_char_)) {
	have_int = true;
	get_next_char();
	while (isdigit(current_char_)) {
	    token_ += current_char_;
	    get_next_char();
	}
	if (current_char_ == '.' || current_char_ == 'e'
				 || current_char_ == 'E')
	    token_ += current_char_;
	else {
	    token_type_ = TOKEN_INTEGER;
	    str_to_int(token_, int_value_);
	    return;
	}
    }

    //	The decimal part of a floating-point number: "." digit ...
    bool have_decimal = false;
    if (current_char_ == '.') {
	get_next_char();
	while (isdigit(current_char_)) {
	    have_decimal = true;
	    token_ += current_char_;
	    get_next_char();
	}
	if (! have_int && (! have_decimal)) {
	    token_ += current_char_;
	    token_type_ = Token::Bad_Number;
	    return;
	}
	else if (current_char_ == 'e' || current_char_ == 'E')
	    token_ += current_char_;
	else {
	    token_type_ = TOKEN_FLOAT;
	    str_to_float(token_, float_value_);
	    return;
	}
    }

    //	The exponent of a floating-pt number:
    //	    ( "e" | "E" ) [ "-" | "-" ] digit ...
    if ((have_int || have_decimal) && (current_char_ == 'e'
				       || current_char_ == 'E')) {
	get_next_char();
	if (current_char_ == '-' || current_char_ == '+') {
	    token_ += current_char_;
	    get_next_char();
	}
	if (! isdigit(current_char_)) {
	    token_ += current_char_;
	    token_type_ = Token::Bad_Number;
	    return;
	}
	while (isdigit(current_char_)) {
	    token_ += current_char_;
	    get_next_char();
	}
	token_type_ = TOKEN_FLOAT;
	str_to_float(token_, float_value_);
	return;
    }

    //	name of a variable, an action, or an expression constant (e.g. pi):
    //	name := letter [ letter | digit | "_" ] ...
    if (isalpha(current_char_)) {
	get_next_char();
	while (isalnum(current_char_) || current_char_ == '_') {
	    token_ += current_char_;
	    get_next_char();
	}
	if (is_known_name(token_, token_type_))
	    return;
	token_type_ = TOKEN_VAR_NAME;
	return;
    }

    //	A quoted string
    if (current_char_ == '"') {
	token_ = ""; //	Trim the quotes from the token
	get_next_char();
	while (current_char_ != '"') {
	    if (current_char_ == EOF) {
		token_type_ = Token::Bad_String;
		return;
	    }
	    token_ += current_char_;
	    get_next_char();
	}
	get_next_char();
	token_type_ = TOKEN_STRING;
	return;
    }

    token_type_ = Token::Bad_Char;
}

//-----------------------------------------------------------------------------
//  Private functions
//-----------------------------------------------------------------------------

void Action_Lexer::get_next_char()
{
    if (current_char_ == EOF)
	return;
    current_char_ = next_char_;
    current_pos_++;
    if (next_char_ != EOF)
	next_char_ = line_->get();
}
