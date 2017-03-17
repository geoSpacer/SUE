// ComputationEngine.cpp: implementation of the ComputationEngine class.
//
//////////////////////////////////////////////////////////////////////

#include "pragmas.h"

#include <map>
#include <string>
#include <vector>
#include <fstream>

#include "common/Error.h"
#include "common/File_Error.h"

#include "Command_Sequence.h"
#include "execute_cmd_seq.h"
#include "ComputationEngine.h"
#include "distributionTypes.h"
#include "correlationStuff.h"
#include "vectorOps.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

using namespace std;

ComputationEngine::ComputationEngine(int	sampleSpaceSize, 
									 int	oddSeed)
{
	if(oddSeed % 2 == 0)
		throw Error("Error constructing ComputationEngine: "
					+(string)"\nPRNG seed must be an odd integer.\n");
	_sampleSpaceSize = sampleSpaceSize;
	DistTyp::seed(oddSeed);
}

ComputationEngine::~ComputationEngine()
{

}

void ComputationEngine::uniform(std::string	varName, 
								double		low, 
								double		high)
{
	if (high < low)
		throw Error("Error: poorly formed uniform parameter."
				    +(std::string)"\nlower bound must be < upper bound of distribution.\n");
	Uniform uni(low, high);
	vector<double> temp(_sampleSpaceSize);
	_sampleSpaceMap[varName] = temp;
	uni.batch(_sampleSpaceMap[varName]);
}
void ComputationEngine::triangular(std::string	varName, 
								   double		low, 
								   double		mode, 
								   double		high)
{
	if(mode < low || high < mode)
		throw Error("Error: poorly formed triangular parameter.\n"
				+(std::string)"must have lower bound <= mode <= upper bound.\n");
	Triangular tri(low, mode, high);
	vector<double> temp(_sampleSpaceSize);
	_sampleSpaceMap[varName] = temp;
	tri.batch(_sampleSpaceMap[varName]);
}
void ComputationEngine::negExp(std::string	varName, 
							   double		low, 
							   double		stdDev)
{
	NegExp neg(low, stdDev);
	vector<double> temp(_sampleSpaceSize);
	_sampleSpaceMap[varName] = temp;
	neg.batch(_sampleSpaceMap[varName]);
}
void ComputationEngine::normal(std::string	varName, 
							   double		mean, 
							   double		stdDev)
{
	Normal norm(mean, stdDev);
	vector<double> temp(_sampleSpaceSize);
	_sampleSpaceMap[varName] = temp;
	norm.batch(_sampleSpaceMap[varName]);
}


void ComputationEngine::assignFromEquation(std::string		varName,
										   Command_Sequence commands)
{
	vector<double> temp(_sampleSpaceSize);
	_sampleSpaceMap[varName] = temp;
	for(int i=0; i < _sampleSpaceSize; i++)
	{	
		_sampleSpaceMap[varName][i] = execute(commands, _sampleSpaceMap, i);
	}
}


void ComputationEngine::normalBivariates(double			requestedCorr,
										 std::string	var1Name,
										 double			var1Mean,
										 double			var1StdDev,
										 std::string	var2Name,
										 double			var2Mean,
										 double			var2StdDev)
{
	if(requestedCorr < -1 || requestedCorr > 1)
		throw Error("Error in normalBivariates: requested correlation must be between -1 and 1.\n");
	vector<double> temp(_sampleSpaceSize);
	_sampleSpaceMap[var1Name] = temp;
	_sampleSpaceMap[var2Name] = temp;
	CorrelationStuff::nicholsNormal(_sampleSpaceMap[var1Name], 
									_sampleSpaceMap[var2Name], 
									requestedCorr, var1Mean, var1StdDev, 
									var2Mean, var2StdDev);
}

void ComputationEngine::rankCorrelate(std::string	x,
									  std::string	y,
									  double		requestedRankCor,
									  int			method)
{	
	if(_sampleSpaceMap.count(x) == 0)
		throw Error("Error in rankCorrelate: Parameter " + x + " could not be found.\n");
	if(_sampleSpaceMap.count(y) == 0)
		throw Error("Error in rankCorrelate: Parameter " + y + " could not be found.\n");
	if(requestedRankCor < -1 || requestedRankCor > 1)
		throw Error("Error in rankCorrelate: requested rank correlation must be between -1 and 1.\n");
	if(method == 1)  // method default = 1
		CorrelationStuff::decayRankCorrelate(_sampleSpaceMap[x], _sampleSpaceMap[y], 
												requestedRankCor);
	else if(method == 2)
		CorrelationStuff::rankCorrelate(_sampleSpaceMap[x], _sampleSpaceMap[y], 
											requestedRankCor);
	else
		throw Error("Error in rankCorrelate: Invalid method choice.\n");
}

