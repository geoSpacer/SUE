// DistTyp.h: interface for the distTyp class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DISTTYP_H__A4D7C366_4174_4DFF_9870_75AE9DCC70A4__INCLUDED_)
#define AFX_DISTTYP_H__A4D7C366_4174_4DFF_9870_75AE9DCC70A4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <vector>
#include "common/Random_Uniform.h"

// An abstract base class
class DistTyp  
{
public:
	DistTyp();
	virtual ~DistTyp();
	double sample() const;
		// This function returns a single distribution consistent sample 
		// from the derrived class object's distribution type.
	void batch(std::vector<double>& batchVect) const;
		// This function fills the input vector with a batch of values 
		// consistent with the calling object's distribution.
	double InvCDF(double p) const;
		// This function returns the inverse cumulative distribution function
		// value of a given 0<=p<=1.
	static void seed(int seyd);
		// This function seeds our PRNG.
private:
	double virtual CDFInv(double p) const = 0;
	static Random::Uniform* randNum;
};
	

#endif // !defined(AFX_DISTTYP_H__A4D7C366_4174_4DFF_9870_75AE9DCC70A4__INCLUDED_)


