///////////////////////////////////////////////////////////////////////////////////////
/// @file driver.cpp                                                                ///
/// @author Jeff Goymerac                                                           ///
/// @brief This file implements the templated Diagonal, Tridiagonal, and  Symetric  ///
///     Matrix classes                                                              ///
///                                                                                 ///
///                                                                                 ///
///////////////////////////////////////////////////////////////////////////////////////


#include "MyVect.h"
#include "Matrix.h"
#include "DMatrix.h"
#include "GausSolv.h"
#include "MatrixError.h"
#include "TriDMatrix.h"
#include "SymMatrix.h"
#include "cholesky.h"
#include "lmatrix.h"
#include "umatrix.h"
#include "pdegen.h"
#include "boundaryfunct.h"
#include "math.h"
#include <ctime>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

int main (int argc, char *argv[])
{
    try
    {
        clock_t start;
        double duration;

        int a = argc,
            b;
        a = 0;
        b=0;
        ifstream myFile;
        //const char *inFile = argv[1];
        cout<<" Enter the size of the mesh: ";
        cin >> a;
        b = pow(a-1,2);
        DMatrix<double> mat(b);
        MyVect<double> vect(b),mul(b);
        vect = 0;
        mul = 0;
        GausSolv<double> gs;
        PDEGen<double> pde;
        mat= pde(a,mat);
        vect = pde(a, vect);
        
        SymMatrix<double> A (b);
        MyVect<double> B(b);
        B = 0;
        
        A=pde(a,A);
        B=pde(a,B);

        cout << "Matrix created: " << endl << A << endl << endl; 

        cout << "Outputting the solution to Ax=b using Gaussian Elimination" << endl;
        //cout<<"Matrix:\n"<<mat;
        start = clock();
        mul = gs (mat, vect);
        cout << "Solution:\n"<<mul << endl;
        duration = (clock()-start)/(double) CLOCKS_PER_SEC;
        cout << "\nTime to run Gaussian Elimination: " << duration << " seconds" << endl << endl;


        cout << "Outputting the solution to Ax=b using Cholesky Decomposition" << endl;
        //cout<<"Matrix:\n"<<A;
        cout<< "Solution:\n";
        start = clock();
        Cholesky<double> ch(A,B);
        duration = (clock()-start)/(double) CLOCKS_PER_SEC;
        cout << "\nTime to run Cholesky Decomposition: " << duration << " seconds" << endl << endl;

    }
    catch (MatrixError& e)
    {
        cout << "An Error occured\n" ;
        e.message(); 
    }
    return 0;
}


