// NormalBivariatesAction.h: interface for the NormalBivariatesAction class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NORMALBIVARIATESACTION_H__5B3216A3_DFDE_42CA_9A49_4037AEABE501__INCLUDED_)
#define AFX_NORMALBIVARIATESACTION_H__5B3216A3_DFDE_42CA_9A49_4037AEABE501__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
#include "Action.h"

class NormalBivariatesAction : public Action  
{
public:
	NormalBivariatesAction(double		requestedCorr,
						   std::string	var1Name,
						   double		var1Mean,
						   double		var1StdDev,
						   std::string	var2Name,
						   double		var2Mean,
						   double		var2StdDev);
	virtual ~NormalBivariatesAction();
	std::string performAction(ComputationEngine& compEng);
private:
	double		_requestedCorr;
	std::string	_var1Name;
	double		_var1Mean;
	double		_var1StdDev;
	std::string	_var2Name;
	double		_var2Mean;
	double		_var2StdDev;
};

#endif // !defined(AFX_NORMALBIVARIATESACTION_H__5B3216A3_DFDE_42CA_9A49_4037AEABE501__INCLUDED_)
