////////////////////////////////////////////////////////////////////////////

/// @file gaussian_solver.h
/// @author Christine Wang CS5201
/// @brief Gaussian Elimination with Scaled Partial Pivoting
///				 Class Template
////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////
/// @class gaussian_solver 
/// @brief Template class for Gaussian Elimination with Scaled
///				 Partial Pivoting
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
/// @fn GaussianSolver(const matrix<T>& source_A, const vector<T>& source_B)
/// @brief Constructor for GaussianSolver
/// @pre N/A
/// @post	An instance of the class is created with m_A and m_B assigned
///				to source_A and source_B, zero vectors for m_X and m_scalars,
///				m_dim set to dimension of A
/// @param source_A - Matrix input A
///				 source_B - Vector input B
/// @return N/A
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
/// @fn solve()
/// @brief calls functions to solve Ax=B for x
/// @pre N/A
/// @post m_scalars, m_X filled, m_A and m_B modified to RRE form
/// @return	void - returns nothing
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
/// @fn fillScalars()
/// @brief fills m_scalars
/// @pre N/A
/// @post m_scalars is filled with scalar values
/// @return void - returns nothing
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
/// @fn swap(int index1, int index2)
/// @brief swaps two rows in m_A and m_B
/// @pre m_A and m_B must have same dimension/size
/// @post m_A and m_B altered with swapped rows
/// @param index1 - index of row to be swapped with index2
///				 index2 - index of row to be swapped with index1
/// @return void - returns nothing
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
/// @fn eliminate(int row)
/// @brief performs one step of forward elimination
/// @pre row must be a valid index in m_A and m_B (0<=row<m_dim)
/// @post m_A and m_B altered
/// @param row - row number that elimination is being performed around
/// @return void - returns nothing
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
/// @fn substitute()
/// @brief performs backwards substitution
/// @pre m_A and m_B must be non-empty
/// @post m_X is filled with solutions
/// @return void - returns nothing
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
/// @fn findBiggest(int row)
/// @brief helps choose next row for elimination
/// @pre row must be a valid index (0=<row<m_dim)
/// @post N/A
/// @return int - index of row chosen
////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
/// @fn print_Result()
/// @brief prints solution found
/// @pre m_X must be non-empty
/// @post N/A
/// @return void - returns nothing
////////////////////////////////////////////////////////////////////////////

#ifndef GAUSSIANSOLVER_H
#define GAUSSIANSOLVER_H

#include "matrix.h"

template<class T>
class GaussianSolver
{
public:
	GaussianSolver(const matrix<T>& source_A, const vector<T>& source_B);
	void solve();
	void fillScalars();
	void swap(int index1, int index2);
	void eliminate(int row);
	void substitute();
	int findBiggest(int row);
	void printResult();
private:
	int m_dim;
	T* m_scalars;
	matrix<T> m_A;
	vector<T> m_B;
	vector<T> m_X;
};

#include "gaussian_solver.hpp"
#endif
