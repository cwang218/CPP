//////////////////////////////////////////////////////////////////////
/// @file vectorexception.h
/// @author Christine Wang
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
/// @brief Uses cerr to display the type of error which occurred
/// @pre N/A
/// @post N/A
/// @return void - nothing returned
////////////////////////////////////////////////////////////////////// 

#ifndef EXCEPTION_H
#define EXCEPTION_H

class Exception
{
  public:
    Exception(const int type){m_type=type;}
		void message() const throw()
    {
      if(m_type==0)	cerr << "INVALID SIZE OR DIMENSION\n";
      else if(m_type==1)	cerr << "INDEX OUT OF BOUNDS\n";
      else if(m_type==2)	cerr << "VECTORS MUST BE THE SAME SIZE\n";
      else if(m_type==3)  cerr << "VECTOR/MATRIX MUST BE NONEMPTY\n";
      else if(m_type==4)  cerr << "VECTOR SIZE MUST BE THE SAME AS MATRIX DIMENSION\n";
      else if(m_type==5)  cerr << "MATRICES MUST BE THE SAME SIZE\n";
    }
  private:
    int m_type;
};

#endif
