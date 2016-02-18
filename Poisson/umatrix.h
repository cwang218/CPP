//////////////////////////////////////////////////////////////////////
/// @file UMatrix.h
/// @author Christine Wang
/// @brief UMatrix Class Template
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @class UMatrix 
/// @brief Template class for an Upper Triangular Matrix
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn copy(const UMatrix<T>& source)
/// @brief Copy function for UMatrix
/// @pre N/A
/// @post Calling object will have m_dimension=source.m_dimension
///				and same values in m_ptr_to_data as source.m_ptr_to_data
/// @return N/A
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn UMatrix()
/// @brief Default constructor for UMatrix
/// @pre N/A
/// @post An instance of the class created with m_dimension=0
///				and m_ptr_to_data=0
/// @return N/A
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn UMatrix(const int dim)
/// @brief Constructor for UMatrix with parameter for dimension
/// @pre dim must be greater than or equal to zero
/// @post An instance of the class created with m_dimension columns
///				and rows
/// @param dim - dimension value to set m_dimension
/// @return N/A
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn ~UMatrix() 
/// @brief Destructor for UMatrix 
/// @pre N/A 
/// @post Deletes m_ptr_to_data
/// @return N/A
////////////////////////////////////////////////////////////////////// 

////////////////////////////////////////////////////////////////////// 
/// @fn operator()(const int i, const int j)
/// @brief UMatrix accessor operator
/// @pre index must be within range (0 <= index < m_dimension)
/// @post N/A
/// @param index - index of value to return within UMatrix
/// @return Returns value of T at (i+1)th row and (j+1)th column
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator()(const int i, const int j) const
/// @brief UMatrix accessor operator
/// @pre index must be within range (0 <= index < m_dimension)
/// @post N/A
/// @param index - index of value to return within UMatrix
/// @return Returns value of T at (i+1)th row and (j+1)th column
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator=(const UMatrix<T>& source)
/// @brief UMatrix assignment operator for UMatrix
/// @pre N/A 
/// @post Values of calling object are set to those of source
/// @param source - Instance of UMatrix to set values of calling object
/// @return Returns a reference to instance with updated values
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator+(const MatrixBase<T>& source)
/// @brief Addition operator for UMatrix
/// @pre source.m_dimension must equal m_dimension
/// @post N/A
/// @param source - MatrixBase to add to calling UMatrix
/// @return Returns MatrixBase sum of calling UMatrix and source
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator-() const
/// @brief Negation operator for UMatrix
/// @pre N/A
/// @post N/A
/// @return Returns a copy of instance with 
///					(-1)*(all values in ptr_to_data)
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator-(const MatrixBase<T>& source)
/// @brief Subtraction operator for UMatrix
/// @pre m_dimension must be equal to source.m_dimension
/// @post N/A
/// @param source - MatrixBase subtracted from calling object
/// @return Returns MatrixBase difference of calling object and source
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator*(const MatrixBase<T>& source)
/// @brief Multiplication operator for UMatrix
/// @pre m_dimension must equal source.m_dimension
/// @post N/A
/// @param source - MatrixBase to multiply with calling UMatrix
/// @return Returns product of calling MatrixBase and UMatrix source
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator*(const T mult)
/// @brief Multiplication operator for UMatrix and number
/// @pre N/A
/// @post N/A
/// @param mult - number to multiply with UMatrix
/// @return Returns UMatrix*mult
//////////////////////////////////////////////////////////////////////

#ifndef UMATRIX_H
#define UMATRIX_H

#include "Matrix.h"

template<class T>
class UMatrix: public Matrix<T>
{
	public:
		/***************** Constructors *****************/
		UMatrix();
		UMatrix(int dimension);
		UMatrix(const UMatrix<T>& source);

		/****************** Destructor ******************/
		virtual ~UMatrix();

		/************* Overloaded Operators *************/
		virtual MyVect<T> &operator[] (int i);
    virtual const MyVect<T> &operator[] (int i)const;
		T& operator()(const int i, const int j);
		T operator()(const int i, const int j) const;
		UMatrix<T>& operator=(const UMatrix<T>& source);
		UMatrix<T>& operator+(const UMatrix<T>& source);
		UMatrix<T>& operator-(const UMatrix<T>& source);
		UMatrix<T>& operator-();
		UMatrix<T>& operator*(const T mult);
		virtual MyVect<T> &operator* (const MyVect<T> &s);  


		/****************** Accessors ******************/
		virtual int size ()const{return m_dimension;}

		/********* Overloaded Stream Operators *********/
		template<class S>
		friend ostream& operator <<(ostream& out, const UMatrix<S>& source);
		template<class S>
		friend istream& operator >>(istream& in, UMatrix<S>& source);

	private:
		int m_dimension;
		MyVect<T> *m_ptr_to_data;
		void copy(const UMatrix<T>& source);
		void clean();
};


#include "umatrix.hpp"

#endif
