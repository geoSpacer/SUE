// RegressionAction.cpp: implementation of the RegressionAction class.
//
//////////////////////////////////////////////////////////////////////

#include "pragmas.h"

#include "RegressionAction.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

RegressionAction::RegressionAction(std::string		fileName,
								   Command_Sequence	commands,
								   double			freeVarLowBound,
								   double			freeVarHighBound,
								   double			steps)
{
	_fileName = fileName;
	_commands = commands;
	_freeVarLowBound = freeVarLowBound;
	_freeVarHighBound = freeVarHighBound;
	_steps = steps;
}

RegressionAction::~RegressionAction()
{
}

std::string RegressionAction::performAction(ComputationEngine& compEng)
{
	std::ostringstream ostr;
	compEng.regression(_fileName, _commands, _freeVarLowBound, _freeVarHighBound, _steps);
	ostr << ".CSV regression file named \"" << _fileName 
		 << "\" created.\n\n";
	return ostr.str();
}


