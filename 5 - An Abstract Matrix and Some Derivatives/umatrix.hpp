//////////////////////////////////////////////////////////////////////
/// @file umatrix.hpp
/// @author Christine Wang CS5201
/// @brief Upper Triangular UMatrix Class
//////////////////////////////////////////////////////////////////////


template<class T>
UMatrix<T> :: UMatrix()
{
	m_dimension = 0;
	m_ptr_to_data = 0;
}
	
template<class T>
UMatrix<T> :: UMatrix(int dimension)
{
	//if(dimension<0)	throw Exception(0);

	m_dimension = dimension;
	
	m_ptr_to_data = new vector<T>[dimension];

	for(int i=0; i<dimension; i++)
	{
		m_ptr_to_data[i].setSize(dimension);
		for(int j=0; j<dimension-i; j++)
		{
			m_ptr_to_data[i][j]=0;
		}
	}
}

template<class T>
UMatrix<T> :: UMatrix(const UMatrix<T>& source)
{
	copy(source);
}

template<class T>
UMatrix<T> :: ~UMatrix()
{
	clean();
}

template<class T>
void UMatrix<T> :: clean()
{
	delete [] m_ptr_to_data;
}

template<class T>
vector<T>& UMatrix<T> :: operator[](const int i)
{
	//if(i<0 || i>= m_dimension)	throw Exception(2);
	return m_ptr_to_data[i];
}

template<class T>
vector<T> UMatrix<T> :: operator[](const int i) const
{
	//if(i<0 || i>= m_dimension)	throw Exception(2);
	return m_ptr_to_data[i];
}

template<class T>
UMatrix<T>& UMatrix<T> :: operator=(const UMatrix<T>& source)
{
	if(m_ptr_to_data != source.m_ptr_to_data)
	{
		m_dimension = source.m_dimension;
		m_ptr_to_data = new vector<T>[m_dimension];
		for(int x=0; x<m_dimension; x++)
		{
			m_ptr_to_data[x].setSize(m_dimension-x);
		}
	}
	copy(source);
	return *this;
}

template<class T>
void UMatrix<T> :: setsize(const int dimension)
{
	if(m_dimension!=dimension)
	{
		clean();
		m_ptr_to_data = new vector<T>(dimension);
		for(int i=0; i<m_dimension; i++)
		{
			m_ptr_to_data[i].setSize(dimension-i);
			for(int j=0; j<m_ptr_to_data[i].getSize(); j++)
				m_ptr_to_data[i][j] = 0;
		}
	}
}

template<class S>
ostream& operator <<(ostream& out, const UMatrix<S>& source)
{
	for(int i=0; i<source.dimension(); i++)
	{
			out << source.m_ptr_to_data[i] << endl;
	}
	return out;
}

template<class T>
void UMatrix<T> :: copy(const UMatrix<T>& source)
{
	m_dimension=source.m_dimension;
	for(int i=0; i<source.m_dimension; i++)
	{
		m_ptr_to_data[i].setSize(source.m_dimension);
		for(int j=0; j<source.m_dimension-i; j++)
		{
			m_ptr_to_data[i][j]=source[i][j];
		}
	}
}
