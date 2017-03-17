/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 1 of your 30 day trial period.
* 
* This file was produced by an UNREGISTERED COPY of Parser Generator. It is
* for evaluation purposes only. If you continue to use Parser Generator 30
* days after installation then you are required to purchase a license. For
* more information see the online help or go to the Bumble-Bee Software
* homepage at:
* 
* http://www.bumblebeesoftware.com
* 
* This notice must remain present in the file. It cannot be removed.
****************************************************************************/

/****************************************************************************
* myparser.cpp
* C++ source file generated from myparser.y.
* 
* Date: 03/12/03
* Time: 16:02:48
* 
* AYACC Version: 1.97 (Beta Release)
****************************************************************************/

#include <cyacc.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#line 1 "myparser.y"

/****************************************************************************
myparser.y
ParserWizard generated YACC file.

Date: Tuesday, July 17, 2001
****************************************************************************/

#line 13 "myparser.y"


#include "../pragmas.h"

#include "parser_impl.h"
    using namespace Action_Parser;

#include "../Actions.h"


#line 58 "myparser.cpp"
// repeated because of possible precompiled header
#include <cyacc.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#include "myparser.h"

/////////////////////////////////////////////////////////////////////////////
// constructor

YYPARSERNAME::YYPARSERNAME()
{
	yytables();
#line 59 "myparser.y"

	// place any extra initialisation code here
	first_call_to_gettoken = true;
	
	lexer.leading_minus(true);

#line 85 "myparser.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYPARSERNAME::~YYPARSERNAME()
{
	// allows virtual functions to be called properly for correct cleanup
	yydestroy();
}

#ifndef YYSTYPE
#define YYSTYPE int
#endif
#ifndef YYSTACK_SIZE
#define YYSTACK_SIZE 100
#endif
#ifndef YYSTACK_MAX
#define YYSTACK_MAX 0
#endif

/****************************************************************************
* N O T E
* 
* If the compiler generates a YYPARSERNAME error then you have not declared
* the name of the parser. The easiest way to do this is to use a name
* declaration. This is placed in the declarations section of your YACC
* source file and is introduced with the %name keyword. For instance, the
* following name declaration declares the parser myparser:
* 
* %name myparser
* 
* For more information see help.
****************************************************************************/

// yyattribute
#ifdef YYDEBUG
void YYFAR* YYPARSERNAME::yyattribute1(int index) const
{
	YYSTYPE YYFAR* p = &((YYSTYPE YYFAR*)yyattributestackptr)[yytop + index];
	return p;
}
#define yyattribute(index) (*(YYSTYPE YYFAR*)yyattribute1(index))
#else
#define yyattribute(index) (((YYSTYPE YYFAR*)yyattributestackptr)[yytop + (index)])
#endif

void YYPARSERNAME::yystacktoval(int index)
{
	yyassert(index >= 0);
	*(YYSTYPE YYFAR*)yyvalptr = ((YYSTYPE YYFAR*)yyattributestackptr)[index];
}

void YYPARSERNAME::yyvaltostack(int index)
{
	yyassert(index >= 0);
	((YYSTYPE YYFAR*)yyattributestackptr)[index] = *(YYSTYPE YYFAR*)yyvalptr;
}

void YYPARSERNAME::yylvaltoval()
{
	*(YYSTYPE YYFAR*)yyvalptr = *(YYSTYPE YYFAR*)yylvalptr;
}

void YYPARSERNAME::yyvaltolval()
{
	*(YYSTYPE YYFAR*)yylvalptr = *(YYSTYPE YYFAR*)yyvalptr;
}

void YYPARSERNAME::yylvaltostack(int index)
{
	yyassert(index >= 0);
	((YYSTYPE YYFAR*)yyattributestackptr)[index] = *(YYSTYPE YYFAR*)yylvalptr;
}

void YYFAR* YYPARSERNAME::yynewattribute(int count)
{
	yyassert(count >= 0);
	return new YYFAR YYSTYPE[count];
}

void YYPARSERNAME::yydeleteattribute(void YYFAR* attribute)
{
	delete[] (YYSTYPE YYFAR*)attribute;
}

void YYPARSERNAME::yycopyattribute(void YYFAR* dest, const void YYFAR* src, int count)
{
	for (int i = 0; i < count; i++) {
		((YYSTYPE YYFAR*)dest)[i] = ((YYSTYPE YYFAR*)src)[i];
	}
}

#ifdef YYDEBUG
void YYPARSERNAME::yyinitdebug(void YYFAR** p, int count) const
{
	yyassert(p != NULL);
	yyassert(count >= 1);

	YYSTYPE YYFAR** p1 = (YYSTYPE YYFAR**)p;
	for (int i = 0; i < count; i++) {
		p1[i] = &((YYSTYPE YYFAR*)yyattributestackptr)[yytop + i - (count - 1)];
	}
}
#endif

void YYPARSERNAME::yyaction(int action)
{
	switch (action) {
	case 0:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 139 "myparser.y"

		vars_.push_back(lexer.token());
		(*(YYSTYPE YYFAR*)yyvalptr) = vars_.size() - 1;
	    
#line 207 "myparser.cpp"
			}
		}
		break;
	case 1:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 147 "myparser.y"

		(*(YYSTYPE YYFAR*)yyvalptr) = lexer.token_int_value();
	    
#line 222 "myparser.cpp"
			}
		}
		break;
	case 2:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 154 "myparser.y"

		floats_.push_back(yyattribute(1 - 1));
		(*(YYSTYPE YYFAR*)yyvalptr) = floats_.size() - 1;
	    
#line 238 "myparser.cpp"
			}
		}
		break;
	case 3:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 159 "myparser.y"

		floats_.push_back(lexer.token_float_value());
		(*(YYSTYPE YYFAR*)yyvalptr) = floats_.size() - 1;
	    
#line 254 "myparser.cpp"
			}
		}
		break;
	case 4:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[11];
			yyinitdebug((void YYFAR**)yya, 11);