//-------------------------------------------------------------------------------
// Queriers:
//-------------------------------------------------------------------------------

double ComputationEngine::standardDeviation(std::string	varName)
{
	if(_sampleSpaceMap.count(varName) == 0)
		throw Error("Error in standardDeviation: Parameter " + 
					varName + " could not be found.\n");
	VectorStats var_stats(_sampleSpaceMap[varName]);
	return var_stats.standardDeviation();
}
double ComputationEngine::mean(std::string	varName)
{
	if(_sampleSpaceMap.count(varName) == 0)
		throw Error("Error in mean: Parameter " + 
					varName + " could not be found.\n");
	VectorStats var_stats(_sampleSpaceMap[varName]);
	return var_stats.mean();
}
double ComputationEngine::median(std::string		varName)
{
	if(_sampleSpaceMap.count(varName) == 0)
		throw Error("Error in median: Parameter " + 
					varName + " could not be found.\n");
	VectorStats var_stats(_sampleSpaceMap[varName]);
	return var_stats.median();
}
double ComputationEngine::correlation(std::string		var1Name,
									  std::string		var2Name)
{
	if(_sampleSpaceMap.count(var1Name) == 0)
		throw Error("Error in correlation: Parameter " + 
					var1Name + " could not be found.\n");
	if(_sampleSpaceMap.count(var2Name) == 0)
		throw Error("Error in correlation: Parameter " + 
					var2Name + " could not be found.\n");
	return CorrelationStuff::correlation(_sampleSpaceMap[var1Name],
										 _sampleSpaceMap[var2Name]);
}
double ComputationEngine::rankCorrelation(std::string		var1Name,
										  std::string		var2Name)
{
	if(_sampleSpaceMap.count(var1Name) == 0)
		throw Error("Error in rankCorrelation: Parameter " + 
					var1Name + " could not be found.\n");
	if(_sampleSpaceMap.count(var2Name) == 0)
		throw Error("Error in rankCorrelation: Parameter " + 
					var2Name + " could not be found.\n");
	return CorrelationStuff::rankCorrelation(_sampleSpaceMap[var1Name],
											 _sampleSpaceMap[var2Name]);
}
void ComputationEngine::percentileBounds(std::string		varName,
										 double				percentile,
										 double&			low,
										 double&			high)
{
	if(_sampleSpaceMap.count(varName) == 0)
		throw Error("Error in percentileBounds: Parameter " + 
					varName + " could not be found.\n");
	if(percentile<0 || percentile>100)
		throw Error("Error in percentileBounds: requested middle percentile"
					+ (std::string)"\nmust be between 0 and 100.\n");
	VectorStats var_stats(_sampleSpaceMap[varName]);
	var_stats.percentileBounds(percentile, low, high);
}

void ComputationEngine::valsToCSV(std::string				fileName, 
								  std::vector<std::string>&	varNames)
{
	int size = varNames.size();
	for(int i=0; i<size; i++)
	{
		if(_sampleSpaceMap.count(varNames[i])==0)
			throw Error("Error in valsToCSV: parameter " + varNames[i] 
						 + " could not be found.");
	}
	ofstream outfile(fileName.c_str());
	if (outfile.is_open())
	{

		for(int i=0; i<size; i++)
		{
			outfile << varNames[i];
			if(i != size-1)
				outfile << ",";
		}
		outfile << "\n";
		for(int j=0; j<_sampleSpaceSize; j++)
		{
			for(int i=0; i<size; i++)
			{
				outfile << _sampleSpaceMap[varNames[i]][j];		
				if(i != size-1)
					outfile << ",";
			}
			outfile << "\n";
		}
		outfile.close();
	}
	else
		throw File::Error(fileName + ": ", "", "ComputationEngine::valsToCSV",
					"Couldn't open file ");
	return;
}

void ComputationEngine::histogram(std::string				fileName,
				  std::string				var, 
								  double				boxes,
								  double				excludedTailPercent)
{
	if(_sampleSpaceMap.count(var) == 0)
		throw Error("Error in histogramize: parameter " + var + " couldn't be found.\n");
	histogramize(_sampleSpaceMap[var], boxes, 
					fileName, excludedTailPercent);
}


