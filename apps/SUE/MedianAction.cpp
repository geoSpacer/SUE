// MedianAction.cpp: implementation of the MedianAction class.
//
//////////////////////////////////////////////////////////////////////

#include "pragmas.h"

#include "MedianAction.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MedianAction::MedianAction(std::string	varName)
{
	_varName = varName;
}

MedianAction::~MedianAction()
{

}

std::string MedianAction::performAction(ComputationEngine& compEng)
{
	std::ostringstream ostr;
	ostr << "\"" << _varName << "\" has a median of "
		 << compEng.median(_varName) << "\n\n";
	return ostr.str();
}