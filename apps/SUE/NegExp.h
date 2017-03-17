// NegExp.h: interface for the NegExp class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NEGEXP_H__83EE8934_4946_49B7_95D8_AE1B70E4DB72__INCLUDED_)
#define AFX_NEGEXP_H__83EE8934_4946_49B7_95D8_AE1B70E4DB72__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "distTyp.h"

class NegExp : public DistTyp  
{
public:
	NegExp(double	low, 
		   double	stdDev);
		// a true negative exponential distribution is entirely determined by its 
		// lower bound and standard deviation.  So that's all we need include
		// for the constructor.
	virtual ~NegExp();
private:
	double _low, _stdDev;
	double CDFInv(double p) const;
};

#endif // !defined(AFX_NEGEXP_H__83EE8934_4946_49B7_95D8_AE1B70E4DB72__INCLUDED_)
