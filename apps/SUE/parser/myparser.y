%{
/****************************************************************************
myparser.y
ParserWizard generated YACC file.

Date: Tuesday, July 17, 2001
****************************************************************************/
%}

/////////////////////////////////////////////////////////////////////////////
// declarations section

%{

#include "../pragmas.h"

#include "parser_impl.h"
    using namespace Action_Parser;

#include "../Actions.h"

%}

%include{
#include <vector>
#include <string>
}

// parser name
%name myparser

// class definition
{
	// place any extra class members here
	virtual int yygettoken();

	bool first_call_to_gettoken;
	virtual void yysyntaxerror();
	
    private:
	bool allow_T_var_;
	    //	Is the T variable allowed in an expression?  It can be appear
	    //	in regression expressions, but not assignment expressions.

	std::vector<double> floats_;
	    //	Values associated with TOKEN_FLOATs in an action

	std::vector<std::string> vars_;
	    //	List of variable names in an action

	std::string filename_;
	    //	for output commands

	std::vector<double> percentiles_;
	    //	for RegressionPercentiles action
}

// constructor
{
	// place any extra initialisation code here
	first_call_to_gettoken = true;
	
	lexer.leading_minus(true);
}

// place any declarations here

//  Distribution types for variables

%token TOKEN_VAR_NAME

%token TOKEN_TRIANGULAR
%token TOKEN_UNIFORM
%token TOKEN_NORMAL
%token TOKEN_NEG_EXPONENTIAL
%token TOKEN_NORMAL_BIVARIATES

//	Tokens in expressions

%token TOKEN_COMMA
%token TOKEN_LEFT_PAREN, TOKEN_RIGHT_PAREN

%token TOKEN_EQUAL

%left  TOKEN_PLUS, TOKEN_MINUS
%left  TOKEN_STAR, TOKEN_SLASH
%right TOKEN_CARET
%right UNARY_MINUS

%token TOKEN_INTEGER
%token TOKEN_FLOAT

%token TOKEN_PI
%token TOKEN_E
%token TOKEN_T

%token TOKEN_LN
%token TOKEN_LOG10

//	Actions

%token TOKEN_RANK_CORRELATE
%token TOKEN_GROW
%token TOKEN_DECAY

%token TOKEN_STD_DEVIATION
%token TOKEN_MEAN
%token TOKEN_MEDIAN
%token TOKEN_CORRELATION
%token TOKEN_RANK_CORRELATION
%token TOKEN_PERCENTILE_BOUNDS

%token TOKEN_REGRESSION
%token TOKEN_REGRESSION_PERCENTILES
%token TOKEN_STRING

%token TOKEN_VALS_TO_CSV
%token TOKEN_HISTOGRAMIZE

%%

/////////////////////////////////////////////////////////////////////////////
// rules section

// place your YACC rules here (there must be at least one)

action
	: variable_defn
	| rank_correlate
	| stats_query
	| regression
	| output
	;

//-----------------------------------------------------------------------------

var_name
	: TOKEN_VAR_NAME
	    {
		vars_.push_back(lexer.token());
		$$ = vars_.size() - 1;
	    }
	;

integer
	: TOKEN_INTEGER
	    {
		$$ = lexer.token_int_value();
	    }
	;

number
	: integer
	    {
		floats_.push_back($1);
		$$ = floats_.size() - 1;
	    }
	| TOKEN_FLOAT
	    {
		floats_.push_back(lexer.token_float_value());
		$$ = floats_.size() - 1;
	    }
	;

//-----------------------------------------------------------------------------

