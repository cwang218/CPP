//////////////////////////////////////////////////////////////////////
/// @file driver.cpp
/// @author Christine Wang CS5201
/// @brief Driver file 
//////////////////////////////////////////////////////////////////////

#include <cstdio>
#include <cstdlib> 
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>

using namespace std;

#include "vector.h"
#include "gauss-seidel.h"


int main(int argc, char* argv[])
{
  // If input file name isn't included, prompt user to run driver again with
  // correct form.
  if(argc == 1)
  {
    cout << "Please use form: driver datafile.txt" << endl;
    return 0;
  }

  char* inputFile = argv[1];

  ifstream fin;                     // used to read data file
  int numVects = 0;                // number of vector inputs
  vector<vector<double> > vect;  			// used to hold vector inputs

  fin.open(inputFile); // open data file
  fin >> numVects;   // read in number of inputs

  vect.setsize(numVects);

  for(int i = 0; i < numVects; i++)
  {
    vect[i].setsize(numVects);

    for(int j = 0; j<numVects; j++)
    {
      fin >> vect[i][j];
    }
  }

  fin.close();

  vector<double> sum = vect[0]+vect[1];
  vector<double> diff = vect[0]-vect[1];


  cout << "Vector math with first two inputs: " << vect[0] << " and " << vect[1] << endl
  		 << "Sum: " << sum << endl
			 << "Difference: " << diff << endl
			 << "Dot Product: " << (vect[0]*vect[1]) << endl << endl
  		 << "Third input vector: " << vect[2] << endl
  		 << "Second element of third input vector: " << (vect[2])[1] << endl << endl;

  GaussSeidel<double> tester(vect, 0.01);
  tester.solve();

  return 0;
}
