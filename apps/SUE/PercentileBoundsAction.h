// PercentileBoundsAction.h: interface for the PercentileBoundsAction class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PERCENTILEBOUNDSACTION_H__30C7DA3A_7992_4A36_A5E0_C81FAB4FCC0E__INCLUDED_)
#define AFX_PERCENTILEBOUNDSACTION_H__30C7DA3A_7992_4A36_A5E0_C81FAB4FCC0E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
#include "Action.h"

class PercentileBoundsAction : public Action  
{
public:
	PercentileBoundsAction(std::string	varName,
						   double		percentile);
	virtual ~PercentileBoundsAction();
	std::string performAction(ComputationEngine& compEng);
private:
	std::string _varName;
	double		_percentile;
};

#endif // !defined(AFX_PERCENTILEBOUNDSACTION_H__30C7DA3A_7992_4A36_A5E0_C81FAB4FCC0E__INCLUDED_)
