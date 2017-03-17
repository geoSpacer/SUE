// RegressionPercentilesAction.cpp: implementation of the RegressionPercentilesAction class.
//
//////////////////////////////////////////////////////////////////////

#include "pragmas.h"

#include "RegressionPercentilesAction.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

RegressionPercentilesAction::RegressionPercentilesAction
								(std::string			fileName,
								 Command_Sequence		commands,
								 double					freeVarLowBound,
								 double					freeVarHighBound,
								 double					steps,
								 std::vector<double>	percentiles)
{
	_fileName = fileName;
	_commands = commands;
	_freeVarLowBound = freeVarLowBound;
	_freeVarHighBound = freeVarHighBound;
	_steps = steps;
	_percentiles = percentiles;
}

RegressionPercentilesAction::~RegressionPercentilesAction()
{

}

std::string RegressionPercentilesAction::performAction(ComputationEngine& compEng)
{
	std::ostringstream ostr;
	compEng.regressionPercentiles(_fileName, _commands, 
								  _freeVarLowBound, _freeVarHighBound, 
								  _steps, _percentiles);
	ostr << ".CSV regression percentiles file named \"" << _fileName 
		 << "\" created \nwith percentiles " 
		 << ToString::vectToString(_percentiles) << ".\n\n";
	return ostr.str();
}
