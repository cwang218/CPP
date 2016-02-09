//////////////////////////////////////////////////////////////////////
/// @file driver.cpp
/// @author Christine Wang CS5201
/// @brief Driver file
//////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
using namespace std;

#include "vector.h"
#include "matrixbase.h"
#include "matrix.h"
#include "umatrix.h"
#include "lmatrix.h"
#include "gauss.h"


int main(int argc, char* argv[])
{
	//If input file isn't included, prompt user to run driver again with correct form
	if(argc==1)
	{
		cout << "Please use form: driver datafilename" << endl;
		return 0;
	}

	char* inputFile = argv[1];
	//char* inputFile = "prg5.txt";

	ifstream fin;	// used to read data file

	fin.open(inputFile);

	int dim;

	fin >> dim;

	Matrix<float> A(dim);
	vector<float> B(dim);

	fin >> A;
	fin >> B;

	fin.close();

	cout << "Ax = B\n\n"
			 << "A = \n" << A << endl
			 << "B = \n" << B << endl;

	Gauss<float> solver(A,B);

	return 0;	
}
