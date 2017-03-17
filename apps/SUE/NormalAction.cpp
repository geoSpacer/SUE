// NormalAction.cpp: implementation of the NormalAction class.
//
//////////////////////////////////////////////////////////////////////

#include "pragmas.h"

#include "NormalAction.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

NormalAction::NormalAction(std::string		varName, 
						   double			mean, 
						   double			stdDev)
{
	_varName = varName;
	_mean = mean;
	_stdDev = stdDev;
}

NormalAction::~NormalAction()
{

}

std::string NormalAction::performAction(ComputationEngine& compEng)
{
	compEng.normal(_varName, _mean, _stdDev);
	std::ostringstream ostr;
	ostr <<"Created normal parameter \"" << _varName 
		 << "\" \nwith mode "
		 << _mean << " and standard deviation " << _stdDev << ".\n\n";
	return ostr.str();
}