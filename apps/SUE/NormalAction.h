// NormalAction.h: interface for the NormalAction class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NORMALACTION_H__5BCA5401_A5DD_444A_ADC7_893D1C6E5BE1__INCLUDED_)
#define AFX_NORMALACTION_H__5BCA5401_A5DD_444A_ADC7_893D1C6E5BE1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
#include "Action.h"

class NormalAction : public Action  
{
public:
	NormalAction(std::string	varName, 
				 double			mean, 
				 double			stdDev);
	virtual ~NormalAction();
	std::string performAction(ComputationEngine& compEng); 
private:
	std::string		_varName;
	double			_mean;
	double			_stdDev; 
};

#endif // !defined(AFX_NORMALACTION_H__5BCA5401_A5DD_444A_ADC7_893D1C6E5BE1__INCLUDED_)
