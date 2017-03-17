// RankCorrelationAction.cpp: implementation of the RankCorrelationAction class.
//
//////////////////////////////////////////////////////////////////////

#include "pragmas.h"

#include "RankCorrelationAction.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

RankCorrelationAction::RankCorrelationAction(std::string	var1Name,
											 std::string	var2Name)
{
	_var1Name = var1Name;
	_var2Name = var2Name;
}


RankCorrelationAction::~RankCorrelationAction()
{

}

std::string RankCorrelationAction::performAction(ComputationEngine& compEng)
{
	std::ostringstream ostr;
	ostr << "\"" << _var1Name 
		 << "\" and \"" << _var2Name 
		 << "\" have a rank correlation coefficient of "
		 << compEng.rankCorrelation(_var1Name, _var2Name)
		 << ".\n\n";
	return ostr.str();
}