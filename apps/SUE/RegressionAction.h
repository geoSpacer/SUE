// RegressionAction.h: interface for the RegressionAction class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_REGRESSIONACTION_H__F0D7FCC4_17AB_4C8C_A116_FEED388587D5__INCLUDED_)
#define AFX_REGRESSIONACTION_H__F0D7FCC4_17AB_4C8C_A116_FEED388587D5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include<string>

#include "Command_Sequence.h"
#include "Action.h"

class RegressionAction : public Action  
{
public:
	RegressionAction(std::string		fileName,
					 Command_Sequence	commands,
					 double				freeVarLowBound,
					 double				freeVarHighBound,
					 double				steps);
	virtual ~RegressionAction();
	std::string performAction(ComputationEngine& compEng);
private:
	std::string			_fileName; 
	Command_Sequence	_commands;
	double				_freeVarLowBound;
	double				_freeVarHighBound;
	double				_steps;
};

#endif // !defined(AFX_REGRESSIONACTION_H__F0D7FCC4_17AB_4C8C_A116_FEED388587D5__INCLUDED_)
