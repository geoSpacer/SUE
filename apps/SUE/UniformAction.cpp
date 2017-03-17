// UniformAction.cpp: implementation of the UniformAction class.
//
//////////////////////////////////////////////////////////////////////
#include "pragmas.h"

#include "UniformAction.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

UniformAction::UniformAction(std::string		varName, 
							 double				low, 
							 double				high)
{
	_varName = varName;
	_low = low;
	_high = high;
}

UniformAction::~UniformAction()
{

}

std::string UniformAction::performAction(ComputationEngine& compEng)
{
	compEng.uniform(_varName, _low, _high);
	std::ostringstream ostr;
	ostr <<"Created uniform parameter \"" << _varName 
		 << "\" \nwith lower bound " << _low 
		 << " and upper bound " << _high << ".\n\n";
	return ostr.str();
}