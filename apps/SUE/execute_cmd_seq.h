#ifndef EXECUTE_CMD_SEQ_H
#define EXECUTE_CMD_SEQ_H

//-----------------------------------------------------------------------------

#include <map>
#include <string>
#include <vector>

#include "Command_Sequence.h"

class Ecoregion;

//-----------------------------------------------------------------------------

double execute(const Command_Sequence &								cmd_seq, 
			   std::map <std::string, std::vector<double> >&		sampleSpace,
			   int													index);
    //	Executes the given command sequence, returning the value computed by
    //	the sequence.

namespace Command_Variables
{
    extern double T;
	//  Current time (or whatever the free regression parameter is)
};

//-----------------------------------------------------------------------------

#endif
