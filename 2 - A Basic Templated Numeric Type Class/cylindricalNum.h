//////////////////////////////////////////////////////////////////////
/// @file cylindricalNum.h
/// @author Christine Wang CS5201
/// @brief cylindricalNum Class Definition and Function Prototypes
////////////////////////////////////////////////////////////////////// 

////////////////////////////////////////////////////////////////////// 
/// @class cylindricalNum
/// @brief Template Class to implement a "wrap" on cylindrical
///				 coordinates
////////////////////////////////////////////////////////////////////// 

////////////////////////////////////////////////////////////////////// 
/// @fn cylindricalNum()
/// @brief Default Constructor for cylindricalNum
/// @pre N/A
/// @post An instance of the class created with private variables
/// @return N/A
////////////////////////////////////////////////////////////////////// 

////////////////////////////////////////////////////////////////////// 
/// @fn cylindricalNum(const T r, const T theta, const T z)
/// @brief Constructor for cylindricalNum with parameters for values
/// @pre N/A
/// @post An instance of the class created with private variables
///				initialized to passed parameters
/// @param r - value set to m_r
/// @param theta - value set to m_theta
/// @param z - value set to m_z
/// @return N/A
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn cylindricalNum(const cylindricalNum<T>& source)
/// @brief Copy Constructor for cylindricalNum
/// @pre N/A
/// @post An instance of the class created with private variables
///				initialized to those of the passed parameters
/// @param source - Instance of cylindricalNum by reference sent to copy
/// @return N/A
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn ~cylindricalNum()
/// @brief Destructor for cylindricalNum
/// @pre N/A
/// @post The instance of cylindricalNum is deleted
/// @return N/A
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn cylindricalNum<T> operator -() const
/// @brief cylindricalNum negation operator
/// @pre N/A
/// @post N/A
/// @return Copy of instance with (-1)*(m_r)
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn cylindricalNum<T> operator !() cosnt
/// @brief cylindricalNum conjugate operator
/// @pre N/A
/// @post N/A
/// @return Copy of instance with (-1)*(m_z)
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn T operator ~() const
/// @brief cylindricalNum magnitude accessor
/// @pre N/A
/// @post N/A
/// @return sqrt(r^2 + z^2)
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn cylindricalNum<T> operator =(const cylindricalNum<T>& source)
/// @brief cylindricalNum copy operator
/// @pre N/A
/// @post values of calling object are set to those of source
/// @param source - Instance of cylindricalNum to set calling object
/// @return reference of instance with updated values
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn T operator [](const int coord_choice) const
/// @brief cylindricalNum accessor operator
/// @pre N/A
/// @post N/A
/// @param coord_choice - chooses value to return
///				 (0 for r, 1 for theta, 2 for z)
/// @return value of m_r, m_theta, or m_z depending on coord_choice
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn bool operator <(const cylindricalNum<T>& source) const
/// @brief cylindricalNum less than operator
/// @pre N/A
/// @post N/A
/// @param source - Instance of cylindricalNum to compare with the
///			   calling object
/// @return bool of ~p < ~source
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn bool operator >(const cylindricalNum<T>& source) const
/// @brief cylindricalNum greater than operator
/// @pre N/A
/// @post N/A
/// @param source - Instance of cylindricalNum to compare with the
///			   calling object
/// @return bool of ~p > ~source
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn bool operator ==(const cylindricalNum<T>& source) const
/// @brief cylindricalNum equal to operator
/// @pre N/A
/// @post N/A
/// @param source - Instance of cylindricalNum to compare with the
///			   calling object
/// @return bool of (m_r = source.m_r && m_theta = source.m_theta
///					&& m_z = source.m_z)
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn bool operator !=(const cylindricalNum<T>& source) const
/// @brief cylindricalNum not equal to operator
/// @pre N/A
/// @post N/A
/// @param source - Instance of cylindricalNum to compare with the
///				 calling object
/// @return bool of !(m_r = source.m_r && m_theta = source.m_theta
///					&& m_z = source.m_z)
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn &ostream operator <<(ostream& out, cylindricalNum<T>& source)
/// @brief Function to output values of source
/// @pre N/A
/// @post N/A
/// @param out - ostream instance to output values of source to
/// @param source - cylindricalNum instance with values to put out
/// @return friend reference to ostream with source's values
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn istream& operator >>(istream& in, cylindricalNum<T>& source)
/// @brief Function to input values to source
/// @pre N/A
/// @post N/A
/// @param in - istream instance to input values into source
/// @param source - cylindricalNum instance to put values into
/// @return friend reference to istream
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn string to_cartesian()
/// @brief Function to convert to cartesian values (x,y,z) as a string
/// @pre N/A
/// @post N/A
/// @return Converted cartesian values (x,y,z) as a string
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn T getR() const
/// @brief Acessor function for m_r
/// @pre N/A
/// @post N/A
/// @return Value of m_r
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn T getTheta() const
/// @brief Acessor function for m_theta
/// @pre N/A
/// @post N/A
/// @return Value of m_theta
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn T getZ() const
/// @brief Acessor function for m_z
/// @pre N/A
/// @post N/A
/// @return Value of m_z
//////////////////////////////////////////////////////////////////////

#ifndef CYLINDRICALNUM_H
#define CYLINDRICALNUM_H

#include <cstring>
#include <sstream>

template<class T>
class cylindricalNum
{
public:
	/***************** Constructors *****************/
	cylindricalNum();
	cylindricalNum(const T r, const T theta, const T z);
	cylindricalNum(const cylindricalNum<T>& source);

	/****************** Destructor ******************/
	~cylindricalNum();

	/************* Overloaded Operators *************/
	cylindricalNum<T> operator -() const;
	cylindricalNum<T> operator !() const;
	T operator ~() const;
	cylindricalNum<T> operator =(const cylindricalNum<T>& source);
	T operator [](const int coord_choice) const;
	bool operator <(const cylindricalNum<T>& source) const;
	bool operator >(const cylindricalNum<T>& source) const;
	bool operator ==(const cylindricalNum<T>& source) const;
	bool operator !=(const cylindricalNum<T>& source) const;

	/*************** Other Functions ***************/
	string to_cartesian();

	/****************** Accessors ******************/
	T getR() const;
	T getTheta() const;
	T getZ() const;

	/********* Overloaded Stream Operators *********/
	template<class S>
	friend ostream& operator <<(ostream& out, const cylindricalNum<S>& source);
	template<class S>
	friend istream& operator >>(istream& in, cylindricalNum<S>& source);

private:
	/******************** Data ********************/
	T m_r;
	T m_theta;
	T m_z;

};

#include "cylindricalNum.hpp"
#endif
