// NegExpAction.h: interface for the NegExpAction class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NEGEXPACTION_H__57275ADE_EAF5_44AC_8692_52D73618439B__INCLUDED_)
#define AFX_NEGEXPACTION_H__57275ADE_EAF5_44AC_8692_52D73618439B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Action.h"
#include <string>

class NegExpAction : public Action  
{
public:
	NegExpAction(std::string	varName, 
				 double			low, 
				 double			stdDev);
	virtual ~NegExpAction();
	std::string performAction(ComputationEngine& compEng); 
private:
	std::string		_varName;
	double			_low;
	double			_stdDev; 
};

#endif // !defined(AFX_NEGEXPACTION_H__57275ADE_EAF5_44AC_8692_52D73618439B__INCLUDED_)
