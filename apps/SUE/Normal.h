// Normal.h: interface for the Normal class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NORMAL_H__EDDEC56A_A380_46FC_91B2_887CDA0032F3__INCLUDED_)
#define AFX_NORMAL_H__EDDEC56A_A380_46FC_91B2_887CDA0032F3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "distTyp.h"

class Normal : public DistTyp  
{
public:
	Normal(double	mode, 
		   double	stdDev, 
		   int		discreteIntervals = 10000, 
		   double	stdDevRange = 4);
		// A Normal distribution is entirely specified by it's mode 
		// (= median = mean in this case).  So that's all we need to 
		// specify in the constructor.  
		// Since our implementation of Normal variate generation involves
		// approximating the integral of the Normal probability distribution
		// function, we have two other optional parameters.
		//	discrete_intervals is the number of boxes we use for our integral
		//		approximation.
		//	stdDevRange is the distance from the mean (in standard deviations)
		//		over which we approximate the integral.
		//		4 standard deviations accounts for 99.997% of the area under 
		//		the entire curve, so it makes an adequate default.
		//		<https://courseware.vt.edu/users/holtzman/STAT5605/normaltable.html> 
	virtual ~Normal();
private:
	double CDFInv(double cdfVal) const;
	double pdf(double x) const;
	double _mode, _stdDev, _intervalWidth, _scale, _total, _c1, _pi, _e;
	std::vector<double> _cdfVect;
	std::vector<double> _rectCenterVect;
};

#endif // !defined(AFX_NORMAL_H__EDDEC56A_A380_46FC_91B2_887CDA0032F3__INCLUDED_)
