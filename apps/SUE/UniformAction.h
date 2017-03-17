// UniformAction.h: interface for the UniformAction class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UNIFORMACTION_H__69577A88_4CFB_4E8B_899B_9E4CABB9413A__INCLUDED_)
#define AFX_UNIFORMACTION_H__69577A88_4CFB_4E8B_899B_9E4CABB9413A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Action.h"
#include <string>

class UniformAction : public Action  
{
public:
	UniformAction(std::string	varName, 
				  double		low, 
				  double		high);
	virtual ~UniformAction();
	std::string performAction(ComputationEngine& compEng);
private:
	std::string		_varName;
	double			_low;
	double			_high; 

};

#endif // !defined(AFX_UNIFORMACTION_H__69577A88_4CFB_4E8B_899B_9E4CABB9413A__INCLUDED_)
