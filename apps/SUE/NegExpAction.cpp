// NegExpAction.cpp: implementation of the NegExpAction class.
//
//////////////////////////////////////////////////////////////////////

#include "pragmas.h"

#include "common/Error.h"

#include "NegExpAction.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

NegExpAction::NegExpAction(std::string		varName, 
						   double			low, 
						   double			stdDev)
{
	_varName = varName;
	_low = low;
	_stdDev = stdDev;
}

NegExpAction::~NegExpAction()
{

}

std::string NegExpAction::performAction(ComputationEngine& compEng)
{
	compEng.negExp(_varName, _low, _stdDev);
	std::ostringstream ostr;
	ostr <<"Created negative exponential parameter \"" << _varName 
		 << "\" \nwith lower bound " << _low 
		 << " and standard deviation " << _stdDev << ".\n\n";
	return ostr.str();
}