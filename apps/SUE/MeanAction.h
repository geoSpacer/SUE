// MeanAction.h: interface for the MeanAction class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MEANACTION_H__27CCCB24_718F_47F2_BADE_06BC06129715__INCLUDED_)
#define AFX_MEANACTION_H__27CCCB24_718F_47F2_BADE_06BC06129715__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Action.h"

class MeanAction : public Action  
{
public:
	MeanAction(std::string	varName);
	virtual ~MeanAction();
	std::string performAction(ComputationEngine& compEng);
private:
	std::string	_varName;
};

#endif // !defined(AFX_MEANACTION_H__27CCCB24_718F_47F2_BADE_06BC06129715__INCLUDED_)
