// TriangularAction.h: interface for the TriangularAction class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TRIANGULARACTION_H__79236D71_80E7_4B0F_B9DA_C9078E3DC7FA__INCLUDED_)
#define AFX_TRIANGULARACTION_H__79236D71_80E7_4B0F_B9DA_C9078E3DC7FA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Action.h"
#include <string>
#include <iostream>

class TriangularAction : public Action  
{
public:
	TriangularAction(std::string	varName, 
					 double			low, 
					 double			mode, 
					 double			high);
	virtual ~TriangularAction();
	std::string performAction(ComputationEngine& compEng);
private:
	std::string		_varName;
	double			_low;
	double			_mode; 
	double			_high;
};

#endif // !defined(AFX_TRIANGULARACTION_H__79236D71_80E7_4B0F_B9DA_C9078E3DC7FA__INCLUDED_)
