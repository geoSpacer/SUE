//-----------------------------------------------------------------------------
//  Class implementation:  Default_Epsilon template
//-----------------------------------------------------------------------------

#include "Default_Epsilon.h"

//-----------------------------------------------------------------------------

float Default_Epsilon<float>::value_ = std::numeric_limits<float>::epsilon();

double Default_Epsilon<double>::value_ =
					std::numeric_limits<double>::epsilon();