void ComputationEngine::regression(std::string			fileName,
								   Command_Sequence		commands,
								   double				freeVarLowBound,
								   double				freeVarHighBound,
								   int					steps)
{
	if(freeVarHighBound <= freeVarLowBound)
		throw Error("Error in regression: "
					+(string)"\nfreeVarLowBound must be < freeVarHighBound.\n");
	if(steps < 2)
		throw Error("Error in regression: \nmust have more"
					+(string)"than 1 step for freeVariable regression.\n");
	double range = freeVarHighBound - freeVarLowBound; 
	double step_size = range/steps;
	map<double, vector<double> > regr_numbers;
	fillMapOfVect(commands, regr_numbers, freeVarLowBound, freeVarHighBound, steps);
	
	ofstream outfile(fileName.c_str());
	if (outfile.is_open())
	{
		outfile << "freeVariable, result\n";
		for(int i=0; i<=steps; i++)
		{
			double free_var_val = freeVarLowBound + i*step_size;
			for(int j=0; j<_sampleSpaceSize; j++)
				outfile << free_var_val << ","
						<< regr_numbers[free_var_val][j] << "\n";
		}	
		outfile.close();
	}
	else
		throw File::Error(fileName + ": ", "", "ComputationEngine::Regression",
					"Couldn't open file ");
	return;
	
}


void ComputationEngine::regressionPercentiles(std::string			fileName,
											  Command_Sequence		commands,
											  double				freeVarLowBound,
											  double				freeVarHighBound,
											  int					steps,
											  std::vector<double>	percentiles)
{
	if(freeVarHighBound <= freeVarLowBound)
		throw Error("Error in regressionPercentiles: "
					+(string)"\nfreeVarLowBound must be < freeVarHighBound.\n");
	if(steps < 2)
		throw Error("Error in regressioPercentiles: \nmust have more"
					+(string)"than 1 step for freeVariable regression.\n");
	map<double, vector<double> > regr_numbers;
	fillMapOfVect(commands, regr_numbers, freeVarLowBound, freeVarHighBound, steps);

	double range = freeVarHighBound - freeVarLowBound; 
	double step_size = range/steps;
	double free_var_val;
	ofstream outfile(fileName.c_str());
	if (outfile.is_open())
	{
		//----------------------------------------------------------------------
		// first establish column names ----------------------------------------
		//----------------------------------------------------------------------
		outfile << "freeVarValue, ";
		for(int i=0; i<percentiles.size(); i++)
		{
			if(percentiles[i] < 0 || percentiles[i] > 100)
				throw Error("Error in regressionPercentiles: "
							 + (string)"\nPercentile values must be > 0 and < 100.\n");
			if(percentiles[i]==0)
				outfile << "median";
			else 
				outfile << "middle " << percentiles[i] << "% - lower bound, "
						<< "middle " << percentiles[i] << "% - upper bound";
			if(i<percentiles.size()-1)	// if we're not on the last vector element,
				outfile << ", ";		// slap on a comma.
		}
		outfile << "\n";
		//----------------------------------------------------------------------
		// then fill the columns with values -----------------------------------
		//----------------------------------------------------------------------
		for(int j=0; j<=steps; j++)
		{	
			free_var_val = freeVarLowBound + j*step_size;
			VectorStats stats(regr_numbers[free_var_val]);

			outfile << free_var_val << ", ";

			double low, high;
			for(int i=0; i<percentiles.size(); i++)
			{
				if(percentiles[i]==0)
					outfile << stats.median();
				else 
				{
					double tester = percentiles[i];
					stats.percentileBounds(percentiles[i], low, high);
					outfile << low << ", "
							<< high;
				}
				if(i<percentiles.size()-1)
					outfile << ", ";
			}
			outfile << "\n";
		}
		outfile.close();
	}
	else
		throw File::Error(fileName + ": ", "", "ComputationEngine::RegressionPercentiles",
					"Couldn't open file ");

}

void ComputationEngine::fillMapOfVect(Command_Sequence							commands,
									  std::map<double, std::vector<double> >&	mapOfVect,
									  double									low,
									  double									high,
									  double									steps)
{	
	double range = high - low;
	double step_size = range/steps;
	vector<double> temp(_sampleSpaceSize);
	for(int i=0; i<=steps; i++)
	{
		double free_var_val = low + i*step_size;
		mapOfVect[free_var_val] = temp;
		mapOfVect[free_var_val].resize(_sampleSpaceSize);
		fillVect(commands, free_var_val, mapOfVect[free_var_val]);
	}
}

void ComputationEngine::fillVect(Command_Sequence		commands,
								 double					freeVarValue,
								 std::vector<double>&	vect)
{
	Command_Variables::T = freeVarValue;
	for(int i=0; i<_sampleSpaceSize; i++)
		vect[i] = execute(commands, _sampleSpaceMap, i);
}
