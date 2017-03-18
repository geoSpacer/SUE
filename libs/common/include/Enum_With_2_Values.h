#ifndef COMMON_LIB__ENUM_WITH_2_VALUES_H
#define COMMON_LIB__ENUM_WITH_2_VALUES_H

//-----------------------------------------------------------------------------

//  Macro:  ENUM_WITH_2_VALUES
//
//  This macro defines an "enum"erated type with 2 values: 1 and 0.  The type
//  is essentially a boolean type.  The names of the 2 values are used to
//  create the name of the type as follows:
//
//	{true_value_name}_or_{false_value_name}

#define ENUM_WITH_2_VALUES(true_value_name, false_value_name)	\
    enum true_value_name##_or_##false_value_name {		\
	true_value_name  = 1,					\
	false_value_name = 0					\
    };								\
								\
    inline							\
    bool operator==(true_value_name##_or_##false_value_name x,	\
		    true_value_name##_or_##false_value_name y)	\
    {								\
	return int(x) == int(y);				\
    }

//-----------------------------------------------------------------------------

#endif
