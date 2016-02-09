//////////////////////////////////////////////////////////////////////
/// @file vectorexception.h
/// @author Christine Wang CS5201
/// @brief Vector Exception Class and Functions
//////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// 
/// @fn vectorException(const int type)
/// @brief Constructor for vectorException Class
/// @pre N/A
/// @post An instance of the class is created with type of given parameter
/// @param - type - type of exception: 1)divide by zero 2)vector out of bound
/// @return N/A
////////////////////////////////////////////////////////////////////// 

////////////////////////////////////////////////////////////////////// 
/// @fn message()
/// @brief Uses cout to display the type of error which occurred
/// @pre N/A
/// @post N/A
/// @return void - nothing returned
////////////////////////////////////////////////////////////////////// 

#ifndef VECTOREXCEPTION_H
#define VECTOREXCEPTION_H

class VectorException: public exception
{
  private:
    int m_type;
  public:
    VectorException(const int type){m_type=type;}
		void  message() const throw()
    {
    	cerr << "\nERROR: ";
      if(m_type==0)	cout << "INVALID SIZE\n";
      else if(m_type==1)	cout << "INDEX OUT OF BOUNDS\n";
      else if(m_type==2)	cout << "VECTORS MUST BE THE SAME SIZE\n";
    }
};

#endif