#endif
			{
#line 171 "myparser.y"

		Action_Parser::action = new TriangularAction(vars_[yyattribute(1 - 10)],
							     floats_[yyattribute(5 - 10)],
							     floats_[yyattribute(7 - 10)],
							     floats_[yyattribute(9 - 10)]);
	    
#line 272 "myparser.cpp"
			}
		}
		break;
	case 5:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[9];
			yyinitdebug((void YYFAR**)yya, 9);
#endif
			{
#line 180 "myparser.y"

		Action_Parser::action = new UniformAction(vars_[yyattribute(1 - 8)],
							  floats_[yyattribute(5 - 8)],
							  floats_[yyattribute(7 - 8)]);
	    
#line 289 "myparser.cpp"
			}
		}
		break;
	case 6:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[9];
			yyinitdebug((void YYFAR**)yya, 9);
#endif
			{
#line 188 "myparser.y"

		Action_Parser::action = new NormalAction(vars_[yyattribute(1 - 8)],
							 floats_[yyattribute(5 - 8)],
							 floats_[yyattribute(7 - 8)]);
	    
#line 306 "myparser.cpp"
			}
		}
		break;
	case 7:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[9];
			yyinitdebug((void YYFAR**)yya, 9);
#endif
			{
#line 196 "myparser.y"

		Action_Parser::action = new NegExpAction(vars_[yyattribute(1 - 8)],
							 floats_[yyattribute(5 - 8)],
							 floats_[yyattribute(7 - 8)]);
	    
#line 323 "myparser.cpp"
			}
		}
		break;
	case 8:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[17];
			yyinitdebug((void YYFAR**)yya, 17);
#endif
			{
#line 206 "myparser.y"

		Action_Parser::action = new NormalBivariatesAction(floats_[yyattribute(7 - 16)],
								   vars_[yyattribute(1 - 16)],
								   floats_[yyattribute(9 - 16)],
								   floats_[yyattribute(11 - 16)],
								   vars_[yyattribute(3 - 16)],
								   floats_[yyattribute(13 - 16)],
								   floats_[yyattribute(15 - 16)]);
	    
#line 344 "myparser.cpp"
			}
		}
		break;
	case 9:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 217 "myparser.y"

		    allow_T_var_ = false;
		    lexer.leading_minus(false);
		
#line 360 "myparser.cpp"
			}
		}
		break;
	case 10:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 222 "myparser.y"

		    Action_Parser::action = new
				    AssignFromEquationAction(vars_[yyattribute(1 - 4)],
							     command_sequence);
		
#line 377 "myparser.cpp"
			}
		}
		break;
	case 11:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 233 "myparser.y"
 put_command(Command_Integer, lexer.token_int_value()); 
#line 390 "myparser.cpp"
			}
		}
		break;
	case 12:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 235 "myparser.y"
 put_command(Command_Float, lexer.token_float_value()); 
#line 403 "myparser.cpp"
			}
		}
		break;
	case 13:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 239 "myparser.y"
 put_command(Command_Var, lexer.token()); 
#line 416 "myparser.cpp"
			}
		}
		break;
	case 14:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 241 "myparser.y"

		    if (allow_T_var_)
			put_command(Command_T);
		    else
			Action_Parser::error("\"t\" cannot be used in"
					     " an assignment expression");
		
#line 435 "myparser.cpp"
			}
		}
		break;
	case 15:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 249 "myparser.y"
 put_command(Command_Negate); 
#line 448 "myparser.cpp"
			}
		}
		break;
	case 16:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 251 "myparser.y"
 put_command(Command_Add); 
#line 461 "myparser.cpp"
			}
		}
		break;
	case 17:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 253 "myparser.y"
 put_command(Command_Subtract); 
#line 474 "myparser.cpp"
			}
		}
		break;
	case 18:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 255 "myparser.y"
 put_command(Command_Multiply); 
#line 487 "myparser.cpp"
			}
		}
		break;
	case 19:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 257 "myparser.y"
 put_command(Command_Divide); 
#line 500 "myparser.cpp"
			}
		}
		break;
	case 20:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 259 "myparser.y"
 put_command(Command_Exponentation); 
#line 513 "myparser.cpp"
			}
		}
		break;
	case 21:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 265 "myparser.y"
 put_command(Command_Pi); 
#line 526 "myparser.cpp"
			}
		}
		break;
	case 22:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 267 "myparser.y"
 put_command(Command_E); 
#line 539 "myparser.cpp"
			}
		}
		break;
	case 23:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 277 "myparser.y"
 put_command(Command_Ln); 
#line 552 "myparser.cpp"
			}
		}
		break;
	case 24:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 282 "myparser.y"
 put_command(Command_Log10); 
#line 565 "myparser.cpp"
			}
		}
		break;
	case 25:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[11];
			yyinitdebug((void YYFAR**)yya, 11);
#endif
			{
#line 291 "myparser.y"

		Action_Parser::action = new RankCorrelateAction(vars_[yyattribute(3 - 10)],
								vars_[yyattribute(5 - 10)],
								floats_[yyattribute(7 - 10)],
								yyattribute(9 - 10));
	    
#line 583 "myparser.cpp"
			}
		}
		break;
	case 26:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 301 "myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = 2; 
#line 596 "myparser.cpp"
			}
		}
		break;
	case 27:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 303 "myparser.y"
 (*(YYSTYPE YYFAR*)yyvalptr) = 1; 
#line 609 "myparser.cpp"
			}
		}
		break;
	case 28:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 310 "myparser.y"

		Action_Parser::action = new StandardDeviationAction(vars_[yyattribute(3 - 4)]);
	    
#line 624 "myparser.cpp"
			}
		}
		break;
	case 29:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 315 "myparser.y"

		Action_Parser::action = new MeanAction(vars_[yyattribute(3 - 4)]);
	    
#line 639 "myparser.cpp"
			}
		}
		break;
	case 30:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 321 "myparser.y"

		Action_Parser::action = new MedianAction(vars_[yyattribute(3 - 4)]);
	    
