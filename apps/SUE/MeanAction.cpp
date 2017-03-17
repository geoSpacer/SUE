// MeanAction.cpp: implementation of the MeanAction class.
//
//////////////////////////////////////////////////////////////////////

#include "pragmas.h"

#include "MeanAction.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MeanAction::MeanAction(std::string	varName)
{
	_varName = varName;
}

MeanAction::~MeanAction()
{

}

std::string MeanAction::performAction(ComputationEngine& compEng)
{
	std::ostringstream ostr;
	ostr << "\"" << _varName << "\" has a mean of "
		 << compEng.mean(_varName) << "\n\n";
	return ostr.str();
}