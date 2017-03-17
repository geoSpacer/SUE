// orrelationAction.cpp: implementation of the CorrelationAction class.
//
//////////////////////////////////////////////////////////////////////

#include "pragmas.h"

#include "CorrelationAction.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CorrelationAction::CorrelationAction(std::string	var1Name,
									 std::string	var2Name)
{
	_var1Name = var1Name;
	_var2Name = var2Name;
}

CorrelationAction::~CorrelationAction()
{

}

std::string CorrelationAction::performAction(ComputationEngine& compEng)
{
	std::ostringstream ostr;
	ostr << "\"" << _var1Name 
		 << "\" and \"" << _var2Name 
		 << "\" have a correlation coefficient of "
		 << compEng.correlation(_var1Name, _var2Name)
		 << ".\n\n";
	return ostr.str();
}