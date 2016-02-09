//////////////////////////////////////////////////////////////////////
/// @file lmatrix.h
/// @author Christine Wang CS5201
/// @brief LMatrix Class Template
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @class LMatrix 
/// @brief Template class for a Lower Triangular Matrix
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn copy(const LMatrix<T>& source)
/// @brief Copy function for LMatrix
/// @pre N/A
/// @post Calling object will have m_dimension=source.m_dimension
///				and same values in m_ptr_to_data as source.m_ptr_to_data
/// @return N/A
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn LMatrix()
/// @brief Default constructor for LMatrix
/// @pre N/A
/// @post An instance of the class created with m_dimension=0
///				and m_ptr_to_data=0
/// @return N/A
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn LMatrix(const int dim)
/// @brief Constructor for LMatrix with parameter for dimension
/// @pre dim must be greater than or equal to zero
/// @post An instance of the class created with m_dimension columns
///				and rows
/// @param dim - dimension value to set m_dimension
/// @return N/A
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn ~LMatrix() 
/// @brief Destructor for LMatrix 
/// @pre N/A 
/// @post Deletes m_ptr_to_data
/// @return N/A
////////////////////////////////////////////////////////////////////// 

////////////////////////////////////////////////////////////////////// 
/// @fn operator()(const int i, const int j)
/// @brief LMatrix accessor operator
/// @pre index must be within range (0 <= index < m_dimension)
/// @post N/A
/// @param index - index of value to return within LMatrix
/// @return Returns value of T at (i+1)th row and (j+1)th column
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator()(const int i, const int j) const
/// @brief LMatrix accessor operator
/// @pre index must be within range (0 <= index < m_dimension)
/// @post N/A
/// @param index - index of value to return within LMatrix
/// @return Returns value of T at (i+1)th row and (j+1)th column
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator=(const LMatrix<T>& source)
/// @brief LMatrix assignment operator for LMatrix
/// @pre N/A 
/// @post Values of calling object are set to those of source
/// @param source - Instance of LMatrix to set values of calling object
/// @return Returns a reference to instance with updated values
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator+(const MatrixBase<T>& source)
/// @brief Addition operator for LMatrix
/// @pre source.m_dimension must equal m_dimension
/// @post N/A
/// @param source - MatrixBase to add to calling LMatrix
/// @return Returns MatrixBase sum of calling LMatrix and source
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator-() const
/// @brief Negation operator for LMatrix
/// @pre N/A
/// @post N/A
/// @return Returns a copy of instance with 
///					(-1)*(all values in ptr_to_data)
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator-(const MatrixBase<T>& source)
/// @brief Subtraction operator for LMatrix
/// @pre m_dimension must be equal to source.m_dimension
/// @post N/A
/// @param source - MatrixBase subtracted from calling object
/// @return Returns MatrixBase difference of calling object and source
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator*(const MatrixBase<T>& source)
/// @brief Multiplication operator for LMatrix
/// @pre m_dimension must equal source.m_dimension
/// @post N/A
/// @param source - MatrixBase to multiply with calling LMatrix
/// @return Returns product of calling MatrixBase and LMatrix source
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator*(const T mult)
/// @brief Multiplication operator for LMatrix and number
/// @pre N/A
/// @post N/A
/// @param mult - number to multiply with LMatrix
/// @return Returns LMatrix*mult
//////////////////////////////////////////////////////////////////////

#ifndef LMATRIX_H
#define LMATRIX_H

#include "matrixbase.h"
#include "matrix.h"

using namespace std;

template<class T>
class LMatrix: public Matrix<T>
{
	public:
		/***************** Constructors *****************/
		LMatrix();
		LMatrix(int dimension);
		LMatrix(const LMatrix<T>& source);

		/****************** Destructor ******************/
		virtual ~LMatrix();

		/************* Overloaded Operators *************/
		virtual vector<T>& operator[](const int i);
		virtual vector<T> operator[](const int i) const;
		LMatrix<T>& operator=(const LMatrix<T>& source);

		/****************** Accessors ******************/
		virtual int dimension() const {return m_dimension;}

		/*************** Other Functions ***************/
		void setsize(const int dimension);

		/********* Overloaded Stream Operators *********/
		template<class S>
		friend ostream& operator <<(ostream& out, const LMatrix<S>& source);

	private:
		int m_dimension;
		vector<T>* m_ptr_to_data;
		void copy(const LMatrix<T>& source);
		void clean();
};

#include "lmatrix.hpp"

#endif
