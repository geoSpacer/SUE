// RankCorrelateAction.h: interface for the RankCorrelateAction class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RANKCORRELATEACTION_H__97ADF19D_D6C2_429A_B401_A94F47B837D1__INCLUDED_)
#define AFX_RANKCORRELATEACTION_H__97ADF19D_D6C2_429A_B401_A94F47B837D1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
#include "Action.h"

class RankCorrelateAction : public Action  
{
public:
	RankCorrelateAction(std::string	var1Name,
						std::string	var2Name,
						double		requestedRankCor,
						int			method = 1);
		// method 1 = decay
		// method 2 = grow
	virtual ~RankCorrelateAction();
	std::string performAction(ComputationEngine& compEng); 
private:
	std::string	_var1Name;
	std::string	_var2Name;
	double		_requestedRankCor;
	int			_method;
};

#endif // !defined(AFX_RANKCORRELATEACTION_H__97ADF19D_D6C2_429A_B401_A94F47B837D1__INCLUDED_)
