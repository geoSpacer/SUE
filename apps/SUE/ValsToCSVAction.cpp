// ValsToCSVAction.cpp: implementation of the ValsToCSVAction class.
//
//////////////////////////////////////////////////////////////////////

#include "pragmas.h"

#include "ValsToCSVAction.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ValsToCSVAction::ValsToCSVAction(std::string				fileName, 
								 std::vector<std::string>&	varNames)
{
	_fileName = fileName;
	_varNames = varNames;
}

ValsToCSVAction::~ValsToCSVAction()
{

}

std::string ValsToCSVAction::performAction(ComputationEngine& compEng)
{
	std::ostringstream ostr;
	compEng.valsToCSV(_fileName, _varNames);
	ostr << ".CSV file \"" << _fileName 
		 << "\" created of parameters " 
		 << ToString::vectToString(_varNames) << ".\n\n";
	return ostr.str();
}