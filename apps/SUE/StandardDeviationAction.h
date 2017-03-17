// StandardDeviationAction.h: interface for the StandardDeviationAction class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STANDARDDEVIATIONACTION_H__6079EDCA_8237_4A86_982F_4ED1659D97C2__INCLUDED_)
#define AFX_STANDARDDEVIATIONACTION_H__6079EDCA_8237_4A86_982F_4ED1659D97C2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
#include "Action.h"

class StandardDeviationAction : public Action  
{
public:
	StandardDeviationAction(std::string	varName);
	virtual ~StandardDeviationAction();
	std::string performAction(ComputationEngine& compEng); 
private:
	std::string	_varName;
};

#endif // !defined(AFX_STANDARDDEVIATIONACTION_H__6079EDCA_8237_4A86_982F_4ED1659D97C2__INCLUDED_)
