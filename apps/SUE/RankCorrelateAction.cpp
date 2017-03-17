// RankCorrelateAction.cpp: implementation of the RankCorrelateAction class.
//
//////////////////////////////////////////////////////////////////////

#include "pragmas.h"

#include "RankCorrelateAction.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

RankCorrelateAction::RankCorrelateAction(std::string	var1Name,
										 std::string	var2Name,
										 double			requestedRankCor,
										 int			method)
{
	_var1Name = var1Name;
	_var2Name = var2Name;
	_requestedRankCor = requestedRankCor;
	_method = method;
}

RankCorrelateAction::~RankCorrelateAction()
{

}

std::string RankCorrelateAction::performAction(ComputationEngine& compEng)
{
	compEng.rankCorrelate(_var1Name, _var2Name, _requestedRankCor, _method);
	std::ostringstream ostr;
	ostr << "Rank correlated parameters \"" << _var1Name 
		 << "\" and \"" << _var2Name << "\"\nwith ";
	if(_method == 1)
		 ostr << "\"decay\"";
	else	
		 ostr << "\"grow\"";
	ostr << " method, "
		 << "\naiming for rank correlation " << _requestedRankCor << ".\n\n";
	return ostr.str();
}