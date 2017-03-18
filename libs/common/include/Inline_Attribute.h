#ifndef COMMON_LIB__INLINE_ATTRIBUTE_H
#define COMMON_LIB__INLINE_ATTRIBUTE_H

//-----------------------------------------------------------------------------

//  Macro:  INLINE_ATTRIBUTE
//
//  This macro simply defines an inline function to provide read-only access
//  to a class' member that represents an attribute.

#define INLINE_ATTRIBUTE(type, class_, attribute)	\
    inline						\
    type class_::attribute() const			\
    {							\
	return attribute##_;				\
    }

//-----------------------------------------------------------------------------

#endif
