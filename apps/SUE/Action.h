// Action.h: interface for the Action class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ACTION_H__326E379C_42CA_4702_90AA_187DE579F8D3__INCLUDED_)
#define AFX_ACTION_H__326E379C_42CA_4702_90AA_187DE579F8D3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <string>
#include "ComputationEngine.h"

class Action  
{
public:
	Action();
	virtual ~Action();
	std::string virtual performAction(ComputationEngine& compEng);
};


namespace ToString
{
	template <class T>
	std::string vectToString(const std::vector<T>& vect)
	// simply prints the elements of a vector - separated by commas.
	{
		int size = vect.size();
		std::ostringstream ostr;
		for(int i=0; i<size; i++)
		{
			ostr << vect[i];
			if(i != size-1)
				ostr << ", ";
		}
		return ostr.str();
	}

	template <class T>
	std::string listToString(const std::list<T>& lyst)
	{
		std::list<T>::const_iterator itr = lyst.begin();
		std::ostringstream ostr;
		while(itr != lyst.end())
		{
			ostr << *itr;
			itr++;
			if(itr != lyst.end())
				ostr << ", ";
		}
		return ostr.str();
	}
};



#endif // !defined(AFX_ACTION_H__326E379C_42CA_4702_90AA_187DE579F8D3__INCLUDED_)
