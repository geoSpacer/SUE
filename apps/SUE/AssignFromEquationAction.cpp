// AssignFromEquationAction.cpp: implementation of the AssignFromEquationAction class.
//
//////////////////////////////////////////////////////////////////////
#include "pragmas.h"

#include "AssignFromEquationAction.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

AssignFromEquationAction::AssignFromEquationAction(std::string		varName,
												   Command_Sequence	comSeq)
{
	_varName = varName;
	_comSeq = comSeq;
}

AssignFromEquationAction::~AssignFromEquationAction()
{

}

std::string AssignFromEquationAction::performAction(ComputationEngine& compEng)
{
	compEng.assignFromEquation(_varName, _comSeq);
	std::ostringstream ostr;
	ostr <<"Created parameter \"" << _varName 
		 << "\" \nfrom an input equation.\n\n";
	return ostr.str();
}