#line 654 "myparser.cpp"
			}
		}
		break;
	case 31:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[7];
			yyinitdebug((void YYFAR**)yya, 7);
#endif
			{
#line 327 "myparser.y"

		Action_Parser::action = new CorrelationAction(vars_[yyattribute(3 - 6)],
							      vars_[yyattribute(5 - 6)]);
	    
#line 670 "myparser.cpp"
			}
		}
		break;
	case 32:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[7];
			yyinitdebug((void YYFAR**)yya, 7);
#endif
			{
#line 334 "myparser.y"

		Action_Parser::action = new RankCorrelationAction(vars_[yyattribute(3 - 6)],
								  vars_[yyattribute(5 - 6)]);
	    
#line 686 "myparser.cpp"
			}
		}
		break;
	case 33:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[7];
			yyinitdebug((void YYFAR**)yya, 7);
#endif
			{
#line 342 "myparser.y"

		Action_Parser::action = new PercentileBoundsAction(vars_[yyattribute(3 - 6)],
								   floats_[yyattribute(5 - 6)]);
	    
#line 702 "myparser.cpp"
			}
		}
		break;
	case 34:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 352 "myparser.y"

		filename_ = lexer.token();
	    
#line 717 "myparser.cpp"
			}
		}
		break;
	case 35:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 359 "myparser.y"

		    allow_T_var_ = true;
		    lexer.leading_minus(false);
		
#line 733 "myparser.cpp"
			}
		}
		break;
	case 36:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 364 "myparser.y"

		    lexer.leading_minus(true);
		
#line 748 "myparser.cpp"
			}
		}
		break;
	case 37:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[15];
			yyinitdebug((void YYFAR**)yya, 15);
#endif
			{
#line 370 "myparser.y"

		Action_Parser::action = new RegressionAction(filename_,
							     command_sequence,
							     floats_[yyattribute(7 - 14)],
							     floats_[yyattribute(9 - 14)],
							     yyattribute(11 - 14));
	    
#line 767 "myparser.cpp"
			}
		}
		break;
	case 38:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 379 "myparser.y"

		    allow_T_var_ = true;
		    lexer.leading_minus(false);
		
#line 783 "myparser.cpp"
			}
		}
		break;
	case 39:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 384 "myparser.y"

		    lexer.leading_minus(true);
		
#line 798 "myparser.cpp"
			}
		}
		break;
	case 40:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[17];
			yyinitdebug((void YYFAR**)yya, 17);
#endif
			{
#line 391 "myparser.y"

		Action_Parser::action = new RegressionPercentilesAction(
							    filename_,
							    command_sequence,
							    floats_[yyattribute(7 - 16)],
							    floats_[yyattribute(9 - 16)],
							    yyattribute(11 - 16),
							    percentiles_);
	    
#line 819 "myparser.cpp"
			}
		}
		break;
	case 41:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 408 "myparser.y"

		percentiles_.push_back(floats_[yyattribute(1 - 1)]);
		floats_.pop_back();
	    
#line 835 "myparser.cpp"
			}
		}
		break;
	case 42:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[8];
			yyinitdebug((void YYFAR**)yya, 8);
#endif
			{
#line 424 "myparser.y"

		Action_Parser::action = new ValsToCSVAction(filename_,
							    vars_);
	    
#line 851 "myparser.cpp"
			}
		}
		break;
	case 43:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[11];
			yyinitdebug((void YYFAR**)yya, 11);
#endif
			{
#line 432 "myparser.y"

		Action_Parser::action = new HistogramAction(filename_,
							    vars_[yyattribute(3 - 10)],
							    yyattribute(5 - 10),
							    floats_[yyattribute(7 - 10)]);
	    
#line 869 "myparser.cpp"
			}
		}
		break;
	default:
		yyassert(0);
		break;
	}
}

