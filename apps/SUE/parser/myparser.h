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
* myparser.h
* C++ header file generated from myparser.y.
* 
* Date: 03/12/03
* Time: 16:02:48
* 
* AYACC Version: 1.97 (Beta Release)
****************************************************************************/

#ifndef _MYPARSER_H
#define _MYPARSER_H

#include <cyacc.h>

#line 24 "myparser.y"

#include <vector>
#include <string>

#line 38 "myparser.h"
/////////////////////////////////////////////////////////////////////////////
// myparser

#ifndef YYEXPPARSER
#define YYEXPPARSER
#endif

class YYEXPPARSER YYFAR myparser : public _YL yyfparser {
public:
	myparser();
	virtual ~myparser();

protected:
	void yytables();
	virtual void yyaction(int action);
#ifdef YYDEBUG
	void YYFAR* yyattribute1(int index) const;
	void yyinitdebug(void YYFAR** p, int count) const;
#endif

	// attribute functions
	virtual void yystacktoval(int index);
	virtual void yyvaltostack(int index);
	virtual void yylvaltoval();
	virtual void yyvaltolval();
	virtual void yylvaltostack(int index);

	virtual void YYFAR* yynewattribute(int count);
	virtual void yydeleteattribute(void YYFAR* attribute);
	virtual void yycopyattribute(void YYFAR* dest, const void YYFAR* src, int count);

public:
#line 33 "myparser.y"

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

#line 96 "myparser.h"
};

#ifndef YYPARSERNAME
#define YYPARSERNAME myparser
#endif

#define TOKEN_VAR_NAME 257
#define TOKEN_TRIANGULAR 258
#define TOKEN_UNIFORM 259
#define TOKEN_NORMAL 260
#define TOKEN_NEG_EXPONENTIAL 261
#define TOKEN_NORMAL_BIVARIATES 262
#define TOKEN_COMMA 263
#define TOKEN_LEFT_PAREN 264
#define TOKEN_RIGHT_PAREN 265
#define TOKEN_EQUAL 266
#define TOKEN_PLUS 267
#define TOKEN_MINUS 268
#define TOKEN_STAR 269
#define TOKEN_SLASH 270
#define TOKEN_CARET 271
#define UNARY_MINUS 272
#define TOKEN_INTEGER 273
#define TOKEN_FLOAT 274
#define TOKEN_PI 275
#define TOKEN_E 276
#define TOKEN_T 277
#define TOKEN_LN 278
#define TOKEN_LOG10 279
#define TOKEN_RANK_CORRELATE 280
#define TOKEN_GROW 281
#define TOKEN_DECAY 282
#define TOKEN_STD_DEVIATION 283
#define TOKEN_MEAN 284
#define TOKEN_MEDIAN 285
#define TOKEN_CORRELATION 286
#define TOKEN_RANK_CORRELATION 287
#define TOKEN_PERCENTILE_BOUNDS 288
#define TOKEN_REGRESSION 289
#define TOKEN_REGRESSION_PERCENTILES 290
#define TOKEN_STRING 291
#define TOKEN_VALS_TO_CSV 292
#define TOKEN_HISTOGRAMIZE 293
#endif
