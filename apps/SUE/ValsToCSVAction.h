// ValsToCSVAction.h: interface for the ValsToCSVAction class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VALSTOCSVACTION_H__FA4E295A_3EB3_4977_B648_5FC0D337FFC6__INCLUDED_)
#define AFX_VALSTOCSVACTION_H__FA4E295A_3EB3_4977_B648_5FC0D337FFC6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
#include <list>
#include "Action.h"

class ValsToCSVAction : public Action  
{
public:
	ValsToCSVAction(std::string					fileName, 
				    std::vector<std::string>&	varNames);
	virtual ~ValsToCSVAction();
	std::string performAction(ComputationEngine& compEng);
private:
	std::string					_fileName; 
	std::vector<std::string>	_varNames;
};

#endif // !defined(AFX_VALSTOCSVACTION_H__FA4E295A_3EB3_4977_B648_5FC0D337FFC6__INCLUDED_)
