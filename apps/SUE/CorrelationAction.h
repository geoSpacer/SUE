// orrelationAction.h: interface for the CorrelationAction class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CORRELATIONACTION_H__A8902DC7_D1CB_48C1_86C1_7830E2F0EC65__INCLUDED_)
#define AFX_CORRELATIONACTION_H__A8902DC7_D1CB_48C1_86C1_7830E2F0EC65__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
#include "Action.h"

class CorrelationAction : public Action  
{
public:
	CorrelationAction(std::string	var1Name,
					  std::string	var2Name);
	virtual ~CorrelationAction();
	std::string performAction(ComputationEngine& compEng);
private:
	std::string	_var1Name;
	std::string	_var2Name;
};

#endif // !defined(AFX_CORRELATIONACTION_H__A8902DC7_D1CB_48C1_86C1_7830E2F0EC65__INCLUDED_)
