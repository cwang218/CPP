//////////////////////////////////////////////////////////////////////
/// @file smatrix.hpp
/// @author Christine Wang CS5201
/// @brief Symmetric Matrix Class
//////////////////////////////////////////////////////////////////////

template<class T>
void SMatrix<T> :: copy(const SMatrix<T>& source)
{
	if(this!=source)
	{
		if(m_dimension > 0)
	{
		for(int i=0; i<m_dimension; i++)
		{
			delete [] m_ptr_to_data[i];
		}
		delete [] m_ptr_to_data;
	}

		m_ptr_to_data = new T*[this->m_dimension];
		for(int i=0; i<m_dimension; i++)
		{
			m_ptr_to_data = new T[i+1];
			for(int j=0; j<i+1; j++)
			{
				m_ptr_to_data[i][j] = source(i,j);
			}
		}
	}
}

template<class T>
SMatrix<T> :: SMatrix(const int dim)
{
	m_dimension = dim;
	m_ptr_to_data = new T*[m_dimension];

	for(int i=0; i<m_dimension; i++)
	{
		for(int j=0; j<m_dimension; j++)
		{
			m_ptr_to_data[i][j] = new T[i+1];
		}
	}
}

template<class T>
T& SMatrix<T> :: operator()(const int i, const int j)
{
	if(i>=j)	return m_ptr_to_data[i][j];
	return m_ptr_to_data[j][i];
}

template<class T>
T SMatrix<T> :: operator()(const int i, const int j) const
{
	if(i>=j)	return m_ptr_to_data[i][j];
	return m_ptr_to_data[j][i];
}

template<class S>
istream& operator >>(istream& in, MatrixBase<S>& source)
{
	for(int i=0; i<source.dimension(); i++)
	{
		for(int j=0; j<source.dimension(); j++)
		{
			in >> source(i,j);
		}
	}
}
