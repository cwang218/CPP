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
#include <vector>
using namespace std;

#include "cylindricalNum.h"
#include "norm.h"

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
  int numCoords = 0;                // number of cylindricalNum inputs
  vector<cylindricalNum<double> > vect;  // used to hold cylindricalNum inputs

  fin.open(inputFile); // open data file
  fin >> numCoords;   // read in number of inputs

  for(int i = 0; i < numCoords; i++)
  {
    cout << endl;

    cylindricalNum<double> inputCoord; // create cylindricalNum with input values

    // read in values of point
    fin >> inputCoord;

    vect.push_back(inputCoord); // add inputCoord to vector of all inputs

    // Polar reflection of the first point
    if(i == 0)
    {
      cylindricalNum<double> negation = -inputCoord;
      cout << "\nThe polar reflection of " << inputCoord << " is " << negation << ".";

    }
    // z-axis reflection of the second point
    else if(i == 1)
    {
      cylindricalNum<double> conjugate = !inputCoord;
      cout << "\nThe z-axis reflection of " << inputCoord << " is " << conjugate << ".";
    }
    // Comparison of third and forth point
    else if(i == 2)
    {

      cylindricalNum<double> compare;  // cylindricalNum for forth point

      // Read in values of forth point
      fin >> compare;      

      // set comp to <, >, or = depending on comparison of third and forth point
      string comp = " ";

      if(inputCoord < compare)
      {
        comp = " is closer to the origin than ";
      }
      else if(inputCoord > compare)
      {
        comp = " is farther from the origin than ";
      }
      else
      {
        comp = " is the same distance from the origin as ";
      }

      cout << "\n" << inputCoord << comp << compare << ".";

      i ++;
    }
    // Fifth point converted to cartesian
    else if(i == 4)
    {
      cout << endl << inputCoord << " converted to cartesian is " << inputCoord.to_cartesian() << ".";
    }
  }

  fin.close();

  // 1-norm for entire data list
  norm sum;

  cout << "\nThe sum of the vectors is " << sum(vect) << ".\n\n";

  return 0;
}
