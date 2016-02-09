//////////////////////////////////////////////////////////////////////
/// @file dmatrix.hpp
/// @author Christine Wang CS5201
/// @brief Diagonal Matrix Class
//////////////////////////////////////////////////////////////////////

template<class T>
void DMatrix<T> :: copy(const DMatrix<T>& source)
{
	if(m_dimension > 0)
	{
		for(int i=0; i<m_dimension; i++)
		{
			delete [] m_ptr_to_data[i];
		}
		delete [] m_ptr_to_data;
	}

	m_dimension = source.m_dimension;
	m_ptr_to_data = new T*[m_dimension];

	for(int i=0; i<m_dimension; i++)
	{
		m_ptr_to_data[i] = new T[1];
		m_ptr_to_data[i] = source[i,i];
	}
}

template<class T>
DMatrix<T> :: DMatrix(const int dim)
{
	m_dimension = dim;
	m_ptr_to_data = new T*[m_dimension];
	for(int i=0; i<m_dimension; i++)
	{
		m_ptr_to_data[i] = new T[1];
	}
}

template<class T>
DMatrix<T> :: DMatrix(const int DMatrix<T>& source)
{
	copy(source);
}

template<class T>
T& DMatrix<T> :: operator()(const int i, const int j)
{
	if(i==j)
		return m_ptr_to_data[i][0];
	return 0;
}

template<class T>
T DMatrix<T> :: operator()(const int i, const int j) const
{
	if(i==j)
		return m_ptr_to_data[i][0];
	return 0;
}

template<class T>
MatrixBase<T>& DMatrix<T> :: operator+(const MatrixBase<T>& source)
{
	for(int i=0; i<m_dimension; i++)
	{
		m_ptr_to_data[i][0] = m_ptr_to_data[i][0] + source.m_ptr_to_data[i][0];
	}
	return *this;
}

template<class T>
MatrixBase<T>& DMatrix<T> :: operator-(const MatrixBase<T>& source)
{
	for(int i=0; i<m_dimension; i++)
	{
		m_ptr_to_data[i][0] = m_ptr_to_data[i][0] - source.m_ptr_to_data[i][0];
	}
	return *this;
}

template<class T>
MatrixBase<T>& DMatrix<T> :: operator-()
{
	for(int i=0; i<m_dimension; i++)
	{
		m_ptr_to_data[i][0] = m_ptr_to_data[i][0]*(-1);
	}
	return *this;
}

template<class T>
MatrixBase<T>& DMatrix<T> :: operator*(const MatrixBase<T>& source)
{
/*	if(m_dimension != source.m_dimension)
	{
		throw MatrixException(2);
	}*/
	MatrixBase<T> product(m_dimension);
	T sum = 0;

	for(int i=0; i<m_dimension; i++)
	{
		for(int j=0; j<m_dimension; j++)
		{
			for(int k=0; k<m_dimension; k++)
			{
				sum = sum + (m_ptr_to_data[i][k]*source(k,j));
			}
			product(i,j) = sum;
			sum = 0;
		}
	}
	copy(product);
	return *this;
}

template<class T>
MatrixBase<T>& DMatrix<T> :: operator*(const T scalar)
{
	for(int i=0; i<m_dimension; i++)
	{
		m_ptr_to_data[i][0] = m_ptr_to_data[i][0] * scalar;
	}
	return *this;
}
