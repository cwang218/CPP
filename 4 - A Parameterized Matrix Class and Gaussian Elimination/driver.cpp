//////////////////////////////////////////////////////////////////////
/// @file driver.cpp
/// @author Christine Wang CS5201
/// @brief Driver file
//////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
using namespace std;

#include "exception.h"
#include "vector.h"
#include "matrix.h"
#include "gaussian_solver.h"

int main(int argc, char* argv[])
{
	//If input file isn't included, prompt user to run driver again with correct form
	if(argc==1)
	{
		cout << "Please use form: driver datafilename" << endl;
		return 0;
	}

	char* inputFile = argv[1];

	ifstream fin;	// used to read data file
	int dimension = 0;	// dimension of matrix input

	fin.open(inputFile);
	fin >> dimension;

	try
	{
		matrix<float> A(dimension);	// used to hold m_A
		vector<float> B(dimension);	// used to hold m_B

		fin >> A;
		fin >> B;

		fin.close();

		cout << "Matrix A = " << endl << A << endl << endl
				 << "Matrix B = " << endl << B << endl << endl;

		GaussianSolver<float> solver(A, B);
		solver.solve();

		cout << "The transpose of A = \n";
		matrix<float> T(dimension);
		T = A.transpose();
		cout << T << endl;

		cout << "A x A^T = \n";
		matrix<float> product(dimension);
		product = A * T;
		cout << product << endl;

	}
	catch(Exception& error)
	{
		cerr << "EXCEPTION CAUGHT: ";	
		error.message();
	}
	return 0;	
}
