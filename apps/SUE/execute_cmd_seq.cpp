#include "pragmas.h"

#include <vector>
#include <cmath>
#include <string>

#include "common/Error.h"
#include "common/equal.h"
#include "common/Int_Fmt.h"

#include "execute_cmd_seq.h"

//-----------------------------------------------------------------------------

double Command_Variables::T;


//-----------------------------------------------------------------------------

namespace
{
    const double pi = double(3.1415926535897932384626433832795);
    const double e  = double(2.7182818284590452353602874713527);

    //------------------------------------------------------------------------

    //	These functions are defined instead of using the <stack> standard
    //	header, since the standard pop() doesn't return a value.  In other
    //	words, using std::stack is awkward.

    template <class type>
    inline
    void push(type		  value,
	      std::vector<type> & stack)
	//  Pushes a value onto the stack.
    {
	stack.push_back(value);
    }

    //------------------------------------------------------------------------

    template <class type>
    inline
    type pop(std::vector<type> & stack)
	//  Pops a value off the stack.
    {
	type value = stack[stack.size() - 1];
	stack.pop_back();
	return value;
    }


};

//-----------------------------------------------------------------------------

double execute(const Command_Sequence &								cmd_seq,
			  std::map <std::string, std::vector<double> >&			sampleSpace,
			  int													index)
{
    if (cmd_seq.size() == 0)
	throw Error("Trying to execute an empty command sequence.");

    std::vector<double> num_stack;
	//  For evaluating numeric expressions.

    int	pos = 0;
	//  Current position in the sequence.

    double x, y;
	//  Used to perform commands for binary operators where the order of
	//  operands is important.

    int num_args;
	//  Used by the min and max commands.

    while (pos < cmd_seq.size()) {
	bool jumped = false;
	    //	Did the current command jump to a new position in the sequence?

	switch (cmd_seq[pos].code())
	{
	    //-------------------------
	    //  Constants and variables

	    case Command_Pi:
		push(pi, num_stack);
		break;

	    case Command_E:
		push(e, num_stack);
		break;

	    case Command_T:
		push(double(Command_Variables::T), num_stack);
		break;

	    case Command_Var:
			if(sampleSpace.count(cmd_seq[pos].str_value()) != 0)
			// this pushes the INDEX'th element of the parameter 
			// returned by var_name().
			push(double(sampleSpace[cmd_seq[pos].str_value()][index]),
				num_stack);
			else
				throw Error("Error: Var " + cmd_seq[pos].str_value() 
							 + " not found in map.");
		break;

	    //---------
	    //	Numbers

	    case Command_Integer:
		push(double(cmd_seq[pos].int_value()), num_stack);
		break;

	    case Command_Float:
		push(cmd_seq[pos].double_value(), num_stack);
		break;

	    //-------------------
	    //	Numeric operators

	    case Command_Negate:
		push(-pop(num_stack), num_stack);
		break;

	    case Command_Add:
		push(pop(num_stack) + pop(num_stack), num_stack);
		break;

	    case Command_Subtract:
		y = pop(num_stack);
		x = pop(num_stack);
		push(x - y, num_stack);
		break;

	    case Command_Multiply:
		push(pop(num_stack) * pop(num_stack), num_stack);
		break;

	    case Command_Divide:
		y = pop(num_stack);
		x = pop(num_stack);
		if(y==0)
			throw Error("Math Error: With the given parameter sample space and \n"
						+(std::string)"expression, division by zero occurred.\n");
		push(x / y, num_stack);
		break;

	    case Command_Exponentation:
		y = pop(num_stack);
		x = pop(num_stack);
		if(x < 0 && y != (int)y)
			throw Error("Math Error: With the given parameter sample space and\n"
						+(std::string)"expression, a fractional exponent of a negative number\n"
						+(std::string)"occurred.\n");
		push(double(pow(x, y)), num_stack);
		break;

	    //----------------------
	    //	Lograthmic functions

	    case Command_Ln:
		x = pop(num_stack);
		if(x<=0)
			throw Error("Math Error: With the given parameter sample space and\n"
						+(std::string)"expression, natural log of a number <= 0 occurred.\n");
		push(double(log(x)), num_stack);
		break;

	    case Command_Log10:
		x = pop(num_stack);
		if(x<=0)
			throw Error("Math Error: With the given parameter sample space and\n"
						+(std::string)"expression, log of a number <= 0 occurred.\n");
		push(double(log10(x)), num_stack);
		break;

	    //-----------------------
	    //	Min and Max functions

	    case Command_Max:
		for (num_args = cmd_seq[pos].int_value(); num_args > 1;
							  num_args--) {
		    x = pop(num_stack);
		    y = pop(num_stack);
		    push(x > y ? x : y, num_stack);
		}
		break;

	    case Command_Min:
		for (num_args = cmd_seq[pos].int_value(); num_args > 1;
							  num_args--) {
		    x = pop(num_stack);
		    y = pop(num_stack);
		    push(x < y ? x : y, num_stack);
		}
		break;


	    default:
		throw Error//("Unrecognized command in execute(command sequence).\n");
			
			
			("Unrecognized command: code = "
			    + Int_Fmt(1)(cmd_seq[pos].code())
			    + ", name = " + name(cmd_seq[pos].code()) );



	}   // switch

	if (! jumped)
	    pos++;
    }  // while

    return pop(num_stack);
}
