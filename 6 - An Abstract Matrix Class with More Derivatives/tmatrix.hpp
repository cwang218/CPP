//////////////////////////////////////////////////////////////////////
/// @file tmatrix.hpp
/// @author Christine Wang CS5201
/// @brief Tridiagonal Matrix Class
//////////////////////////////////////////////////////////////////////

template<class T>
void TMatrix<T> :: copy(const TMatrix<T>& source)
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
		int size;
		if(i==0 || i==m_dimension-1)
			size = 2;
		else
			size = 3;

		m_ptr_to_data[i] = new T[size];

		for(int j=0; j<size; j++)
		{
			m_ptr_to_data[i][j] = source(i,j);
		}
	}
}

template<class T>
TMatrix<T> :: TMatrix(const int dim)
{
	m_dimension = dim;
	m_ptr_to_data = new T*[m_dimension];
	for(int i=0; i<m_dimension; i++)
	{
		int size;
		if(i==0 || i==m_dimension-1)
			size = 2;
		else
			size = 3;

		m_ptr_to_data[i] = new T[size];

		for(int j=0; j<size; j++)
		{
			m_ptr_to_data[i][j] = 0;
		}
	}
}


template<class T>
T& TMatrix<T> :: operator()(const int i, const int j)
{
	if(i==j)
		return m_ptr_to_data[i][1];
	if(i==(j+1))
		return m_ptr_to_data[i][0];
	if(j==(i+1))
		return m_ptr_to_data[i][2];
	return 0;
}

template<class T>
T TMatrix<T> :: operator()(const int i, const int j) const
{
	if(i==j)
		return m_ptr_to_data[i][1];
	if(i==(j+1))
		return m_ptr_to_data[i][0];
	if(j==(i+1))
		return m_ptr_to_data[i][2];
	return 0;
}

template<class T>
MatrixBase<T>& TMatrix<T> :: operator=(const MatrixBase<T>& source)
{
	copy(source);
	return *this;
}

template<class T>
MatrixBase<T>& TMatrix<T> :: operator+(const MatrixBase<T>& source)
{
	for(int i=0; i<m_dimension; i++)
	{
		for(int j=0; j<m_ptr_to_data[i].size(); j++)
		{
			m_ptr_to_data[i][j] = m_ptr_to_data[i][j] + source(i,j);
		}
	}
	return *this;
}

template<class T>
MatrixBase<T>& TMatrix<T> :: operator-(const MatrixBase<T>& source)
{
	for(int i=0; i<m_dimension; i++)
	{
		for(int j=0; j<m_ptr_to_data[i].size(); j++)
		{
			m_ptr_to_data[i][j] = m_ptr_to_data[i][j] - source(i,j);
		}
	}
	return *this;
}

template<class T>
MatrixBase<T>& TMatrix<T> :: operator-()
{
	for(int i=0; i<m_dimension; i++)
	{
		for(int j=0; j<m_ptr_to_data[i].size(); j++)
		{
			m_ptr_to_data[i][j] = m_ptr_to_data[i][j]*(-1);
		}
	}
	return *this;
}

template<class T>
MatrixBase<T>& TMatrix<T> :: operator*(const MatrixBase<T>& source)
{
/*	if(m_dimension != source.m_dimension)
	{
		throw MatrixException(2);
	}*/
	MatrixBase<T> product(m_dimension);
	T sum = 0;

	for(int i=0; i<m_dimension; i++)
	{
		for(int j=0; j<4; j++)
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
MatrixBase<T>& TMatrix<T> :: operator*(const T scalar)
{
	for(int i=0; i<m_dimension; i++)
	{
		int size;
		if(i==0 || i==m_dimension-1)
			size = 2;
		else
			size = 3;

		for(int j=0; j<size; j++)
		{
			m_ptr_to_data[i][j] = m_ptr_to_data[i][j] * scalar;
		}
	}
	return *this;
}

template<class S>
istream& operator >>(istream& in, MatrixBase<S>& source)
{
	for(int i=0; i<source.dimension(); i++)
	{
		for(int j=0; j<source[i].size(); j++)
		{
			if(source(i,j)!=0)
				in >> source(i,j);
		}
	}
}
