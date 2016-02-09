//////////////////////////////////////////////////////////////////////
/// @file tmatrix.h
/// @author Christine Wang CS5201
/// @brief TMatrix Class Template
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @class TMatrix 
/// @brief Template class for a Tridiagonal Matrix
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn copy(const TMatrix<T>& source)
/// @brief Copy function for TMatrix
/// @pre N/A
/// @post Calling object will have m_dimension=source.m_dimension
///				and same values in m_ptr_to_data as source.m_ptr_to_data
/// @return N/A
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn TMatrix()
/// @brief Default constructor for TMatrix
/// @pre N/A
/// @post An instance of the class created with m_dimension=0
///				and m_ptr_to_data=0
/// @return N/A
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn TMatrix(const int dim)
/// @brief Constructor for TMatrix with parameter for dimension
/// @pre dim must be greater than or equal to zero
/// @post An instance of the class created with m_dimension columns
///				and rows
/// @param dim - dimension value to set m_dimension
/// @return N/A
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn TMatrix(const MatrixBase<T>& source)
/// @brief Copy Constructor for TMatrix
/// @pre n/A
/// @post An instance of the class created with m_dimension equal
///				to source.m_dimension and m_ptr_to_data=source.m_ptr_to_data
/// @param const MatrixBase<T>& source
/// @return N/A
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn ~TMatrix() 
/// @brief Destructor for TMatrix 
/// @pre N/A 
/// @post Deletes m_ptr_to_data
/// @return N/A
////////////////////////////////////////////////////////////////////// 

////////////////////////////////////////////////////////////////////// 
/// @fn operator()(const int i, const int j)
/// @brief TMatrix accessor operator
/// @pre index must be within range (0 <= index < m_dimension)
/// @post N/A
/// @param index - index of value to return within TMatrix
/// @return Returns value of T at (i+1)th row and (j+1)th column
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator()(const int i, const int j) const
/// @brief TMatrix accessor operator
/// @pre index must be within range (0 <= index < m_dimension)
/// @post N/A
/// @param index - index of value to return within TMatrix
/// @return Returns value of T at (i+1)th row and (j+1)th column
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator=(const TMatrix<T>& source)
/// @brief TMatrix assignment operator for TMatrix
/// @pre N/A 
/// @post Values of calling object are set to those of source
/// @param source - Instance of TMatrix to set values of calling object
/// @return Returns a reference to instance with updated values
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator+(const MatrixBase<T>& source)
/// @brief Addition operator for TMatrix
/// @pre source.m_dimension must equal m_dimension
/// @post N/A
/// @param source - MatrixBase to add to calling TMatrix
/// @return Returns MatrixBase sum of calling TMatrix and source
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator-() const
/// @brief Negation operator for TMatrix
/// @pre N/A
/// @post N/A
/// @return Returns a copy of instance with 
///					(-1)*(all values in ptr_to_data)
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator-(const MatrixBase<T>& source)
/// @brief Subtraction operator for TMatrix
/// @pre m_dimension must be equal to source.m_dimension
/// @post N/A
/// @param source - MatrixBase subtracted from calling object
/// @return Returns MatrixBase difference of calling object and source
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator*(const MatrixBase<T>& source)
/// @brief Multiplication operator for TMatrix
/// @pre m_dimension must equal source.m_dimension
/// @post N/A
/// @param source - MatrixBase to multiply with calling TMatrix
/// @return Returns product of calling MatrixBase and TMatrix source
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator*(const T mult)
/// @brief Multiplication operator for TMatrix and number
/// @pre N/A
/// @post N/A
/// @param mult - number to multiply with TMatrix
/// @return Returns TMatrix*mult
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn istream& operator >>(istream& in, MatrixBase<S>& source)
/// @brief Function to input values to source
/// @pre N/A
/// @post N/A
/// @param in - istream instance to input values into source
/// @param source - TMatrix instance to put values into
/// @return friend reference to istream
//////////////////////////////////////////////////////////////////////

#ifndef TMATRIX_H
#define TMATRIX_H

template<class T>
class TMatrix: public virtual MatrixBase<T>, private Matrix<T>
{
	private:
		void copy(const TMatrix<T>& source);
		int m_dimension;
		T** m_ptr_to_data;
	public:
		/***************** Constructors *****************/
		TMatrix(): Matrix<T>(){}
		TMatrix(const int dim);

		/****************** Destructor ******************/
		~TMatrix(){};

		/************* Overloaded Operators *************/
		virtual T& operator()(const int i, const int j);
		virtual T operator()(const int i, const int j) const;
		virtual MatrixBase<T>&operator=(const MatrixBase<T>& source);
		virtual MatrixBase<T>& operator+(const MatrixBase<T>& source);
		virtual MatrixBase<T>& operator-(const MatrixBase<T>& source);
		virtual MatrixBase<T>& operator-();
		virtual MatrixBase<T>& operator*(const MatrixBase<T>& source);
		virtual MatrixBase<T>& operator*(const T scalar);

		/********* Overloaded Stream Operators *********/
		template<class S>
		friend istream& operator >>(istream& in, MatrixBase<S>& source);
};

#include "tmatrix.hpp"

#endif
