//////////////////////////////////////////////////////////////////////
/// @file smatrix.h
/// @author Christine Wang CS5201
/// @brief SMatrix Class Template
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @class SMatrix 
/// @brief Template class for a Symmetric Matrix
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn copy(const SMatrix<T>& source)
/// @brief Copy function for SMatrix
/// @pre N/A
/// @post Calling object will have m_dimension=source.m_dimension
///				and same values in m_ptr_to_data as source.m_ptr_to_data
/// @return N/A
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn SMatrix()
/// @brief Default constructor for SMatrix
/// @pre N/A
/// @post An instance of the class created with m_dimension=0
///				and m_ptr_to_data=0
/// @return N/A
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn SMatrix(const int dim)
/// @brief Constructor for SMatrix with parameter for dimension
/// @pre dim must be greater than or equal to zero
/// @post An instance of the class created with m_dimension columns
///				and rows
/// @param dim - dimension value to set m_dimension
/// @return N/A
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn ~SMatrix() 
/// @brief Destructor for SMatrix 
/// @pre N/A 
/// @post Deletes m_ptr_to_data
/// @return N/A
////////////////////////////////////////////////////////////////////// 

////////////////////////////////////////////////////////////////////// 
/// @fn operator()(const int i, const int j)
/// @brief SMatrix accessor operator
/// @pre index must be within range (0 <= index < m_dimension)
/// @post N/A
/// @param index - index of value to return within SMatrix
/// @return Returns value of T at (i+1)th row and (j+1)th column
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator()(const int i, const int j) const
/// @brief SMatrix accessor operator
/// @pre index must be within range (0 <= index < m_dimension)
/// @post N/A
/// @param index - index of value to return within SMatrix
/// @return Returns value of T at (i+1)th row and (j+1)th column
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator=(const SMatrix<T>& source)
/// @brief SMatrix assignment operator for SMatrix
/// @pre N/A 
/// @post Values of calling object are set to those of source
/// @param source - Instance of SMatrix to set values of calling object
/// @return Returns a reference to instance with updated values
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator+(const MatrixBase<T>& source)
/// @brief Addition operator for SMatrix
/// @pre source.m_dimension must equal m_dimension
/// @post N/A
/// @param source - MatrixBase to add to calling SMatrix
/// @return Returns MatrixBase sum of calling SMatrix and source
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator-() const
/// @brief Negation operator for SMatrix
/// @pre N/A
/// @post N/A
/// @return Returns a copy of instance with 
///					(-1)*(all values in ptr_to_data)
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator-(const MatrixBase<T>& source)
/// @brief Subtraction operator for SMatrix
/// @pre m_dimension must be equal to source.m_dimension
/// @post N/A
/// @param source - MatrixBase subtracted from calling object
/// @return Returns MatrixBase difference of calling object and source
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator*(const MatrixBase<T>& source)
/// @brief Multiplication operator for SMatrix
/// @pre m_dimension must equal source.m_dimension
/// @post N/A
/// @param source - MatrixBase to multiply with calling SMatrix
/// @return Returns product of calling MatrixBase and SMatrix source
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator*(const T mult)
/// @brief Multiplication operator for SMatrix and number
/// @pre N/A
/// @post N/A
/// @param mult - number to multiply with SMatrix
/// @return Returns SMatrix*mult
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn dimension() 
/// @brief Accessor function for m_dimension of SMatrix
/// @pre N/A
/// @post N/A
/// @return int - m_dimension, or the dimension of the SMatrix
////////////////////////////////////////////////////////////////////// 

////////////////////////////////////////////////////////////////////// 
/// @fn istream& operator >>(istream& in, MatrixBase<S>& source)
/// @brief Function to input values to source
/// @pre N/A
/// @post N/A
/// @param in - istream instance to input values into source
/// @param source - SMatrix instance to put values into
/// @return friend reference to istream
//////////////////////////////////////////////////////////////////////

#ifndef SMATRIX_H
#define SMATRIX_H

template<class T>
class SMatrix: public Matrix<T>
{
	public:
		/***************** Constructors *****************/
		SMatrix();
		SMatrix(int dimension);
		SMatrix(const SMatrix<T>& source);

		/****************** Destructor ******************/
		virtual ~SMatrix();

		/************* Overloaded Operators *************/
		virtual T& operator()(const int i, const int j);
		virtual T operator()(const int i, const int j) const;
		SMatrix<T>& operator=(const SMatrix<T>& source);
		SMatrix<T>& operator+(const SMatrix<T>& source);
		SMatrix<T>& operator-(const SMatrix<T>& source);
		SMatrix<T>& operator-();
		SMatrix<T>& operator*(const T mult);

		/****************** Accessors ******************/
		virtual int dimension() const {return m_dimension;}

		/********* Overloaded Stream Operators *********/
		template<class S>
		friend ostream& operator <<(ostream& out, const SMatrix<S>& source);
		template<class S>
		friend istream& operator >>(istream& in, SMatrix<S>& source);

	private:
		int m_dimension;
		T** m_ptr_to_data;
		void copy(const SMatrix<T>& source);
		void clean();
};

#include "smatrix.hpp"

#endif
