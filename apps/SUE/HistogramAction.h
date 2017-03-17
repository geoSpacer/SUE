// HistogramAction.h: interface for the HistogramAction class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HISTOGRAMACTION_H__9DCB74C1_6538_4434_A0AB_5B35CC59DF84__INCLUDED_)
#define AFX_HISTOGRAMACTION_H__9DCB74C1_6538_4434_A0AB_5B35CC59DF84__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
#include "Action.h"

class HistogramAction : public Action  
{
public:
	HistogramAction(std::string		fileName,
				    std::string		var, 
				    double			boxes,
				    double			excludedTailPercent = 0);
	virtual ~HistogramAction();
	std::string performAction(ComputationEngine& compEng);
private:
	std::string	_fileName;
	std::string	_var;
	double		_boxes;
	double		_excludedTailPercent;
};

#endif // !defined(AFX_HISTOGRAMACTION_H__9DCB74C1_6538_4434_A0AB_5B35CC59DF84__INCLUDED_)
