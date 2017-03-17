// TriangularAction.cpp: implementation of the TriangularAction class.
//
//////////////////////////////////////////////////////////////////////
#include "pragmas.h"

#include "TriangularAction.h"


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

TriangularAction::TriangularAction(std::string		varName, 
								   double			low, 
								   double			mode, 
								   double			high)
{
	_varName = varName;
	_low = low;
	_mode = mode;
	_high = high;
}

TriangularAction::~TriangularAction()
{

}

std::string TriangularAction::performAction(ComputationEngine& compEng)
{
	compEng.triangular(_varName, _low, _mode, _high);
	std::ostringstream ostr;
	ostr <<"Created triangular parameter \"" << _varName 
		 << "\" \nwith lower bound " << _low << " mode "
		 << _mode << " and upper bound " << _high << ".\n\n";
	return ostr.str();
}