void YYPARSERNAME::yytables()
{
	yyattribute_size = sizeof(YYSTYPE);
	yysstack_size = YYSTACK_SIZE;
	yystack_max = YYSTACK_MAX;

#ifdef YYDEBUG
	static const yysymbol_t YYNEARFAR YYBASED_CODE symbol[] = {
		{ "$end", 0 },
		{ "error", 256 },
		{ "TOKEN_VAR_NAME", 257 },
		{ "TOKEN_TRIANGULAR", 258 },
		{ "TOKEN_UNIFORM", 259 },
		{ "TOKEN_NORMAL", 260 },
		{ "TOKEN_NEG_EXPONENTIAL", 261 },
		{ "TOKEN_NORMAL_BIVARIATES", 262 },
		{ "TOKEN_COMMA", 263 },
		{ "TOKEN_LEFT_PAREN", 264 },
		{ "TOKEN_RIGHT_PAREN", 265 },
		{ "TOKEN_EQUAL", 266 },
		{ "TOKEN_PLUS", 267 },
		{ "TOKEN_MINUS", 268 },
		{ "TOKEN_STAR", 269 },
		{ "TOKEN_SLASH", 270 },
		{ "TOKEN_CARET", 271 },
		{ "UNARY_MINUS", 272 },
		{ "TOKEN_INTEGER", 273 },
		{ "TOKEN_FLOAT", 274 },
		{ "TOKEN_PI", 275 },
		{ "TOKEN_E", 276 },
		{ "TOKEN_T", 277 },
		{ "TOKEN_LN", 278 },
		{ "TOKEN_LOG10", 279 },
		{ "TOKEN_RANK_CORRELATE", 280 },
		{ "TOKEN_GROW", 281 },
		{ "TOKEN_DECAY", 282 },
		{ "TOKEN_STD_DEVIATION", 283 },
		{ "TOKEN_MEAN", 284 },
		{ "TOKEN_MEDIAN", 285 },
		{ "TOKEN_CORRELATION", 286 },
		{ "TOKEN_RANK_CORRELATION", 287 },
		{ "TOKEN_PERCENTILE_BOUNDS", 288 },
		{ "TOKEN_REGRESSION", 289 },
		{ "TOKEN_REGRESSION_PERCENTILES", 290 },
		{ "TOKEN_STRING", 291 },
		{ "TOKEN_VALS_TO_CSV", 292 },
		{ "TOKEN_HISTOGRAMIZE", 293 },
		{ NULL, 0 }
	};
	yysymbol = symbol;

	static const char* const YYNEARFAR YYBASED_CODE rule[] = {
		"$accept: action",
		"action: variable_defn",
		"action: rank_correlate",
		"action: stats_query",
		"action: regression",
		"action: output",
		"var_name: TOKEN_VAR_NAME",
		"integer: TOKEN_INTEGER",
		"number: integer",
		"number: TOKEN_FLOAT",
		"variable_defn: var_name TOKEN_EQUAL TOKEN_TRIANGULAR TOKEN_LEFT_PAREN number TOKEN_COMMA number TOKEN_COMMA number TOKEN_RIGHT_PAREN",
		"variable_defn: var_name TOKEN_EQUAL TOKEN_UNIFORM TOKEN_LEFT_PAREN number TOKEN_COMMA number TOKEN_RIGHT_PAREN",
		"variable_defn: var_name TOKEN_EQUAL TOKEN_NORMAL TOKEN_LEFT_PAREN number TOKEN_COMMA number TOKEN_RIGHT_PAREN",
		"variable_defn: var_name TOKEN_EQUAL TOKEN_NEG_EXPONENTIAL TOKEN_LEFT_PAREN number TOKEN_COMMA number TOKEN_RIGHT_PAREN",
		"variable_defn: var_name TOKEN_COMMA var_name TOKEN_EQUAL TOKEN_NORMAL_BIVARIATES TOKEN_LEFT_PAREN number TOKEN_COMMA number TOKEN_COMMA number TOKEN_COMMA number TOKEN_COMMA number TOKEN_RIGHT_PAREN",
		"$$1:",
		"variable_defn: var_name TOKEN_EQUAL $$1 expr",
		"expr: TOKEN_INTEGER",
		"expr: TOKEN_FLOAT",
		"expr: constant",
		"expr: function",
		"expr: TOKEN_VAR_NAME",
		"expr: TOKEN_T",
		"expr: TOKEN_MINUS expr",
		"expr: expr TOKEN_PLUS expr",
		"expr: expr TOKEN_MINUS expr",
		"expr: expr TOKEN_STAR expr",
		"expr: expr TOKEN_SLASH expr",
		"expr: expr TOKEN_CARET expr",
		"expr: TOKEN_LEFT_PAREN expr TOKEN_RIGHT_PAREN",
		"constant: TOKEN_PI",
		"constant: TOKEN_E",
		"function: ln_function",
		"function: log10_function",
		"ln_function: TOKEN_LN TOKEN_LEFT_PAREN expr TOKEN_RIGHT_PAREN",
		"log10_function: TOKEN_LOG10 TOKEN_LEFT_PAREN expr TOKEN_RIGHT_PAREN",
		"rank_correlate: TOKEN_RANK_CORRELATE TOKEN_LEFT_PAREN var_name TOKEN_COMMA var_name TOKEN_COMMA number TOKEN_COMMA grow_or_decay TOKEN_RIGHT_PAREN",
		"grow_or_decay: TOKEN_GROW",
		"grow_or_decay: TOKEN_DECAY",
		"stats_query: TOKEN_STD_DEVIATION TOKEN_LEFT_PAREN var_name TOKEN_RIGHT_PAREN",
		"stats_query: TOKEN_MEAN TOKEN_LEFT_PAREN var_name TOKEN_RIGHT_PAREN",
		"stats_query: TOKEN_MEDIAN TOKEN_LEFT_PAREN var_name TOKEN_RIGHT_PAREN",
		"stats_query: TOKEN_CORRELATION TOKEN_LEFT_PAREN var_name TOKEN_COMMA var_name TOKEN_RIGHT_PAREN",
		"stats_query: TOKEN_RANK_CORRELATION TOKEN_LEFT_PAREN var_name TOKEN_COMMA var_name TOKEN_RIGHT_PAREN",
		"stats_query: TOKEN_PERCENTILE_BOUNDS TOKEN_LEFT_PAREN var_name TOKEN_COMMA number TOKEN_RIGHT_PAREN",
		"filename: TOKEN_STRING",
		"$$2:",
		"$$3:",
		"regression: TOKEN_REGRESSION $$2 TOKEN_LEFT_PAREN expr $$3 TOKEN_COMMA number TOKEN_COMMA number TOKEN_COMMA integer TOKEN_COMMA filename TOKEN_RIGHT_PAREN",
		"$$4:",
		"$$5:",
		"regression: TOKEN_REGRESSION_PERCENTILES $$4 TOKEN_LEFT_PAREN expr $$5 TOKEN_COMMA number TOKEN_COMMA number TOKEN_COMMA integer TOKEN_COMMA percentiles TOKEN_COMMA filename TOKEN_RIGHT_PAREN",
		"percentiles: TOKEN_LEFT_PAREN percentile more_percentiles TOKEN_RIGHT_PAREN",
		"percentile: number",
		"more_percentiles:",
		"more_percentiles: TOKEN_COMMA percentile more_percentiles",
		"output: TOKEN_VALS_TO_CSV TOKEN_LEFT_PAREN var_name TOKEN_COMMA more_vars filename TOKEN_RIGHT_PAREN",
		"output: TOKEN_HISTOGRAMIZE TOKEN_LEFT_PAREN var_name TOKEN_COMMA integer TOKEN_COMMA number TOKEN_COMMA filename TOKEN_RIGHT_PAREN",
		"more_vars:",
		"more_vars: var_name TOKEN_COMMA more_vars"
	};
	yyrule = rule;
#endif

	static const yyreduction_t YYNEARFAR YYBASED_CODE reduction[] = {
		{ 0, 1, -1 },
		{ 1, 1, -1 },
		{ 1, 1, -1 },
		{ 1, 1, -1 },
		{ 1, 1, -1 },
		{ 1, 1, -1 },
		{ 2, 1, 0 },
		{ 3, 1, 1 },
		{ 4, 1, 2 },
		{ 4, 1, 3 },
		{ 5, 10, 4 },
		{ 5, 8, 5 },
		{ 5, 8, 6 },
		{ 5, 8, 7 },
		{ 5, 16, 8 },
		{ 6, 0, 9 },
		{ 5, 4, 10 },
		{ 7, 1, 11 },
		{ 7, 1, 12 },
		{ 7, 1, -1 },
		{ 7, 1, -1 },
		{ 7, 1, 13 },
		{ 7, 1, 14 },
		{ 7, 2, 15 },
		{ 7, 3, 16 },
		{ 7, 3, 17 },
		{ 7, 3, 18 },
		{ 7, 3, 19 },
		{ 7, 3, 20 },
		{ 7, 3, -1 },
		{ 8, 1, 21 },
		{ 8, 1, 22 },
		{ 9, 1, -1 },
		{ 9, 1, -1 },
		{ 10, 4, 23 },
		{ 11, 4, 24 },
		{ 12, 10, 25 },
		{ 13, 1, 26 },
		{ 13, 1, 27 },
		{ 14, 4, 28 },
		{ 14, 4, 29 },
		{ 14, 4, 30 },
		{ 14, 6, 31 },
		{ 14, 6, 32 },
		{ 14, 6, 33 },
		{ 15, 1, 34 },
		{ 17, 0, 35 },
		{ 18, 0, 36 },
		{ 16, 14, 37 },
		{ 19, 0, 38 },
		{ 20, 0, 39 },
		{ 16, 16, 40 },
		{ 21, 4, -1 },
		{ 22, 1, 41 },
		{ 23, 0, -1 },
		{ 23, 3, -1 },
		{ 24, 7, 42 },
		{ 24, 10, 43 },
		{ 25, 0, -1 },
		{ 25, 3, -1 }
	};
	yyreduction = reduction;

	yytokenaction_size = 135;

	static const yytokenaction_t YYNEARFAR YYBASED_CODE tokenaction[] = {
		{ 0, YYAT_SHIFT, 2 },
		{ 143, YYAT_SHIFT, 152 },
		{ 143, YYAT_SHIFT, 153 },
		{ 0, YYAT_SHIFT, 3 },
		{ 0, YYAT_SHIFT, 4 },
		{ 0, YYAT_SHIFT, 5 },
		{ 0, YYAT_SHIFT, 6 },
		{ 0, YYAT_SHIFT, 7 },
		{ 0, YYAT_SHIFT, 8 },
		{ 0, YYAT_SHIFT, 9 },
		{ 0, YYAT_SHIFT, 10 },
		{ 96, YYAT_SHIFT, 57 },
		{ 0, YYAT_SHIFT, 11 },
		{ 0, YYAT_SHIFT, 12 },
		{ 32, YYAT_SHIFT, 45 },
		{ 32, YYAT_SHIFT, 46 },
		{ 32, YYAT_SHIFT, 47 },
		{ 32, YYAT_SHIFT, 48 },
		{ 96, YYAT_SHIFT, 58 },
		{ 115, YYAT_SHIFT, 94 },
		{ 115, YYAT_SHIFT, 95 },
		{ 115, YYAT_SHIFT, 96 },
		{ 96, YYAT_SHIFT, 59 },
		{ 114, YYAT_SHIFT, 94 },
		{ 114, YYAT_SHIFT, 95 },
		{ 114, YYAT_SHIFT, 96 },
		{ 185, YYAT_SHIFT, 181 },
		{ 96, YYAT_SHIFT, 60 },
		{ 96, YYAT_SHIFT, 61 },
		{ 96, YYAT_SHIFT, 62 },
		{ 96, YYAT_SHIFT, 63 },
		{ 96, YYAT_SHIFT, 64 },
		{ 96, YYAT_SHIFT, 65 },
		{ 96, YYAT_SHIFT, 66 },
		{ 113, YYAT_SHIFT, 132 },
		{ 184, YYAT_SHIFT, 188 },
		{ 113, YYAT_SHIFT, 92 },
		{ 113, YYAT_SHIFT, 93 },
		{ 113, YYAT_SHIFT, 94 },
		{ 113, YYAT_SHIFT, 95 },
		{ 113, YYAT_SHIFT, 96 },
		{ 80, YYAT_SHIFT, 92 },
		{ 80, YYAT_SHIFT, 93 },
		{ 80, YYAT_SHIFT, 94 },
		{ 80, YYAT_SHIFT, 95 },
		{ 80, YYAT_SHIFT, 96 },
		{ 72, YYAT_SHIFT, 92 },
		{ 72, YYAT_SHIFT, 93 },
		{ 72, YYAT_SHIFT, 94 },
		{ 72, YYAT_SHIFT, 95 },
		{ 72, YYAT_SHIFT, 96 },
		{ 67, YYAT_SHIFT, 92 },
		{ 67, YYAT_SHIFT, 93 },
		{ 67, YYAT_SHIFT, 94 },
		{ 67, YYAT_SHIFT, 95 },
		{ 67, YYAT_SHIFT, 96 },
		{ 19, YYAT_SHIFT, 31 },
		{ 183, YYAT_SHIFT, 187 },
		{ 182, YYAT_SHIFT, 186 },
		{ 19, YYAT_SHIFT, 32 },
		{ 181, YYAT_SHIFT, 85 },
		{ 179, YYAT_SHIFT, 122 },
		{ 175, YYAT_SHIFT, 180 },
		{ 174, YYAT_SHIFT, 179 },
		{ 172, YYAT_SHIFT, 176 },
		{ 170, YYAT_SHIFT, 173 },
		{ 168, YYAT_SHIFT, 171 },
		{ 167, YYAT_SHIFT, 170 },
		{ 166, YYAT_SHIFT, 169 },
		{ 162, YYAT_SHIFT, 84 },
		{ 159, YYAT_SHIFT, 165 },
		{ 158, YYAT_SHIFT, 164 },
		{ 157, YYAT_SHIFT, 163 },
		{ 156, YYAT_SHIFT, 162 },
		{ 155, YYAT_SHIFT, 161 },
		{ 154, YYAT_SHIFT, 160 },
		{ 142, YYAT_SHIFT, 151 },
		{ 141, YYAT_SHIFT, 150 },
		{ 140, YYAT_SHIFT, 149 },
		{ 139, YYAT_SHIFT, 148 },
		{ 138, YYAT_SHIFT, 147 },
		{ 137, YYAT_SHIFT, 146 },
		{ 134, YYAT_SHIFT, 145 },
		{ 133, YYAT_SHIFT, 144 },
		{ 130, YYAT_SHIFT, 143 },
		{ 123, YYAT_SHIFT, 136 },
		{ 121, YYAT_SHIFT, 1 },
		{ 118, YYAT_SHIFT, 96 },
		{ 117, YYAT_SHIFT, 96 },
		{ 116, YYAT_SHIFT, 96 },
		{ 112, YYAT_SHIFT, 131 },
		{ 106, YYAT_SHIFT, 129 },
		{ 105, YYAT_SHIFT, 128 },
		{ 104, YYAT_SHIFT, 127 },
		{ 103, YYAT_SHIFT, 126 },
		{ 102, YYAT_SHIFT, 125 },
		{ 101, YYAT_SHIFT, 124 },
		{ 99, YYAT_SHIFT, 121 },
		{ 98, YYAT_SHIFT, 120 },
		{ 97, YYAT_SHIFT, 119 },
		{ 88, YYAT_SHIFT, 111 },
		{ 87, YYAT_SHIFT, 110 },
		{ 83, YYAT_SHIFT, 109 },
		{ 82, YYAT_SHIFT, 108 },
		{ 81, YYAT_SHIFT, 107 },
		{ 75, YYAT_SHIFT, 102 },
		{ 66, YYAT_SHIFT, 91 },
		{ 65, YYAT_SHIFT, 90 },
		{ 55, YYAT_SHIFT, 1 },
		{ 48, YYAT_SHIFT, 79 },
		{ 47, YYAT_SHIFT, 78 },
		{ 46, YYAT_SHIFT, 77 },
		{ 45, YYAT_SHIFT, 76 },
		{ 44, YYAT_SHIFT, 75 },
		{ 43, YYAT_SHIFT, 74 },
		{ 42, YYAT_SHIFT, 73 },
		{ 39, YYAT_SHIFT, 56 },
		{ 38, YYAT_SHIFT, 55 },
		{ 37, YYAT_SHIFT, 54 },
		{ 36, YYAT_SHIFT, 53 },
		{ 35, YYAT_SHIFT, 52 },
		{ 34, YYAT_SHIFT, 51 },
		{ 33, YYAT_SHIFT, 50 },
		{ 28, YYAT_SHIFT, 41 },
		{ 27, YYAT_SHIFT, 40 },
		{ 13, YYAT_ACCEPT, 0 },
		{ 12, YYAT_SHIFT, 30 },
		{ 11, YYAT_SHIFT, 29 },
		{ 8, YYAT_SHIFT, 26 },
		{ 7, YYAT_SHIFT, 25 },
		{ 6, YYAT_SHIFT, 24 },
		{ 5, YYAT_SHIFT, 23 },
		{ 4, YYAT_SHIFT, 22 },
		{ 3, YYAT_SHIFT, 21 },
		{ 2, YYAT_SHIFT, 20 }
	};
	yytokenaction = tokenaction;

	static const yystateaction_t YYNEARFAR YYBASED_CODE stateaction[] = {
		{ -280, 1, YYAT_DEFAULT, 55 },
		{ 0, 0, YYAT_REDUCE, 6 },
		{ -130, 1, YYAT_ERROR, 0 },
		{ -131, 1, YYAT_ERROR, 0 },
		{ -132, 1, YYAT_ERROR, 0 },
		{ -133, 1, YYAT_ERROR, 0 },
		{ -134, 1, YYAT_ERROR, 0 },
		{ -135, 1, YYAT_ERROR, 0 },
		{ -136, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 46 },
		{ 0, 0, YYAT_REDUCE, 49 },
		{ -137, 1, YYAT_ERROR, 0 },
		{ -138, 1, YYAT_ERROR, 0 },
		{ 125, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 1 },
		{ 0, 0, YYAT_REDUCE, 2 },
		{ 0, 0, YYAT_REDUCE, 3 },
		{ 0, 0, YYAT_REDUCE, 4 },
		{ 0, 0, YYAT_REDUCE, 5 },
		{ -207, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 55 },
		{ 0, 0, YYAT_DEFAULT, 55 },
		{ 0, 0, YYAT_DEFAULT, 55 },
		{ 0, 0, YYAT_DEFAULT, 55 },
		{ 0, 0, YYAT_DEFAULT, 55 },
		{ 0, 0, YYAT_DEFAULT, 55 },
		{ 0, 0, YYAT_DEFAULT, 55 },
		{ -140, 1, YYAT_ERROR, 0 },
		{ -141, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 55 },
		{ 0, 0, YYAT_DEFAULT, 55 },
		{ 0, 0, YYAT_DEFAULT, 55 },
		{ -244, 1, YYAT_REDUCE, 15 },
		{ -141, 1, YYAT_ERROR, 0 },
		{ -144, 1, YYAT_ERROR, 0 },
		{ -145, 1, YYAT_ERROR, 0 },
		{ -146, 1, YYAT_ERROR, 0 },
		{ -145, 1, YYAT_ERROR, 0 },
		{ -146, 1, YYAT_ERROR, 0 },
		{ -147, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 96 },
		{ 0, 0, YYAT_DEFAULT, 96 },
		{ -148, 1, YYAT_ERROR, 0 },
		{ -149, 1, YYAT_ERROR, 0 },
		{ -153, 1, YYAT_ERROR, 0 },
		{ -152, 1, YYAT_ERROR, 0 },
		{ -153, 1, YYAT_ERROR, 0 },
		{ -154, 1, YYAT_ERROR, 0 },
		{ -155, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 96 },
		{ 0, 0, YYAT_DEFAULT, 55 },
		{ 0, 0, YYAT_REDUCE, 39 },
		{ 0, 0, YYAT_REDUCE, 40 },
		{ 0, 0, YYAT_REDUCE, 41 },
		{ 0, 0, YYAT_DEFAULT, 55 },
		{ -149, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 181 },
		{ 0, 0, YYAT_REDUCE, 21 },
		{ 0, 0, YYAT_DEFAULT, 96 },
		{ 0, 0, YYAT_DEFAULT, 96 },
		{ 0, 0, YYAT_REDUCE, 17 },
		{ 0, 0, YYAT_REDUCE, 18 },
		{ 0, 0, YYAT_REDUCE, 30 },
		{ 0, 0, YYAT_REDUCE, 31 },
		{ 0, 0, YYAT_REDUCE, 22 },
		{ -157, 1, YYAT_ERROR, 0 },
		{ -158, 1, YYAT_ERROR, 0 },
		{ -216, 1, YYAT_REDUCE, 47 },
		{ 0, 0, YYAT_REDUCE, 19 },
		{ 0, 0, YYAT_REDUCE, 20 },
		{ 0, 0, YYAT_REDUCE, 32 },
		{ 0, 0, YYAT_REDUCE, 33 },
		{ -221, 1, YYAT_REDUCE, 50 },
		{ 0, 0, YYAT_DEFAULT, 121 },
		{ 0, 0, YYAT_DEFAULT, 162 },
		{ -157, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 181 },
		{ 0, 0, YYAT_DEFAULT, 181 },
		{ 0, 0, YYAT_DEFAULT, 181 },
		{ 0, 0, YYAT_DEFAULT, 181 },
		{ -226, 1, YYAT_REDUCE, 16 },
		{ -159, 1, YYAT_ERROR, 0 },
		{ -162, 1, YYAT_ERROR, 0 },
		{ -163, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 7 },
		{ 0, 0, YYAT_REDUCE, 9 },
		{ 0, 0, YYAT_REDUCE, 8 },
		{ -164, 1, YYAT_ERROR, 0 },
		{ -165, 1, YYAT_DEFAULT, 113 },
		{ 0, 0, YYAT_REDUCE, 23 },
		{ 0, 0, YYAT_DEFAULT, 96 },
		{ 0, 0, YYAT_DEFAULT, 96 },
		{ 0, 0, YYAT_DEFAULT, 96 },
		{ 0, 0, YYAT_DEFAULT, 96 },
		{ 0, 0, YYAT_DEFAULT, 96 },
		{ 0, 0, YYAT_DEFAULT, 96 },
		{ -246, 1, YYAT_ERROR, 0 },
		{ -164, 1, YYAT_ERROR, 0 },
		{ -165, 1, YYAT_ERROR, 0 },
		{ -166, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 179 },
		{ -167, 1, YYAT_ERROR, 0 },
		{ -169, 1, YYAT_ERROR, 0 },
		{ -169, 1, YYAT_ERROR, 0 },
		{ -170, 1, YYAT_ERROR, 0 },
		{ -171, 1, YYAT_ERROR, 0 },
		{ -172, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 181 },
		{ 0, 0, YYAT_REDUCE, 42 },
		{ 0, 0, YYAT_REDUCE, 43 },
		{ 0, 0, YYAT_REDUCE, 44 },
		{ 0, 0, YYAT_REDUCE, 29 },
		{ -175, 1, YYAT_DEFAULT, 113 },
		{ -231, 1, YYAT_ERROR, 0 },
		{ -246, 1, YYAT_REDUCE, 24 },
		{ -250, 1, YYAT_REDUCE, 25 },
		{ -182, 1, YYAT_REDUCE, 26 },
		{ -183, 1, YYAT_REDUCE, 27 },
		{ -184, 1, YYAT_REDUCE, 28 },
		{ 0, 0, YYAT_DEFAULT, 181 },
		{ 0, 0, YYAT_DEFAULT, 181 },
		{ -171, 1, YYAT_REDUCE, 58 },
		{ 0, 0, YYAT_REDUCE, 45 },
		{ -180, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 181 },
		{ 0, 0, YYAT_DEFAULT, 181 },
		{ 0, 0, YYAT_DEFAULT, 181 },
		{ 0, 0, YYAT_DEFAULT, 181 },
		{ 0, 0, YYAT_DEFAULT, 181 },
		{ 0, 0, YYAT_DEFAULT, 181 },
		{ -179, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 34 },
		{ 0, 0, YYAT_REDUCE, 35 },
		{ -180, 1, YYAT_ERROR, 0 },
		{ -181, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 59 },
		{ 0, 0, YYAT_REDUCE, 56 },
		{ -182, 1, YYAT_ERROR, 0 },
		{ -183, 1, YYAT_ERROR, 0 },
		{ -184, 1, YYAT_ERROR, 0 },
		{ -187, 1, YYAT_ERROR, 0 },
		{ -188, 1, YYAT_ERROR, 0 },
		{ -189, 1, YYAT_ERROR, 0 },
		{ -280, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 181 },
		{ 0, 0, YYAT_DEFAULT, 181 },
		{ 0, 0, YYAT_DEFAULT, 179 },
		{ 0, 0, YYAT_DEFAULT, 181 },
		{ 0, 0, YYAT_DEFAULT, 181 },
		{ 0, 0, YYAT_REDUCE, 11 },
		{ 0, 0, YYAT_REDUCE, 12 },
		{ 0, 0, YYAT_REDUCE, 13 },
		{ 0, 0, YYAT_REDUCE, 37 },
		{ 0, 0, YYAT_REDUCE, 38 },
		{ -190, 1, YYAT_ERROR, 0 },
		{ -189, 1, YYAT_ERROR, 0 },
		{ -190, 1, YYAT_ERROR, 0 },
		{ -193, 1, YYAT_ERROR, 0 },
		{ -192, 1, YYAT_ERROR, 0 },
		{ -195, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 36 },
		{ 0, 0, YYAT_DEFAULT, 162 },
		{ -204, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 57 },
		{ 0, 0, YYAT_DEFAULT, 181 },
		{ 0, 0, YYAT_REDUCE, 10 },
		{ -195, 1, YYAT_ERROR, 0 },
		{ -196, 1, YYAT_ERROR, 0 },
		{ -197, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 179 },
		{ -199, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 181 },
		{ -201, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 181 },
		{ -200, 1, YYAT_ERROR, 0 },
		{ -201, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 48 },
		{ 0, 0, YYAT_REDUCE, 53 },
		{ 0, 0, YYAT_DEFAULT, 185 },
		{ -230, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 181 },
		{ -214, 1, YYAT_DEFAULT, 162 },
		{ -207, 1, YYAT_ERROR, 0 },
		{ -208, 1, YYAT_ERROR, 0 },
		{ -230, 1, YYAT_ERROR, 0 },
		{ -237, 1, YYAT_REDUCE, 54 },
		{ 0, 0, YYAT_REDUCE, 52 },
		{ 0, 0, YYAT_REDUCE, 51 },
		{ 0, 0, YYAT_REDUCE, 14 },
		{ 0, 0, YYAT_REDUCE, 55 }
	};
	yystateaction = stateaction;

	yynontermgoto_size = 80;

	static const yynontermgoto_t YYNEARFAR YYBASED_CODE nontermgoto[] = {
		{ 0, 13 },
		{ 0, 19 },
		{ 121, 99 },
		{ 181, 177 },
		{ 0, 14 },
		{ 96, 118 },
		{ 96, 68 },
		{ 96, 69 },
		{ 96, 70 },
		{ 96, 71 },
		{ 185, 189 },
		{ 0, 15 },
		{ 179, 183 },
		{ 0, 16 },
		{ 178, 182 },
		{ 0, 17 },
		{ 180, 86 },
		{ 180, 184 },
		{ 173, 178 },
		{ 171, 175 },
		{ 170, 174 },
		{ 181, 185 },
		{ 169, 172 },
		{ 0, 18 },
		{ 164, 168 },
		{ 121, 135 },
		{ 162, 167 },
		{ 161, 166 },
		{ 148, 159 },
		{ 147, 158 },
		{ 146, 157 },
		{ 145, 156 },
		{ 144, 155 },
		{ 143, 154 },
		{ 129, 142 },
		{ 128, 141 },
		{ 127, 140 },
		{ 126, 139 },
		{ 125, 138 },
		{ 124, 137 },
		{ 120, 134 },
		{ 119, 133 },
		{ 107, 130 },
		{ 100, 123 },
		{ 95, 117 },
		{ 94, 116 },
		{ 93, 115 },
		{ 92, 114 },
		{ 91, 113 },
		{ 90, 112 },
		{ 79, 106 },
		{ 78, 105 },
		{ 77, 104 },
		{ 76, 103 },
		{ 74, 101 },
		{ 73, 100 },
		{ 72, 98 },
		{ 67, 97 },
		{ 59, 89 },
		{ 58, 88 },
		{ 56, 87 },
		{ 55, 83 },
		{ 54, 82 },
		{ 50, 81 },
		{ 49, 80 },
		{ 41, 72 },
		{ 40, 67 },
		{ 32, 49 },
		{ 31, 44 },
		{ 30, 43 },
		{ 29, 42 },
		{ 26, 39 },
		{ 25, 38 },
		{ 24, 37 },
		{ 23, 36 },
		{ 22, 35 },
		{ 21, 34 },
		{ 20, 33 },
		{ 10, 28 },
		{ 9, 27 }
	};
	yynontermgoto = nontermgoto;

	static const yystategoto_t YYNEARFAR YYBASED_CODE stategoto[] = {
		{ -1, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 62, -1 },
		{ 59, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 75, -1 },
		{ 74, -1 },
		{ 73, -1 },
		{ 72, -1 },
		{ 71, -1 },
		{ 70, -1 },
		{ 69, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 68, -1 },
		{ 67, -1 },
		{ 66, -1 },
		{ 61, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 59, 96 },
		{ 58, 96 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 57, 96 },
		{ 61, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 60, -1 },
		{ 59, -1 },
		{ 56, 180 },
		{ 0, -1 },
		{ 52, 96 },
		{ 51, 96 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 39, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 36, -1 },
		{ 30, 121 },
		{ 51, -1 },
		{ 0, -1 },
		{ 49, 180 },
		{ 48, 180 },
		{ 47, 180 },
		{ 46, 180 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 42, 96 },
		{ 41, 96 },
		{ 40, 96 },
		{ 39, 96 },
		{ 38, 96 },
		{ 37, 96 },
		{ -2, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 28, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 38, 180 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 37, 180 },
		{ 36, 180 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 35, 180 },
		{ 34, 180 },
		{ 33, 180 },
		{ 32, 180 },
		{ 31, 180 },
		{ 30, 180 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 20, -1 },
		{ 28, 180 },
		{ 27, 180 },
		{ 15, -1 },
		{ 25, 180 },
		{ 24, 180 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 24, -1 },
		{ 23, -1 },
		{ 0, -1 },
		{ 20, 180 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 7, -1 },
		{ -1, -1 },
		{ 15, 180 },
		{ 0, -1 },
		{ -4, 181 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -9, -1 },
		{ -3, -1 },
		{ 13, -1 },
		{ -1, 180 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -13, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 }
	};
	yystategoto = stategoto;

	yydestructorptr = NULL;

	yytokendestptr = NULL;
	yytokendest_size = 0;

	yytokendestbaseptr = NULL;
	yytokendestbase_size = 0;
}
#line 445 "myparser.y"


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

