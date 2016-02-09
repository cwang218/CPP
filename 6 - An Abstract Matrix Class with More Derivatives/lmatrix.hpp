//////////////////////////////////////////////////////////////////////
/// @file lmatrix.hpp
/// @author Christine Wang CS5201
/// @brief Lower Triangular LMatrix Class
//////////////////////////////////////////////////////////////////////

template<class T>
LMatrix<T> :: LMatrix()
{
	m_dimension = 0;
	m_ptr_to_data = 0;
}
	
template<class T>
LMatrix<T> :: LMatrix(int dimension)
{
	//if(dimension<0)	throw Exception(0);

	m_dimension = dimension;
	
	m_ptr_to_data = new vector<T>[dimension];

	for(int i=0; i<dimension; i++)
	{
		m_ptr_to_data[i].setSize(i+1);
		for(int j=0; j<i+1; j++)
		{
			m_ptr_to_data[i][j]=0;
		}
	}
}

template<class T>
LMatrix<T> :: LMatrix(const LMatrix<T>& source)
{
	copy(source);
}

template<class T>
LMatrix<T> :: ~LMatrix()
{
	clean();
}

template<class T>
void LMatrix<T> :: clean()
{
	delete [] m_ptr_to_data;
}

template<class T>
vector<T>& LMatrix<T> :: operator[](const int i)
{
	//if(i<0 || i>= m_dimension)	throw Exception(2);
	return m_ptr_to_data[i];
}

template<class T>
vector<T> LMatrix<T> :: operator[](const int i) const
{
	//if(i<0 || i>= m_dimension)	throw Exception(2);
	return m_ptr_to_data[i];
}

template<class T>
LMatrix<T>& LMatrix<T> :: operator=(const LMatrix<T>& source)
{
	if(m_ptr_to_data != source.m_ptr_to_data)
	{
		m_dimension = source.m_dimension;
		m_ptr_to_data = new vector<T>[m_dimension];
		for(int x=0; x<m_dimension; x++)
		{
			m_ptr_to_data[x].setSize(x+1);
		}
	}
	copy(source);
	return *this;
}

template<class T>
void LMatrix<T> :: setsize(const int dimension)
{
	if(m_dimension!=dimension)
	{
		clean();
		m_ptr_to_data = new vector<T>(dimension);
		for(int i=0; i<m_dimension; i++)
		{
			m_ptr_to_data[i].setSize(i+1);
			for(int j=0; j<m_ptr_to_data[i].getSize(); j++)
				m_ptr_to_data[i][j] = 0;
		}
	}
}

template<class S>
ostream& operator <<(ostream& out, const LMatrix<S>& source)
{
	for(int i=0; i<source.dimension(); i++)
	{
			out << source.m_ptr_to_data[i] << endl;
	}
	return out;
}

template<class T>
void LMatrix<T> :: copy(const LMatrix<T>& source)
{
	m_dimension=source.m_dimension;
	for(int i=0; i<source.m_dimension; i++)
	{
		m_ptr_to_data[i].setSize(source.m_dimension);
		for(int j=0; j<i+1; j++)
		{
			m_ptr_to_data[i][j]=source[i][j];
		}
	}
}
