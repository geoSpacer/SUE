// Action.cpp: implementation of the Action class.
//
//////////////////////////////////////////////////////////////////////
#include "pragmas.h"
#include "Action.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Action::Action()
{

}

Action::~Action()
{

}

std::string Action::performAction(ComputationEngine& compEng)
{
	std::ostringstream ostr;
	ostr << "Program Error - abstract base class instantiated and used.\n";
	return ostr.str();
}
