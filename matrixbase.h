//////////////////////////////////////////////////////////////////////
/// @file matrixbase.h
/// @author Christine Wang CS5201
/// @brief Template Virtual MatrixBase Class
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @class MatrixBase
/// @brief Interface Base class for different matrices
////////////////////////////////////////////////////////////////////// 

////////////////////////////////////////////////////////////////////// 
/// @fn operator *(const MatrixBase<T>& source)
/// @brief virtual Matrix * MatrixBase operator 
/// @pre matrices must be the same dimension, template T must have
///			 * and + operators
/// @post N/A
/// @param source - Instance of Matrix to multiply by
/// @return none - pure virtual function
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator *(const MatrixBase<T>& source)
/// @brief virtual Matrix * MatrixBase operator 
/// @pre matrices must be the same dimension, template T must have
///			 * and + operators
/// @post N/A
/// @param source - Instance of Matrix to multiply by
/// @return none - pure virtual function
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator *(const T mult)
/// @brief virtual Matrix * scalar operator 
/// @pre template T must have * operator
/// @post N/A
/// @param mult - Scalar multiple for Matrix
/// @return none - pure virtual function
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator +(const MatrixBase<T>& source)
/// @brief virtual Matrix + Matrix operator 
/// @pre Matrices must be the same size and template T must have + operator
/// @post N/A
/// @param source - Matrix to be added
/// @return none - pure virtual function
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator -(const MatrixBase<T>& source)
/// @brief virtual Matrix - Matrix operator 
/// @pre Matrices must be the same size and template T must have - operator
/// @post N/A
/// @param source - Matrix to subtract
/// @return none - pure virtual function
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn transpose()
/// @brief virtual MatrixBase transpose function
/// @pre Matrix should have correct dimension and values first
/// @post N/A
/// @return none - pure virtual function
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn dimension()
/// @brief virtual MatrixBase dimension accessor
/// @pre N/A
/// @post N/A
/// @return none - pure virtual function
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator ()(const int x, const int y)
/// @brief Matrix access operator
/// @pre N/A
/// @post N/A
/// @param x - row number, y - column number
/// @return none - pure virtual function
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator ()(const int x, const int y) const
/// @brief Matrix access operator
/// @pre N/A
/// @post N/A
/// @param x - row number, y - column number
/// @return none - pure virtual function
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn ~MatrixBase
/// @brief virtual MatrixBase destructor
/// @pre N/A
/// @post N/A
/// @param N/A
/// @return none - pure virtual function
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn copy(const MatrixBase<T>& source)
/// @brief MatrixBase copy function to copy all elements in a matrix
/// @pre N/A
/// @post N/A
/// @param source - Instance of Matrix to set calling object
/// @return none - pure virtual function
//////////////////////////////////////////////////////////////////////

#ifndef MATRIXBASE_H
#define MATRIXBASE_H

#include "vector.h"
using namespace std;

template<class T>
class MatrixBase
{
	public:		
		/****************** Destructor ******************/
		virtual ~MatrixBase() {}

		/************* Overloaded Operators *************/
		virtual vector<T>& operator[](const int i) = 0;
		virtual vector<T> operator[](const int i) const = 0;

		/****************** Accessors ******************/
		virtual int dimension() const {return 0;}

		/********* Overloaded Stream Operators *********/
		template<class S>
		friend ostream& operator <<(ostream& out, const MatrixBase<S>& source);
		template<class S>
		friend istream& operator >>(istream& in, MatrixBase<S>& source);
};

#endif
