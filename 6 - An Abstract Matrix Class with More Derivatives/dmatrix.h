//////////////////////////////////////////////////////////////////////
/// @file dmatrix.h
/// @author Christine Wang CS5201
/// @brief DMatrix Class Template
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @class DMatrix 
/// @brief Template class for a Diagonal Matrix
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn copy(const DMatrix<T>& source)
/// @brief Copy function for DMatrix
/// @pre N/A
/// @post Calling object will have m_dimension=source.m_dimension
///				and same values in m_ptr_to_data as source.m_ptr_to_data
/// @return N/A
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn DMatrix()
/// @brief Default constructor for DMatrix
/// @pre N/A
/// @post An instance of the class created with m_dimension=0
///				and m_ptr_to_data=0
/// @return N/A
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn DMatrix(const int dim)
/// @brief Constructor for DMatrix with parameter for dimension
/// @pre dim must be greater than or equal to zero
/// @post An instance of the class created with m_dimension columns
///				and rows
/// @param dim - dimension value to set m_dimension
/// @return N/A
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn DMatrix(const MatrixBase<T>& source)
/// @brief Copy Constructor for DMatrix
/// @pre n/A
/// @post An instance of the class created with m_dimension equal
///				to source.m_dimension and m_ptr_to_data=source.m_ptr_to_data
/// @param const MatrixBase<T>& source
/// @return N/A
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn ~DMatrix() 
/// @brief Destructor for DMatrix 
/// @pre N/A 
/// @post Deletes m_ptr_to_data
/// @return N/A
////////////////////////////////////////////////////////////////////// 

////////////////////////////////////////////////////////////////////// 
/// @fn operator()(const int i, const int j)
/// @brief DMatrix accessor operator
/// @pre index must be within range (0 <= index < m_dimension)
/// @post N/A
/// @param index - index of value to return within DMatrix
/// @return Returns value of T at (i+1)th row and (j+1)th column
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator()(const int i, const int j) const
/// @brief DMatrix accessor operator
/// @pre index must be within range (0 <= index < m_dimension)
/// @post N/A
/// @param index - index of value to return within DMatrix
/// @return Returns value of T at (i+1)th row and (j+1)th column
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator=(const DMatrix<T>& source)
/// @brief DMatrix assignment operator for DMatrix
/// @pre N/A 
/// @post Values of calling object are set to those of source
/// @param source - Instance of DMatrix to set values of calling object
/// @return Returns a reference to instance with updated values
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator+(const MatrixBase<T>& source)
/// @brief Addition operator for DMatrix
/// @pre source.m_dimension must equal m_dimension
/// @post N/A
/// @param source - MatrixBase to add to calling DMatrix
/// @return Returns MatrixBase sum of calling DMatrix and source
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator-() const
/// @brief Negation operator for DMatrix
/// @pre N/A
/// @post N/A
/// @return Returns a copy of instance with 
///					(-1)*(all values in ptr_to_data)
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator-(const MatrixBase<T>& source)
/// @brief Subtraction operator for DMatrix
/// @pre m_dimension must be equal to source.m_dimension
/// @post N/A
/// @param source - MatrixBase subtracted from calling object
/// @return Returns MatrixBase difference of calling object and source
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator*(const MatrixBase<T>& source)
/// @brief Multiplication operator for DMatrix
/// @pre m_dimension must equal source.m_dimension
/// @post N/A
/// @param source - MatrixBase to multiply with calling DMatrix
/// @return Returns product of calling MatrixBase and DMatrix source
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator*(const T mult)
/// @brief Multiplication operator for DMatrix and number
/// @pre N/A
/// @post N/A
/// @param mult - number to multiply with DMatrix
/// @return Returns DMatrix*mult
//////////////////////////////////////////////////////////////////////
#ifndef DMATRIX_H
#define DMATRIX_H

template<class T>
class DMatrix: public virtual MatrixBase<T>, private Matrix<T>
{
	private:
		void copy(const DMatrix<T>& source);
		int m_dimension;
		T** m_ptr_to_data;
	public:
		/***************** Constructors *****************/
		DMatrix(): Matrix<T>(){}
		DMatrix(const int dim);
		DMatrix(const int DMatrix<T>& source);

		/****************** Destructor ******************/
		~DMatrix(){};

		/************* Overloaded Operators *************/
		virtual T& operator()(const int i, const int j);
		virtual T operator()(const int i, const int j) const;
		Matrix<T> :: operator=(DMatrix<T>& source);
		virtual MatrixBase<T>& operator+(const MatrixBase<T>& source);
		virtual MatrixBase<T>& operator-(const MatrixBase<T>& source);
		virtual MatrixBase<T>& operator-();
		virtual MatrixBase<T>& operator*(const MatrixBase<T>& source);
		virtual MatrixBase<T>& operator*(const MatrixBase<T>& source);
};

#include "dmatrix.hpp"

#endif
