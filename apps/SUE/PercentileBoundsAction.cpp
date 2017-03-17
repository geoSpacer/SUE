// PercentileBoundsAction.cpp: implementation of the PercentileBoundsAction class.
//
//////////////////////////////////////////////////////////////////////

#include "pragmas.h"

#include "PercentileBoundsAction.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PercentileBoundsAction::PercentileBoundsAction(std::string	varName,
											   double		percentile)
{
	_varName = varName;
	_percentile = percentile;
}

PercentileBoundsAction::~PercentileBoundsAction()
{

}

std::string PercentileBoundsAction::performAction(ComputationEngine& compEng)
{
	std::ostringstream ostr;
	ostr << "The middle " << _percentile << "% of "	
		 << "\"" << _varName << "\" is enclosed by ";
	double low, high;
	compEng.percentileBounds(_varName, _percentile, low, high);
	ostr << low << " and " << high << ".\n\n";
	return ostr.str();
}


