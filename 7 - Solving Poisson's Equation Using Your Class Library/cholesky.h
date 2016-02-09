//////////////////////////////////////////////////////////////////////
/// @file cholesky.h
/// @author Christine Wang CS5201
/// @brief Cholesky Decomposition Class Template
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @class thomas 
/// @brief Template class for Cholesky Decomposition
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn Cholesky(SMatrix<T> s, vector<T> v)
/// @brief Constructor for Cholesky Decomposition with symmetric
///				 matrix A and vector B (Ax=B)
/// @pre s and v must be nonempty
/// @post An instance of the class is created with m_a=s and m_b=v
///	@param s - symmetric matrix input
///				 v - vector input
/// @return N/A
////////////////////////////////////////////////////////////////////// 

////////////////////////////////////////////////////////////////////// 
/// @fn decomp()
/// @brief performs Cholesky Decomposition
/// @pre m_a, m_b, m_l must exist and be nonempty
/// @post m_l is filled
/// @return N/A
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn solve()
/// @brief solves system with forward and backwards substitution
/// @pre m_a, m_b, m_l must exist and be nonempty
/// @post m_a is altered according to algorithm, m_b is changed to
///				the solution set
/// @return vector with solution
////////////////////////////////////////////////////////////////////// 

#ifndef CHOLESKY_H
#define CHOLESKY_H

#include "symmatrix.h"
#include "lmatrix.h"
#include "MyVect.h"
#include "math.h"

template<class T>
class Cholesky
{
	public:
		Cholesky(SymMatrix<T> s, MyVect<T> v);
};

#include "cholesky.hpp"

#endif
