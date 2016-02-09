///////////////////////////////////////////////////////////////////////////////////////
/// @file boundaryfunct.hpp						 									///
/// @author Jeff Goymerac and Christine Wang                                        ///
/// @brief This is the Template File for the Boundary Function Class that is used   ///
///        for function calling in The PDEGen class                                 ///
///                                                                                 ///
///////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////
/// @fn operator()(const double x, const double y)                                  ///
/// @brief This generates our values in the solution vector                         ///
/// @param i - vector size                                                          ///
/// @param m_b - Vector to be filled                                                ///
/// @return Outputs the value to add to solution vector                             ///
///////////////////////////////////////////////////////////////////////////////////////


#ifndef BOUNDARYFUNCT_H
#define BOUNDARYFUNCT_H

#include "dmatrix.h"
#include "MyVect.h"
#include "math.h"

template<class T>
class BoundaryFunct
{
	public: 
		double operator()(const double x, const double y);
};

#include "boundaryfunct.hpp"

#endif
