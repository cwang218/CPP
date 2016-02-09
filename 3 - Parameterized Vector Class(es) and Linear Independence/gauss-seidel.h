//////////////////////////////////////////////////////////////////////
/// @file gauss-seidel.h
/// @author Christine Wang CS5201
/// @brief GaussSeidel Iteration Functional Class
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @class GaussSeidel
/// @brief Template class to implement Gauss-Seidel iteration to
///				 determine linear independence or dependence of a set of
///				 vectors
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn GaussSeidel(<vector<vector<T> >& source, double tolerance)
/// @brief Constructor for GaussSeidel iteration
/// @pre N/A
/// @post An instance of the class is created with m_vectors = source
///				and m_tolerance = tolerance
/// @param vector<vector<T> >& source - vector containing vectors to
///				 be analyzed
///	@param tolerance - value to set m_tolerance
/// @return N/A
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn solve()
/// @brief Goes through process of determining linear independence,
///				 checks if v1 and v2 are multiples, then starts iteration
///				 they are not
/// @pre N/A
/// @post N/A
/// @return void - returns nothing
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn checkMultiple()
/// @brief Checks if first two vectors in m_vectors are multiples
/// @pre N/A
/// @post N/A
/// @return Returns true if vectors are multiples of each other,
///					false otherwise.
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn iteration(vector<T>& x_old, int num)
/// @brief Perform Gauss-Seidel Iteration to solve for vector x
/// @pre N/A
/// @post m_xs is updated with new values
///	@param num - number of vectors being checked
/// @return Returns true if found to converge within tolerancem
///					false otherwise
/// @fn printResult(bool result)
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @brief Outputs determination of linear independence or dependence
///				 linear combination found if dependent, and tolerance
/// @pre N/A
/// @post N/A
///	@param result - whether or not system is linearly independent
/// @return void - returns nothing
//////////////////////////////////////////////////////////////////////

#ifndef GAUSSSEIDEL_H
#define GAUSSSEIDEL_H

#include "vector.h"

template<class T>
class GaussSeidel
{
	public:
		GaussSeidel( vector<vector<T> >& source, double tolerance);
		void printResult(bool result);
		void solve();
	private:
		vector<vector<T> > m_vectors;	// holds vectors to be analyzed
		vector<double> m_xs;	// holds current x values
		double m_tolerance;	// holds tolerance for Gauss-Seidel iteration
		bool checkMultiple();
		bool iteration(vector<T>& x_old, int num);
};

#include "gauss-seidel.hpp"
#endif
