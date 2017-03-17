// MedianAction.h: interface for the MedianAction class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MEDIANACTION_H__11D2A6A6_058C_47B6_AA0E_DE5A36DB29C0__INCLUDED_)
#define AFX_MEDIANACTION_H__11D2A6A6_058C_47B6_AA0E_DE5A36DB29C0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
#include "Action.h"

class MedianAction : public Action  
{
public:
	MedianAction(std::string	varName);
	virtual ~MedianAction();
	std::string performAction(ComputationEngine& compEng);
private:
	std::string	_varName;
};

#endif // !defined(AFX_MEDIANACTION_H__11D2A6A6_058C_47B6_AA0E_DE5A36DB29C0__INCLUDED_)
