#ifndef COMMON_LIB__VECTOR_OF_H
#define COMMON_LIB__VECTOR_OF_H

//-----------------------------------------------------------------------------

#include <vector>

//-----------------------------------------------------------------------------

//  Function:  vector_of
//
//  Operator:  operator&
//
//  This function and operator are used together to make it easy to specify a
//  literal vector of values.  For example,
//
//	Fruit cherry("cherry");
//	Fruit banana("banana");
//	Fruit mango("mango");
//
//	Fruit_Salad salad( vector_of(cherry) & banana & mango );
//
//  Here, the constructor for Fruit_Salad is passed a vector of 3 Fruit
//  objects.
//
//  Usually, the compiler can deduce the template argument for the "vector_of"
//  function from the function's argument.  However, there are a couple of
//  situations where the template argument should be specified:
//
//	1)  when constructing a vector of std::string from string literals,
//	    e.g.,
//
//		std::vector<std::string> greetings;
//		greetings = vector_of<std::string>("Hello.")
//						 & "Hi"
//						 & "What's up?";
//
//	2) when constructing a vector of float's from floating-point literals
//	   (the compiler treats such a literal as a "double"), e.g.,
//
//		std::vector<float> scores(vector_of<float>(90.5)
//							 & 85
//							 & 0;

template<class T>
inline
std::vector<T> vector_of(const T & x)
{
    return std::vector<T>(1, x);
}

//-----------------------------------------------------------------------------

template<class T,
	 class U>
inline
std::vector<T> operator&(std::vector<T> & vector,
			 const U &	  x)
{
    vector.push_back(T(x));
    return vector;
}


//-----------------------------------------------------------------------------

#endif
