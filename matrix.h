//////////////////////////////////////////////////////////////////////
/// @file Matrix.h
/// @author Christine Wang CS5201
/// @brief Template Matrix Class
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @class Matrix 
/// @brief Template class for a Matrix
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn Matrix()
/// @brief Default constructor for Matrix
/// @pre N/A
/// @post An instance of the class created with m_dimension=0
///				and m_ptr_to_data=0
/// @return N/A
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn Matrix(const int dim)
/// @brief Constructor for Matrix with parameter for dimension
/// @pre dim must be greater than or equal to zero
/// @post An instance of the class created with m_dimension columns
///				and rows
/// @param dim - dimension value to set m_dimension
/// @return N/A
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn Matrix(const MatrixBase<T>& source)
/// @brief Copy Constructor for Matrix
/// @pre n/A
/// @post An instance of the class created with m_dimension equal
///				to source.m_dimension and m_ptr_to_data=source.m_ptr_to_data
/// @param const MatrixBase<T>& source
/// @return N/A
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn ~Matrix() 
/// @brief Destructor for Matrix 
/// @pre N/A 
/// @post Deletes m_ptr_to_data
/// @return N/A
////////////////////////////////////////////////////////////////////// 

////////////////////////////////////////////////////////////////////// 
/// @fn operator()(const int i, const int j)
/// @brief Matrix accessor operator
/// @pre index must be within range (0 <= index < m_dimension)
/// @post N/A
/// @param index - index of value to return within Matrix
/// @return Returns value of T at (i+1)th row and (j+1)th column
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator()(const int i, const int j) const
/// @brief Matrix accessor operator
/// @pre index must be within range (0 <= index < m_dimension)
/// @post N/A
/// @param index - index of value to return within Matrix
/// @return Returns value of T at (i+1)th row and (j+1)th column
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator=(const Matrix<T>& source)
/// @brief Matrix assignment operator for Matrix
/// @pre N/A 
/// @post Values of calling object are set to those of source
/// @param source - Instance of Matrix to set values of calling object
/// @return Returns a reference to instance with updated values
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator+(const MatrixBase<T>& source)
/// @brief Addition operator for Matrix
/// @pre source.m_dimension must equal m_dimension
/// @post N/A
/// @param source - MatrixBase to add to calling Matrix
/// @return Returns MatrixBase sum of calling Matrix and source
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator-() const
/// @brief Negation operator for Matrix
/// @pre N/A
/// @post N/A
/// @return Returns a copy of instance with 
///					(-1)*(all values in ptr_to_data)
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator-(const MatrixBase<T>& source)
/// @brief Subtraction operator for Matrix
/// @pre m_dimension must be equal to source.m_dimension
/// @post N/A
/// @param source - MatrixBase subtracted from calling object
/// @return Returns MatrixBase difference of calling object and source
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator*(const MatrixBase<T>& source)
/// @brief Multiplication operator for Matrix
/// @pre m_dimension must equal source.m_dimension
/// @post N/A
/// @param source - MatrixBase to multiply with calling Matrix
/// @return Returns product of calling MatrixBase and Matrix source
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator*(const T mult)
/// @brief Multiplication operator for Matrix and number
/// @pre N/A
/// @post N/A
/// @param mult - number to multiply with Matrix
/// @return Returns Matrix*mult
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn dimension() 
/// @brief Accessor function for m_dimension of Matrix
/// @pre N/A
/// @post N/A
/// @return int - m_dimension, or the dimension of the Matrix
////////////////////////////////////////////////////////////////////// 

////////////////////////////////////////////////////////////////////// 
/// @fn &ostream operator <<(ostream& out, matrix<S>& source)
/// @brief Function to output values of source
/// @pre N/A
/// @post N/A
/// @param out - ostream instance to output values of source to
/// @param source - matrix instance with values to put out
/// @return friend reference to ostream with source's values
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn istream& operator >>(istream& in, MatrixBase<S>& source)
/// @brief Function to input values to source
/// @pre N/A
/// @post N/A
/// @param in - istream instance to input values into source
/// @param source - Matrix instance to put values into
/// @return friend reference to istream
//////////////////////////////////////////////////////////////////////
	

#ifndef MATRIX_H
#define MATRIX_H

#include "matrixbase.h"

using namespace std;

template<class T>
class Matrix: public MatrixBase<T>
{
	public:
		/***************** Constructors *****************/
		Matrix();
		Matrix(int dimension);
		Matrix(const Matrix<T>& source);

		/****************** Destructor ******************/
		virtual ~Matrix();

		/************* Overloaded Operators *************/
		virtual vector<T>& operator[](const int i);
		virtual vector<T> operator[](const int i) const;
		bool operator==(Matrix<T>& rhs);
		Matrix<T>& operator=(const Matrix<T>& source);
		Matrix<T>& operator+(const Matrix<T>& source);
		Matrix<T>& operator-(const Matrix<T>& source);
		Matrix<T>& operator-();
		Matrix<T>& operator*(const Matrix<T>& source);
		Matrix<T>& operator*(const T mult);
		Matrix<T>& operator*(const vector<T>& source);

		/****************** Accessors ******************/
		virtual int dimension() const {return m_dimension;}

		/********* Overloaded Stream Operators *********/
		template<class S>
		friend ostream& operator <<(ostream& out, const Matrix<S>& source);
		template<class S>
		friend istream& operator >>(istream& in, Matrix<S>& source);

	private:
		int m_dimension;
		vector<T>* m_ptr_to_data;
		void copy(const Matrix<T>& source);
		void clean();
};

#include "matrix.hpp"
#endif
