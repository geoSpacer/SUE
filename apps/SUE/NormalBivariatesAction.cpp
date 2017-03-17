// NormalBivariatesAction.cpp: implementation of the NormalBivariatesAction class.
//
//////////////////////////////////////////////////////////////////////

#include "pragmas.h"

#include "NormalBivariatesAction.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

NormalBivariatesAction::NormalBivariatesAction(double		requestedCorr,
											   std::string	var1Name,
											   double		var1Mean,
											   double		var1StdDev,
											   std::string	var2Name,
											   double		var2Mean,
											   double		var2StdDev)
{
	_requestedCorr = requestedCorr;
	_var1Name =	var1Name;
	_var1Mean = var1Mean;
	_var1StdDev = var1StdDev;
	_var2Name = var2Name;
	_var2Mean = var2Mean;
	_var2StdDev = var2StdDev;
}

NormalBivariatesAction::~NormalBivariatesAction()
{
	
}

std::string NormalBivariatesAction::performAction(ComputationEngine& compEng)
{
	compEng.normalBivariates(_requestedCorr, _var1Name, _var1Mean, _var1StdDev,
							 _var2Name, _var2Mean, _var2StdDev);
	std::ostringstream ostr;
	ostr << "Created correlated normal parameters \"" << _var1Name 
		 << "\" and \"" << _var2Name 
		 << "\" \nwith modes " << _var1Mean << " and " << _var2Mean 
		 << ",\nstandard deviations " << _var1StdDev << " and "
		 << _var2StdDev << ",\nand correlation " << _requestedCorr<< ".\n\n";
	return ostr.str();
}