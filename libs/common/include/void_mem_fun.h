#ifndef COMMON_LIB__VOID_MEM_FUN_H
#define COMMON_LIB__VOID_MEM_FUN_H

//-----------------------------------------------------------------------------

#include <functional>

//-----------------------------------------------------------------------------

//  Visual C++ (Service Pack 5) does not allow a void function to have a
//  return statement that calls another void function.  The example below is
//  from "The C++ Programming Language, 3rd edition" by Bjarne Stroustrup,
//  Section 7.3 "Value REturn", pg 148:
//
//	void g(int* p);
//
//	void h(int* p) { /* ... */ return g(p); }  // ok: return of "no value"
//
//  This example causes VC to output error C2562 -- 'void' function returning
//  a value.
//
//  Unfortunately, this feature is important for various template functions
//  in the standard library.  One of them is "mem_fun".
//
//  To work around this problem, we define a template called "void_mem_fun()"
//  to be used with member functions that have a return type of "void".  It's
//  based on the code in Stroustrup for "mem_fun_t" and "mem_func" in
//  Section 18.4.4.2 "Member Function Adapters", pg 520.

#ifdef WIN32

    template<class R,
	     class T>
    class void_mem_fun_t
	: public std::unary_function<T*, R>
    {
	R (T::*pmf)();

    public:
	explicit
	    void_mem_fun_t(R (T::*p)())
		: pmf(p)
	    { }

	R operator()(T* p) const
	{
	    (p->*pmf)();    //	call through pointer
	}
    };

    //-------------------------------------------------------------------------

    template<class R,
	     class T>
    void_mem_fun_t<R,T> void_mem_fun(R (T::*f)())
    {
	return void_mem_fun_t<R,T>(f);
    }

#else

    #define void_mem_fun_t mem_fun_t
    #define void_mem_fun   mem_fun

#endif

//-----------------------------------------------------------------------------

#endif
