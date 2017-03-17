// DistTyp.cpp: implementation of the DistTyp class.
//
//////////////////////////////////////////////////////////////////////
#include "pragmas.h"
#include <iostream>
#include "DistTyp.h"
#include "common/Error.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


Random::Uniform* DistTyp::randNum = 0;



void DistTyp::seed(int seyd)
{
	if(randNum != 0)	// avoids memory leak in the event of calling
		delete randNum;	// seed more than once.
	randNum = new Random::Uniform(seyd);
}






DistTyp::DistTyp()
{

}

DistTyp::~DistTyp()
{

}


double DistTyp::sample() const
{

	double rand_n = randNum->next();
	return CDFInv(rand_n);
}


double DistTyp::InvCDF(double p) const
{
	if(p<0 || p>1)
	{
		throw Error("No!  Inverse CDF only valid [0,1].\n");
	}
	return CDFInv(p);
}

void DistTyp::batch(vector<double>& batchVect) const
{
	int size = batchVect.size();
	for(int i=0; i<size; i++)
	{
		batchVect[i] = sample();
	}
}

