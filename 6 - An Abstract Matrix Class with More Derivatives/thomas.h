//////////////////////////////////////////////////////////////////////
/// @file thomas.h
/// @author Christine Wang CS5201
/// @brief Thomas Algorithm Class Template
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @class thomas 
/// @brief Template class for Thomas Algorithm
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn Thomas(TMatrix<T> t, vector<T> v)
/// @brief Constructor for Thomas Algorithm with tridiagonal
///				 matrix A and vector B (Ax=B)
/// @pre t and v must be nonempty
/// @post An instance of the class is created with m_a=t and m_b=v
///	@param t - tridiagonal matrix input
///				 v - vector input
/// @return N/A
////////////////////////////////////////////////////////////////////// 

////////////////////////////////////////////////////////////////////// 
/// @fn solve()
/// @brief performs Thomas algorithm
/// @pre m_a, m_b, m_l, m_u must exist and be nonempty
/// @post m_a is altered according to algorithm, m_b is changed to
///				the solution set, m_l and m_u are filled
/// @return vector with solution
////////////////////////////////////////////////////////////////////// 

#ifndef THOMAS_H
#define THOMAS_H

#include "vector.h"
#include "tmatrix.h"
#include "lmatrix.h"
#include "umatrix.h"

template<class T>
class Thomas
{
	public:
		Thomas(TMatrix<T> t, vector<T> v);
		vector<T>& solve();
	private:
		TMatrix<T>* m_a;
		vector<T> m_b;
		LMatrix<T>* m_l;
		UMatrix<T>* m_u;
};

#include "thomas.hpp"

#endif
