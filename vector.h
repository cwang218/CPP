//////////////////////////////////////////////////////////////////////
/// @file vector.h
/// @author Christine Wang CS5201
/// @brief Vector Class Template
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @class vector 
/// @brief Template class for a vector
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn vector()
/// @brief Default Constructor for vector
/// @pre N/A
/// @post An instance of the class created with private variables
///				initialized to zero
/// @return N/A
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/// @fn vector(const int size)
/// @brief Constructor for vector with parameter for size
/// @pre size must be greater than or equal to zero
/// @post An instance of the class created with m_size tuples
/// @param size - size value to set m_size
/// @return N/A
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn vector(const vector<T>& source)
/// @brief Copy constructor for vector  
/// @pre N/A
/// @post An instance of the class is created with private variables
/// 			initialized to those of the source vector
/// @param source - Instance of vector by reference sent to vectorcopy
/// @return N/A
////////////////////////////////////////////////////////////////////// 

////////////////////////////////////////////////////////////////////// 
/// @fn ~vector() 
/// @brief Destructor for vector 
/// @pre N/A 
/// @post Deletes ptr_to_data
/// @return N/A
////////////////////////////////////////////////////////////////////// 

//////////////////////////////////////////////////////////////////////
/// @fn clean
/// @brief Cleans up allocated memory
/// @pre N/A
/// @post Vector contains no data and is of length zero
/// @return void - returns nothing
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator [](const int index)
/// @brief Vector accessor operator
/// @pre index must be within range (0 <= index < m_size)
/// @post N/A
/// @param index - index of value to return within vector
/// @return Returns value of (index-1)th tuple of vector
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator [](const int index) const
/// @brief Vector accessor operator
/// @pre index must be within range (0 <= index < m_size)
/// @post N/A
/// @param index - index of value to return within vector
/// @return Returns value of (index-1)th tuple of vector
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator =(const vector<T>& source)
/// @brief Vector assignment operator for vector
/// @pre N/A 
/// @post Values of calling object are set to those of source
/// @param source - Instance of vector to set values of calling object
/// @return Returns a reference to instance with updated values
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator =(const float rhs)
/// @brief Scalar assignment operator for vector
/// @pre N/A 
/// @post All values of calling object are set to rhs
/// @param rhs - value to set all tuples of vector
/// @return Returns a reference of instance with updated values
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator +(const vector<T>& source) const
/// @brief Addition operator for vector
/// @pre source.m_size must equal m_size
/// @post N/A
/// @param source - vector to add to calling vector
/// @return Returns vector sum of calling vector and source
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator -() const
/// @brief Negation operator for vector
/// @pre N/A
/// @post N/A
/// @return Returns a copy of instance with
///					(-1)*(all values in ptr_to_data)
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator-(vconst ector<T>& source) const
/// @brief Subtraction operator for vector
/// @pre m_size must be equal to source.m_size
/// @post N/A
/// @param source - vector subtracted from calling object
/// @return Returns vector difference of calling object and source
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator*(const vector<T>& source) const
/// @brief Dot product operator for vector
/// @pre m_size must equal source.m_size
/// @post N/A
/// @param source - vector to calculate dot product with calling vector
/// @return Returns dot product of calling vector and source
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator==(vector<T>& rhs)
/// @brief Equal to operator for vector
/// @pre N/A
/// @post N/A
/// @param rhs - vector to compare with calling object
/// @return Returns true if equal, false otherwise
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn operator*(const T mult) const
/// @brief Multiplication operator for vector and number
/// @pre N/A
/// @post N/A
/// @param mult - number to multiply with vector
/// @return Returns vector*mult
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn getsize() 
/// @brief Accessor function for m_size of vector
/// @pre N/A
/// @post N/A
/// @return int - m_size, or the size of the vector
////////////////////////////////////////////////////////////////////// 

////////////////////////////////////////////////////////////////////// 
/// @fn setSize(const int size) 
/// @brief Mutator function for m_size in vector
/// @pre size must be greater than or equal to 0
/// @post m_size will be set to the value of given parameter, but
/// 			m_ptr_to_data will point to new data. Must be set again.
/// @param size - value to set m_size
/// @return void - Nothing returned
////////////////////////////////////////////////////////////////////// 

////////////////////////////////////////////////////////////////////// 
/// @fn findAbsMax
/// @brief find index of largest absolute number in array
/// @pre vector must be nonempty
/// @post N/A
/// @return index of largest absolute number
////////////////////////////////////////////////////////////////////// 

////////////////////////////////////////////////////////////////////// 
/// @fn &ostream operator <<(ostream& out, vector<S>& source)
/// @brief Function to output values of source
/// @pre N/A
/// @post N/A
/// @param out - ostream instance to output values of source to
/// @param source - vector instance with values to put out
/// @return friend reference to ostream with source's values
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn istream& operator >>(istream& in, vector<S>& source)
/// @brief Function to input values to source
/// @pre N/A
/// @post N/A
/// @param in - istream instance to input values into source
/// @param source - vector instance to put values into
/// @return friend reference to istream
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn vectorcopy(const vector<T>& source)
/// @brief vector copy function to copy all tuples in a vector
/// @pre vector calling and source should be the same size
/// @post Values of m_ptr_to_data are set to those of source
/// @param source - Instance of vector to set calling object
/// @return void - returns nothing
//////////////////////////////////////////////////////////////////////

#ifndef VECTOR_H
#define VECTOR_H

template<class T> class vector
{
	public:
		/***************** Constructors *****************/
		vector();
		vector(const int size);
		vector(const vector<T>& source);

		/****************** Destructor ******************/
		~vector();


		/************* Overloaded Operators ******	c*******/
		T& operator[](const int i);
		const T& operator[](const int it) const;
		vector<T>& operator=(const vector<T>& source);
		vector<T>& operator=(const float rhs);
		T operator*(const vector<T>& source) const;
		bool operator==(vector<T>& rhs) const;
		vector<T> operator+(const vector<T>& source) const;
		vector<T> operator-() const;
		vector<T> operator-(const vector<T>& source) const;
		vector<T> operator*(const T mult) const;

		/****************** Accessors ******************/
		int getSize() const;

		/****************** Modifiers ******************/
		void setSize(const int size);

		/************* Overloaded Operators ******	c*******/
		T findAbsMax();

		/********* Overloaded Stream Operators *********/
		template<class S>
		friend ostream& operator <<(ostream& out, const vector<S>& source);
		template<class S>
		friend istream& operator >>(istream& in, vector<S>& source);

	private:
		int m_size;
		T* m_ptr_to_data;
		void vectorcopy(const vector<T>& source);
		void clean();
};

#include "vector.hpp"
#endif