variable_defn
	: var_name TOKEN_EQUAL TOKEN_TRIANGULAR TOKEN_LEFT_PAREN
			number TOKEN_COMMA number TOKEN_COMMA number
			TOKEN_RIGHT_PAREN
	    {
		Action_Parser::action = new TriangularAction(vars_[$1],
							     floats_[$5],
							     floats_[$7],
							     floats_[$9]);
	    }

	| var_name TOKEN_EQUAL TOKEN_UNIFORM TOKEN_LEFT_PAREN
			number TOKEN_COMMA number TOKEN_RIGHT_PAREN
	    {
		Action_Parser::action = new UniformAction(vars_[$1],
							  floats_[$5],
							  floats_[$7]);
	    }

	| var_name TOKEN_EQUAL TOKEN_NORMAL TOKEN_LEFT_PAREN
			number TOKEN_COMMA number TOKEN_RIGHT_PAREN
	    {
		Action_Parser::action = new NormalAction(vars_[$1],
							 floats_[$5],
							 floats_[$7]);
	    }

	| var_name TOKEN_EQUAL TOKEN_NEG_EXPONENTIAL TOKEN_LEFT_PAREN
			number TOKEN_COMMA number TOKEN_RIGHT_PAREN
	    {
		Action_Parser::action = new NegExpAction(vars_[$1],
							 floats_[$5],
							 floats_[$7]);
	    }

	| var_name TOKEN_COMMA var_name TOKEN_EQUAL TOKEN_NORMAL_BIVARIATES
			TOKEN_LEFT_PAREN number TOKEN_COMMA
			number TOKEN_COMMA number TOKEN_COMMA
			number TOKEN_COMMA number TOKEN_RIGHT_PAREN
	    {
		Action_Parser::action = new NormalBivariatesAction(floats_[$7],
								   vars_[$1],
								   floats_[$9],
								   floats_[$11],
								   vars_[$3],
								   floats_[$13],
								   floats_[$15]);
	    }

	| var_name TOKEN_EQUAL
		{
		    allow_T_var_ = false;
		    lexer.leading_minus(false);
		}
	    expr
		{
		    Action_Parser::action = new
				    AssignFromEquationAction(vars_[$1],
							     command_sequence);
		}
	;

//-----------------------------------------------------------------------------

expr
	: TOKEN_INTEGER
		{ put_command(Command_Integer, lexer.token_int_value()); }
	| TOKEN_FLOAT
		{ put_command(Command_Float, lexer.token_float_value()); }
	| constant
	| function
	| TOKEN_VAR_NAME
		{ put_command(Command_Var, lexer.token()); }
	| TOKEN_T
		{
		    if (allow_T_var_)
			put_command(Command_T);
		    else
			Action_Parser::error("\"t\" cannot be used in"
					     " an assignment expression");
		}
	| TOKEN_MINUS expr %prec UNARY_MINUS
		{ put_command(Command_Negate); }
	| expr TOKEN_PLUS  expr
		{ put_command(Command_Add); }
	| expr TOKEN_MINUS expr
		{ put_command(Command_Subtract); }
	| expr TOKEN_STAR  expr
		{ put_command(Command_Multiply); }
	| expr TOKEN_SLASH expr
		{ put_command(Command_Divide); }
	| expr TOKEN_CARET expr
		{ put_command(Command_Exponentation); }
	| TOKEN_LEFT_PAREN expr TOKEN_RIGHT_PAREN
	;

constant
	: TOKEN_PI
		{ put_command(Command_Pi); }
	| TOKEN_E
		{ put_command(Command_E); }
	;

function
	: ln_function
	| log10_function
	;

ln_function
	: TOKEN_LN TOKEN_LEFT_PAREN expr TOKEN_RIGHT_PAREN
	    { put_command(Command_Ln); }
	;

log10_function
	: TOKEN_LOG10 TOKEN_LEFT_PAREN expr TOKEN_RIGHT_PAREN
	    { put_command(Command_Log10); }
	;

//-----------------------------------------------------------------------------

rank_correlate
	: TOKEN_RANK_CORRELATE TOKEN_LEFT_PAREN var_name TOKEN_COMMA
			var_name TOKEN_COMMA number TOKEN_COMMA grow_or_decay
			TOKEN_RIGHT_PAREN
	    {
		Action_Parser::action = new RankCorrelateAction(vars_[$3],
								vars_[$5],
								floats_[$7],
								$9);
	    }
	;

grow_or_decay
	: TOKEN_GROW
	    { $$ = 2; }
	| TOKEN_DECAY
	    { $$ = 1; }
	;

//------------------------------------------------------------------------------
	
stats_query
	: TOKEN_STD_DEVIATION TOKEN_LEFT_PAREN var_name TOKEN_RIGHT_PAREN
	    {
		Action_Parser::action = new StandardDeviationAction(vars_[$3]);
	    }

	| TOKEN_MEAN TOKEN_LEFT_PAREN var_name TOKEN_RIGHT_PAREN
	    {
		Action_Parser::action = new MeanAction(vars_[$3]);
	    }


	| TOKEN_MEDIAN TOKEN_LEFT_PAREN var_name TOKEN_RIGHT_PAREN
	    {
		Action_Parser::action = new MedianAction(vars_[$3]);
	    }

	| TOKEN_CORRELATION TOKEN_LEFT_PAREN var_name TOKEN_COMMA
			var_name TOKEN_RIGHT_PAREN
	    {
		Action_Parser::action = new CorrelationAction(vars_[$3],
							      vars_[$5]);
	    }

	| TOKEN_RANK_CORRELATION TOKEN_LEFT_PAREN var_name TOKEN_COMMA
			var_name TOKEN_RIGHT_PAREN
	    {
		Action_Parser::action = new RankCorrelationAction(vars_[$3],
								  vars_[$5]);
	    }


	| TOKEN_PERCENTILE_BOUNDS TOKEN_LEFT_PAREN var_name TOKEN_COMMA
			number TOKEN_RIGHT_PAREN
	    {
		Action_Parser::action = new PercentileBoundsAction(vars_[$3],
								   floats_[$5]);
	    }
	;

