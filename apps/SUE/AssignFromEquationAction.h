// AssignFromEquationAction.h: interface for the AssignFromEquationAction class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ASSIGNFROMEQUATIONACTION_H__823E0A22_5E31_49FE_ADD0_E1C580DBBE9D__INCLUDED_)
#define AFX_ASSIGNFROMEQUATIONACTION_H__823E0A22_5E31_49FE_ADD0_E1C580DBBE9D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include<string>

#include "Command_Sequence.h"
#include "Action.h"

class AssignFromEquationAction : public Action  
{
public:
	AssignFromEquationAction(std::string		varName,
							 Command_Sequence	comSeq);
	virtual ~AssignFromEquationAction();
	std::string performAction(ComputationEngine& compEng); 
private:
	std::string		_varName;
	Command_Sequence	_comSeq; 
};

#endif // !defined(AFX_ASSIGNFROMEQUATIONACTION_H__823E0A22_5E31_49FE_ADD0_E1C580DBBE9D__INCLUDED_)
