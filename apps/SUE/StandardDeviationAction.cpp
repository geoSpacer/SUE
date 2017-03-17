// StandardDeviationAction.cpp: implementation of the StandardDeviationAction class.
//
//////////////////////////////////////////////////////////////////////

#include "pragmas.h"

#include "StandardDeviationAction.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

StandardDeviationAction::StandardDeviationAction(std::string	varName)
{
	_varName = varName;
}

StandardDeviationAction::~StandardDeviationAction()
{

}

std::string StandardDeviationAction::performAction(ComputationEngine& compEng)
{
	std::ostringstream ostr;
	ostr << "\"" << _varName 
		 << "\" has a standard deviation of " << compEng.standardDeviation(_varName)
		 << ".\n\n";
	return ostr.str();
}