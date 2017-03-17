// ComputationEngine.h: interface for the ComputationEngine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMPUTATIONENGINE_H__2D8530BF_1FCC_42D0_B51F_55DEFA93A0DF__INCLUDED_)
#define AFX_COMPUTATIONENGINE_H__2D8530BF_1FCC_42D0_B51F_55DEFA93A0DF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include<map>
#include<string>
#include<vector>
#include<list>

#include "Command_Sequence.h"

class ComputationEngine  
{
public:
	ComputationEngine(int	sampleSpaceSize, 
					  int	oddSeed);
	virtual ~ComputationEngine();
//------------------------------------------------------------------------------------
//Data Modifiers:
//------------------------------------------------------------------------------------
	void uniform(std::string	varName, 
				double			low, 
				double			high);
		// creates a sample space parameter with a uniform distribution
		// with lower bound "low" and upper bound "high".
		// parameter is stored as varName.
	void triangular(std::string		varName, 
					double			low, 
					double			mode, 
					double			high);
		// creates a sample space parameter with a triangular distribution
		// with lower bound, upper bound, and mode as specified.
		// parameter is stored as varName.
	void negExp(std::string		varName, 
				double			low, 
				double			stdDev);
		// creates a sample space parameter with a negative exponential distribution
		// with lower bound and standard deviation as specified.
		// parameter is stored as varName.
	void normal(std::string		varName, 
				double			mean, 
				double			stdDev);
		// creates a sample space parameter with a normal distribution
		// with mean and standard deviation as specified.
		// parameter is stored as varName.

	void assignFromEquation(std:: string		varName,
							Command_Sequence	commands);
		// creates a sample space parameter with the result of performing
		// commands (commands will be a function on other parameters).

	void normalBivariates(double		requestedCorr,
						  std::string	var1Name,
						  double		var1Mean,
						  double		var1StdDev,
						  std::string	var2Name,
						  double		var2Mean,
						  double		var2StdDev);
		// creates correlated normal bivariates 
		// (one named var1Name, the other var2Name)
		// as though they were drawn from a population 
		// with correlation requestedCorr 
		// var1Name and var2Name will have means and standard
		// deviations as specified.
	void rankCorrelate(std::string	x,
					   std::string	y,
					   double		requestedRankCor,
					   int			method = 1);
		// takes two sample space parameters, x and y,
		// and massages the order of y's elements relative to x
		// in order to achieve close to the requested
		// rank correlation.
		// We have two different methods for the massaging of y's elements.
		// decayRankCorrelate is the default (see documentation for more info).

//------------------------------------------------------------------------------------
//Queriers:
//------------------------------------------------------------------------------------
	double standardDeviation(std::string	varName);
		// returns the standard deviation of the elements in sample space
		// parameter varName.
	double mean(std::string		varName);
		// returns the mean of the elements in sample space parameter varName.
	double median(std::string		varName);
		// returns the median of the elements in sample space parameter
		// varName.
	double correlation(std::string		var1Name,
					   std::string		var2Name);
		// returns the correlation coefficient between sample space parameters
		// var1Name and var2Name.
	double rankCorrelation(std::string		var1Name,
						   std::string		var2Name);
		// returns the rank correlation between sample space parameters
		// var1Name and var2Name.
	void percentileBounds(std::string		varName,
						  double			percentile,
						  double&			low,
						  double&			high);
		// this returns the upper & lower bounds, between 
		// which the middle "percentile" percent of var1's values are found. 
		// This calculations may involve interpolation, in which case
		// weighted interpolated values are taken.  (the returned number
		// will be closest to the closest actual value) 

	void valsToCSV(std::string					fileName, 
				   std::vector<std::string>&	varNames);
		// goes through varNames and puts the elements of those sample
		// space parameters into filename.
		// This will be a .csv file (so name it appropriately)
		// The .csv file is intended to be opened in Excel.  
		// The first element in each "column" is the name of the 
		// parameter of which all the following elements in that same 
		// column are samples.

	void histogram(std::string		fileName,
				   std::string		var, 
				   double			boxes,
				   double			excludedTailPercent = 0);	
		// histogram makes a histogram of the values in the sample space
		// parameter var.  
		// The histogram goes to a .csv file called fileName (again, name it appropriately). 
		// If double "excludedTailPercent" is entered, 
		// the histogram will only cover the middle (100-excludedTails)% of 
		// the parameter's range.  (this can be useful for readability when 
		// a parameter has very long, low probability tails)

	void regression(std::string			fileName,
					Command_Sequence	commands,
					double				freeVarLowBound,
					double				freeVarHighBound,
					int					steps);
		// makes a .csv file with each column corresponding to the result
		// of a regression equation with a different free-variable value.
		// Head of each column will be the free-variable value used for that column.
		// Free-variable will range from freeVarLowBound to freeVarHighBound
		// and the regression equation will be evaluated for "steps" different
		// (equally spaced) free-variable values.

	void regressionPercentiles(std::string			fileName,
							   Command_Sequence		commands,
							   double				freeVarLowBound,
							   double				freeVarHighBound,
							   int					steps,
							   std::vector<double>	percentiles);
		// same as above, only for each free-variable value evaluation, 
		// we'll return the percentiles rather than all the points associated 
		// with a certain free-variable value.
		// Put another way, it's as though we call percentileBounds a number of 
		// times with some evenly spaced percentiles on each cluster of points at 
		// each free-variable value.
		// This will give us a sort of topographic map of the density of the scatter-
		// plot spread. 
		// In the case percentiles = 10, we'd return the deciles (numbers (upper & 
		// lower) which bound the middle 100, 80, 60, 40, 20, and 0 percent of values.)
		// for each free-variable value evaluated.
		// even values of "percentiles" will have a value for middle 0% (= median)
		// whereas odd values will not.

private:
	std::map<std::string, std::vector<double> > _sampleSpaceMap;
	int _sampleSpaceSize;
	void fillMapOfVect(Command_Sequence						commands,
						std::map<double, std::vector<double> >&	mapOfVect,
						double									low,
						double									high,
						double									steps);
	void fillVect(Command_Sequence		commands,
				  double				freeVarValue,
				  std::vector<double>&	vect);
};

#endif // !defined(AFX_COMPUTATIONENGINE_H__2D8530BF_1FCC_42D0_B51F_55DEFA93A0DF__INCLUDED_)
