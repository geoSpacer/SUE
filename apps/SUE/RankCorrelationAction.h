// RankCorrelationAction.h: interface for the RankCorrelationAction class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RANKCORRELATIONACTION_H__9E93986D_7998_4235_A688_0E545F715E7A__INCLUDED_)
#define AFX_RANKCORRELATIONACTION_H__9E93986D_7998_4235_A688_0E545F715E7A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
#include "Action.h"

class RankCorrelationAction : public Action  
{
public:
	RankCorrelationAction(std::string	var1Name,
					      std::string	var2Name);
	virtual ~RankCorrelationAction();
	std::string performAction(ComputationEngine& compEng);
private:
	std::string	_var1Name;
	std::string	_var2Name;
};

#endif // !defined(AFX_RANKCORRELATIONACTION_H__9E93986D_7998_4235_A688_0E545F715E7A__INCLUDED_)
