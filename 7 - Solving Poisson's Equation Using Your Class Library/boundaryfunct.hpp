///////////////////////////////////////////////////////////////////////////////////////
/// @file boundaryfunct.hpp						 									///
/// @author Jeff Goymerac and Christine Wang                                        ///
/// @brief This is Boundary Function Class that is used for function calling        ///
///        In The PDEGen class                                                      ///
///                                                                                 ///
///////////////////////////////////////////////////////////////////////////////////////

template<class T>
double BoundaryFunct<T> :: operator()(const double x, const double y)
{
	if(x==0)
		return sin(y);
	if(y==0)
		return sin(x);
	return 0;
}