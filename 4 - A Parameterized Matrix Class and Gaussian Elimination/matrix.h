//////////////////////////////////////////////////////////////////////
/// @file matrix.h
/// @author Christine Wang CS5201
/// @brief Matrix Class Template
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @class matrix 
/// @brief Template class for a matrix
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn matrix()
/// @brief Default Constructor for matrix
/// @pre N/A
/// @post An instance of the class created with private variables
///				initialized to zero
/// @return N/A
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn matrix(const int dimension)
/// @brief Constructor for matrix with parameter for dimension
/// @pre dimension must be greater than or equal to zero
/// @post An instance of the class created with m_dimension columns
///				and rows
/// @param dimension - dimension value to set m_dimension
/// @return N/A
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn matrix(const matrix<T>& source)
/// @brief Copy constructor for matrix  
/// @pre N/A
/// @post An instance of the class is created with private variables
/// 			initialized to those of the source matrix
/// @param source - Instance of matrix by reference sent to matrixcopy
/// @return N/A
////////////////////////////////////////////////////////////////////// 

////////////////////////////////////////////////////////////////////// 
/// @fn ~matrix() 
/// @brief Destructor for matrix 
/// @pre N/A 
/// @post Deletes m_ptr_to_data
/// @return N/A
////////////////////////////////////////////////////////////////////// 

//////////////////////////////////////////////////////////////////////
/// @fn clean
/// @brief Cleans up allocated memory
/// @pre N/A
/// @post Matrix contains no data and is of length zero
/// @return void - returns nothing
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator [](const int index)
/// @brief Matrix accessor operator
/// @pre index must be within range (0 <= index < m_dimension)
/// @post N/A
/// @param index - index of value to return within matrix
/// @return Returns value of (index-1)th vector of matrix
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator [](const int index) const
/// @brief Matrix accessor operator
/// @pre index must be within range (0 <= index < m_dimension)
/// @post N/A
/// @param index - index of value to return within matrix
/// @return Returns value of (index-1)th vector of matrix
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator =(const matrix<T>& source)
/// @brief Matrix assignment operator for matrix
/// @pre N/A 
/// @post Values of calling object are set to those of source
/// @param source - Instance of matrix to set values of calling object
/// @return Returns a reference to instance with updated values
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator +(const matrix<T>& source) const
/// @brief Addition operator for matrix
/// @pre source.m_dimension must equal m_dimension
/// @post N/A
/// @param source - matrix to add to calling matrix
/// @return Returns matrix sum of calling matrix and source
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator -() const
/// @brief Negation operator for matrix
/// @pre N/A
/// @post N/A
/// @return Returns a copy of instance with
///					(-1)*(all values in ptr_to_data)
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator-(vconst ector<T>& source) const
/// @brief Subtraction operator for matrix
/// @pre m_dimension must be equal to source.m_dimension
/// @post N/A
/// @param source - matrix subtracted from calling object
/// @return Returns matrix difference of calling object and source
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator*(const matrix<T>& source) const
/// @brief Multiplication operator for matrix
/// @pre m_dimension must equal source.m_dimension
/// @post N/A
/// @param source - matrix to multiply with calling matrix
/// @return Returns product of calling matrix and matrix source
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator*(const vector<T>& source) const
/// @brief Multiplication operator for matrix and vector
/// @pre m_dimension must equal source.m_size
/// @post N/A
/// @param source - vector to multiply with calling matrix
/// @return Returns product of calling matrix and vector source
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator*(const T mult) const
/// @brief Multiplication operator for matrix and number
/// @pre N/A
/// @post N/A
/// @param mult - number to multiply with matrix
/// @return Returns matrix*mult
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator==(matrix<T>& rhs)
/// @brief Equal to operator for matrix
/// @pre N/A
/// @post N/A
/// @param rhs - matrix to compare with calling object
/// @return Returns true if equal, false otherwise
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn getdimension() 
/// @brief Accessor function for m_dimension of matrix
/// @pre N/A
/// @post N/A
/// @return int - m_dimension, or the dimension of the matrix
////////////////////////////////////////////////////////////////////// 

////////////////////////////////////////////////////////////////////// 
/// @fn setdimension(const int dimension) 
/// @brief Mutator function for m_dimension in matrix
/// @pre dimension must be greater than or equal to 0
/// @post m_dimension will be set to the value of given parameter, but
/// 			m_ptr_to_data will point to new data. Must be set again.
/// @param dimension - value to set m_dimension
/// @return void - Nothing returned
////////////////////////////////////////////////////////////////////// 

////////////////////////////////////////////////////////////////////// 
/// @fn transpose() const
/// @brief transpose function for matrix
/// @pre N/A
/// @post N/A
/// @return transpose of calling matrix
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
/// @fn istream& operator >>(istream& in, matrix<S>& source)
/// @brief Function to input values to source
/// @pre N/A
/// @post N/A
/// @param in - istream instance to input values into source
/// @param source - matrix instance to put values into
/// @return friend reference to istream
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn matrixcopy(const matrix<T>& source)
/// @brief matrix copy function to copy all tuples in a matrix
/// @pre matrix calling and source should be the same dimension
/// @post Values of m_ptr_to_data are set to those of source
/// @param source - Instance of matrix to set calling object
/// @return void - returns nothing
//////////////////////////////////////////////////////////////////////

#ifndef MATRIX_H
#define MATRIX_H

#include "vector.h"

template<class T>
class matrix
{
	public:
		/***************** Constructors *****************/
		matrix();
		matrix(int dimension);
		matrix(const matrix<T>& source);

		/****************** Destructor ******************/
		~matrix();

		/************* Overloaded Operators *************/
		vector<T>& operator[](const int i);
		const vector<T>& operator[](const int i) const;
		matrix<T>& operator=(const matrix<T>& source);
		bool operator==(matrix<T>& rhs) const;
		matrix<T> operator+(const matrix<T>& source) const;
		matrix<T> operator-() const;
		matrix<T> operator-(const matrix<T>& source) const;
		matrix<T> operator*(const matrix<T>& source) const;
		matrix<T> operator*(const vector<T>& source) const;
		matrix<T> operator*(const T mult) const;

		/****************** Accessors ******************/
		int getDimension() const;

		/****************** Modifiers ******************/
		void setDimension(const int dimension);

		/*************** Other Functions ***************/
		matrix<T> transpose() const;

		/********* Overloaded Stream Operators *********/
		template<class S>
		friend ostream& operator <<(ostream& out, const matrix<S>& source);
		template<class S>
		friend istream& operator >>(istream& in, matrix<S>& source);

	private:
		int m_dimension;
		vector<T>* m_ptr_to_data;
		void matrixcopy(const matrix<T>& source);
		void clean();
};

#include "matrix.hpp"
#endif
