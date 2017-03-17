// triangular.h: interface for the triangular class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TRIANGULAR_H__A7534CC5_AA74_4775_9D27_2F3E46A0759A__INCLUDED_)
#define AFX_TRIANGULAR_H__A7534CC5_AA74_4775_9D27_2F3E46A0759A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "DistTyp.h"

class Triangular : public DistTyp  
{
public:
	Triangular(double	low, 
			   double	mode, 
			   double	high);
		// a triangular distribution is entirely determined by an upper and 
		// lower bound and a mode.  So that's all we need include in
		// the constructor.
	virtual ~Triangular();
private:
	double _l, _m, _r, _areaLeftOfMode, _c1, _c2a, _c2b;
	double virtual CDFInv(double p) const;
	double lowerCDFInv(double p) const;
	double upperCDFInv(double p) const;
};

#endif // !defined(AFX_TRIANGULAR_H__A7534CC5_AA74_4775_9D27_2F3E46A0759A__INCLUDED_)
