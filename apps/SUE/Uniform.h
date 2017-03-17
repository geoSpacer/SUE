// Uniform.h: interface for the Uniform class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UNIFORM_H__320975A7_E17E_48A3_9B9C_5C88759DCAA9__INCLUDED_)
#define AFX_UNIFORM_H__320975A7_E17E_48A3_9B9C_5C88759DCAA9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "DistTyp.h"

class Uniform : public DistTyp  
{
public:
	Uniform(double	lowerBound, 
			double	upperBound);
		// Uniform distributions are completely determined by absolute
		// upper and lower bounds, so that's all we need to include 
		// in the constructor.
	virtual ~Uniform();
private:
	double CDFInv(double p) const;
	double _lower, _upper, _range;
};

#endif // !defined(AFX_UNIFORM_H__320975A7_E17E_48A3_9B9C_5C88759DCAA9__INCLUDED_)
