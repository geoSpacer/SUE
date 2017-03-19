#ifndef COMMON_LIB__OUTPUT_COLUMNS_H
#define COMMON_LIB__OUTPUT_COLUMNS_H

//-----------------------------------------------------------------------------

#include <fstream>
#include <vector>

#include "Str_Column.h"
#include "Int_Column.h"
#include "Float_Column.h"
#include "Column_Group.h"

//-----------------------------------------------------------------------------

void write_titles(std::ofstream &		       file,
		  const std::vector<Column_or_Group> & columns,
		  bool				       initial_GT_sign = true);

    //	Write all the titles for a list of output columns to a file.
    //	If {initial_GT_sign} is true, then the first character of each title
    //	line is replaced with a ">" (so make sure the first column has a
    //	lead spacing > 0.

const bool no_initial_GT_sign = false;

    //	To make code a bit more self-documenting.

Multi_Line_Text combine_titles(const std::vector<Column_or_Group> & columns);

    //	Combine all the titles for a list of output columns into a single set
    //	of lines.

//-----------------------------------------------------------------------------

#endif
