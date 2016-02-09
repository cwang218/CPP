/////////////////////////////////////////////////////////////////////
/// @file gauss.h
/// @author Christine Wang CS5201
/// @brief Gaussian Elimination Elmination Template Class
//////////////////////////////////////////////////////////////////////


#ifndef GAUSS_H
#define GAUSS_H

#include "matrix.h"
#include "umatrix.h"
#include "lmatrix.h"
#include "vector.h"

template<class T>
class Gauss
{
	public:
		Gauss(Matrix<T>& A, vector<T>& B);
	private:
		Matrix<T> m_A;
		vector<T> m_B;
		vector<T> m_X;
		vector<T> m_Y;
		UMatrix<T> m_U;
		LMatrix<T> m_L;
};

#include "gauss.hpp"
#endif
