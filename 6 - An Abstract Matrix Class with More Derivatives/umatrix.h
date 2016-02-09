//////////////////////////////////////////////////////////////////////
/// @file UUMatrix.h
/// @author Christine Wang CS5201
/// @brief UUMatrix Class Template
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @class UUMatrix 
/// @brief Template class for an Upper Triangular UMatrix
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn copy(const UUMatrix<T>& source)
/// @brief Copy function for UUMatrix
/// @pre N/A
/// @post Calling object will have m_dimension=source.m_dimension
///				and same values in m_ptr_to_data as source.m_ptr_to_data
/// @return N/A
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn UUMatrix()
/// @brief Default constructor for UUMatrix
/// @pre N/A
/// @post An instance of the class created with m_dimension=0
///				and m_ptr_to_data=0
/// @return N/A
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn UUMatrix(const int dim)
/// @brief Constructor for UUMatrix with parameter for dimension
/// @pre dim must be greater than or equal to zero
/// @post An instance of the class created with m_dimension columns
///				and rows
/// @param dim - dimension value to set m_dimension
/// @return N/A
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn ~UUMatrix() 
/// @brief Destructor for UUMatrix 
/// @pre N/A 
/// @post Deletes m_ptr_to_data
/// @return N/A
////////////////////////////////////////////////////////////////////// 

////////////////////////////////////////////////////////////////////// 
/// @fn operator()(const int i, const int j)
/// @brief UUMatrix accessor operator
/// @pre index must be within range (0 <= index < m_dimension)
/// @post N/A
/// @param index - index of value to return within UUMatrix
/// @return Returns value of T at (i+1)th row and (j+1)th column
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator()(const int i, const int j) const
/// @brief UUMatrix accessor operator
/// @pre index must be within range (0 <= index < m_dimension)
/// @post N/A
/// @param index - index of value to return within UUMatrix
/// @return Returns value of T at (i+1)th row and (j+1)th column
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator=(const UUMatrix<T>& source)
/// @brief UUMatrix assignment operator for UUMatrix
/// @pre N/A 
/// @post Values of calling object are set to those of source
/// @param source - Instance of UUMatrix to set values of calling object
/// @return Returns a reference to instance with updated values
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator+(const UMatrixBase<T>& source)
/// @brief Addition operator for UUMatrix
/// @pre source.m_dimension must equal m_dimension
/// @post N/A
/// @param source - UMatrixBase to add to calling UUMatrix
/// @return Returns UMatrixBase sum of calling UUMatrix and source
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator-() const
/// @brief Negation operator for UUMatrix
/// @pre N/A
/// @post N/A
/// @return Returns a copy of instance with 
///					(-1)*(all values in ptr_to_data)
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator-(const UMatrixBase<T>& source)
/// @brief Subtraction operator for UUMatrix
/// @pre m_dimension must be equal to source.m_dimension
/// @post N/A
/// @param source - UMatrixBase subtracted from calling object
/// @return Returns UMatrixBase difference of calling object and source
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator*(const UMatrixBase<T>& source)
/// @brief Multiplication operator for UUMatrix
/// @pre m_dimension must equal source.m_dimension
/// @post N/A
/// @param source - UMatrixBase to multiply with calling UUMatrix
/// @return Returns product of calling UMatrixBase and UUMatrix source
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator*(const T mult)
/// @brief Multiplication operator for UUMatrix and number
/// @pre N/A
/// @post N/A
/// @param mult - number to multiply with UUMatrix
/// @return Returns UUMatrix*mult
//////////////////////////////////////////////////////////////////////

#ifndef UMATRIX_H
#define UMATRIX_H

#include "matrix.h"
#include "matrixbase.h"

using namespace std;

template<class T>
class UMatrix: private MatrixBase<T>, public Matrix<T>
{
	public:
		/***************** Constructors *****************/
		UMatrix();
		UMatrix(int dimension);
		UMatrix(const UMatrix<T>& source);

		/****************** Destructor ******************/
		virtual ~UMatrix();

		/************* Overloaded Operators *************/
		virtual vector<T>& operator[](const int i);
		virtual vector<T> operator[](const int i) const;
		UMatrix<T>& operator=(const UMatrix<T>& source);

		/****************** Accessors ******************/
		virtual int dimension() const {return m_dimension;}

		/*************** Other Functions ***************/
		void setsize(const int dimension);

		/********* Overloaded Stream Operators *********/
		template<class S>
		friend ostream& operator <<(ostream& out, const UMatrix<S>& source);

	private:
		int m_dimension;
		vector<T>* m_ptr_to_data;
		void copy(const UMatrix<T>& source);
		void clean();
};


#include "umatrix.hpp"

#endif