//------------------------------------------------------------------------------

filename
	: TOKEN_STRING
	    {
		filename_ = lexer.token();
	    }
	;

regression
	: TOKEN_REGRESSION
		{
		    allow_T_var_ = true;
		    lexer.leading_minus(false);
		}
			TOKEN_LEFT_PAREN expr
		{
		    lexer.leading_minus(true);
		}
			TOKEN_COMMA
			number TOKEN_COMMA number TOKEN_COMMA integer
			TOKEN_COMMA filename TOKEN_RIGHT_PAREN
	    {
		Action_Parser::action = new RegressionAction(filename_,
							     command_sequence,
							     floats_[$7],
							     floats_[$9],
							     $11);
	    }

	| TOKEN_REGRESSION_PERCENTILES
		{
		    allow_T_var_ = true;
		    lexer.leading_minus(false);
		}
			TOKEN_LEFT_PAREN expr
		{
		    lexer.leading_minus(true);
		}
			TOKEN_COMMA
			number TOKEN_COMMA number TOKEN_COMMA integer
			TOKEN_COMMA percentiles TOKEN_COMMA filename
			TOKEN_RIGHT_PAREN
	    {
		Action_Parser::action = new RegressionPercentilesAction(
							    filename_,
							    command_sequence,
							    floats_[$7],
							    floats_[$9],
							    $11,
							    percentiles_);
	    }
	;

percentiles
	: TOKEN_LEFT_PAREN percentile more_percentiles TOKEN_RIGHT_PAREN
	;

percentile
	: number
	    {
		percentiles_.push_back(floats_[$1]);
		floats_.pop_back();
	    }
	;

more_percentiles
	:  // empty
	| TOKEN_COMMA percentile more_percentiles
	;

//------------------------------------------------------------------------------

output
	: TOKEN_VALS_TO_CSV TOKEN_LEFT_PAREN var_name TOKEN_COMMA more_vars
			filename TOKEN_RIGHT_PAREN
	    {
		Action_Parser::action = new ValsToCSVAction(filename_,
							    vars_);
	    }

	| TOKEN_HISTOGRAMIZE TOKEN_LEFT_PAREN var_name TOKEN_COMMA
			integer TOKEN_COMMA number TOKEN_COMMA
			filename TOKEN_RIGHT_PAREN
	    {
		Action_Parser::action = new HistogramAction(filename_,
							    vars_[$3],
							    $5,
							    floats_[$7]);
	    }
	;

more_vars
	:   // empty
	| var_name TOKEN_COMMA more_vars
	;

%%

/////////////////////////////////////////////////////////////////////////////
// programs section

//-----------------------------------------------------------------------------

int YYPARSERNAME::yygettoken()
{
    using namespace Action_Parser;

    if (first_call_to_gettoken)
	first_call_to_gettoken = false;
    else
	lexer.get_next_token();
    check_if_bad_token();
    return lexer.token_type();
}

//-----------------------------------------------------------------------------

namespace
{
    const char * error_mesgs[] = {
#include "error_mesgs.c"
    };
    
    struct Error_State
    {
	int state;
	int mesg_num;
    };
    
    const Error_State error_states[] = {
#include "error_states.c"
    };
    
    const int error_state_count = sizeof(error_states) / sizeof(Error_State);
};

//-----------------------------------------------------------------------------

void YYPARSERNAME::yysyntaxerror()
{
    if (Action_Parser::action)
	delete Action_Parser::action;
	
    int state = yypeek();
    for (int i = 0; i < error_state_count; i++) {
        if (error_states[i].state == state) {
            int mesg_num = error_states[i].mesg_num;
	    Action_Parser::error(error_mesgs[mesg_num]);
	}
    }

    std::ostringstream mesg;
    mesg << "Syntax error (state is " << state << ")";
    Action_Parser::error(mesg.str());
}

//-----------------------------------------------------------------------------
