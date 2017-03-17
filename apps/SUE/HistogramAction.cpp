// HistogramAction.cpp: implementation of the HistogramAction class.
//
//////////////////////////////////////////////////////////////////////

#include "pragmas.h"

#include "common/Error.h"

#include "HistogramAction.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

HistogramAction::HistogramAction(std::string	fileName,
								 std::string	var, 
								 double			boxes,
								 double			excludedTailPercent)
{
	_fileName = fileName;
	_var = var;
	_boxes = boxes;
	_excludedTailPercent = excludedTailPercent;
}

HistogramAction::~HistogramAction()
{

}

std::string HistogramAction::performAction(ComputationEngine& compEng)
{
	std::ostringstream ostr;
	compEng.histogram(_fileName, _var, _boxes, _excludedTailPercent);
	ostr << ".CSV histogram file named \"" << _fileName 
		 << "\" of \"" << _var << "\" created.\n\n";
	return ostr.str();
}