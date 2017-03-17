// RegressionPercentilesAction.h: interface for the RegressionPercentilesAction class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_REGRESSIONPERCENTILESACTION_H__F32CD09A_81CA_4049_8F07_E0C642D84051__INCLUDED_)
#define AFX_REGRESSIONPERCENTILESACTION_H__F32CD09A_81CA_4049_8F07_E0C642D84051__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
#include <vector>

#include "Command_Sequence.h"
#include "Action.h"

class RegressionPercentilesAction : public Action  
{
public:
	RegressionPercentilesAction(std::string			fileName,
								Command_Sequence	commands,
								double				freeVarLowBound,
								double				freeVarHighBound,
								double				steps,
								std::vector<double>	percentiles);
	virtual ~RegressionPercentilesAction();
	std::string performAction(ComputationEngine& compEng);
private:
	std::string			_fileName; 
	Command_Sequence	_commands;
	double				_freeVarLowBound;
	double				_freeVarHighBound;
	double				_steps;
	std::vector<double>	_percentiles;
};

#endif // !defined(AFX_REGRESSIONPERCENTILESACTION_H__F32CD09A_81CA_4049_8F07_E0C642D84051__INCLUDED_)
