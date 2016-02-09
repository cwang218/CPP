//////////////////////////////////////////////////////////////////////
/// @file Matrix.hpp
/// @brief vector Function Definition
/// @brief Matrix Class Template
//////////////////////////////////////////////////////////////////////

template<class T>
Matrix<T> :: Matrix()
{
	m_dimension = 0;
	m_ptr_to_data = 0;
}
	
template<class T>
Matrix<T> :: Matrix(int dimension)
{
	//if(dimension<0)	throw Exception(0);

	m_dimension = dimension;
	
	m_ptr_to_data = new vector<T>[dimension];

	for(int i=0; i<dimension; i++)
	{
		m_ptr_to_data[i].setSize(dimension);
		for(int j=0; j<dimension; j++)
		{
			m_ptr_to_data[i][j]=0;
		}
	}
}

template<class T>
Matrix<T> :: Matrix(const Matrix<T>& source)
{
	copy(source);
}

template<class T>
Matrix<T> :: ~Matrix()
{
	clean();
}

template<class T>
void Matrix<T> :: clean()
{
	delete [] m_ptr_to_data;
}

template<class T>
vector<T>& Matrix<T> :: operator[](const int i)
{
	//if(i<0 || i>= m_dimension)	throw Exception(2);
	return m_ptr_to_data[i];
}

template<class T>
vector<T> Matrix<T> :: operator[](const int i) const
{
	//if(i<0 || i>= m_dimension)	throw Exception(2);
	return m_ptr_to_data[i];
}

template<class T>
Matrix<T>& Matrix<T> :: operator=(const Matrix<T>& source)
{
	if(m_ptr_to_data != source.m_ptr_to_data)
	{
		if(m_dimension!=0)
			clean();
		m_dimension = source.m_dimension;
		m_ptr_to_data = new vector<T>[m_dimension];
		for(int x=0; x<m_dimension; x++)
		{
			m_ptr_to_data[x].setSize(m_dimension);
		}
	}
	copy(source);
	return *this;
}

template<class T>
bool Matrix<T> :: operator==(Matrix<T>& rhs)
{
	return(m_ptr_to_data == rhs.m_ptr_to_data);
}

template<class T>
Matrix<T>& Matrix<T> :: operator+(const Matrix<T>& source)
{
	//if(m_dimension != source.m_dimension)	throw Exception(5);
	Matrix<T> sum(m_dimension);
	for(int i=0; i<m_dimension; i++)
	{
			sum[i] = m_ptr_to_data[i] + source[i];
	}

	return sum;
}

template<class T>
Matrix<T>& Matrix<T> :: operator-()
{
	Matrix<T> negate(m_dimension);
	for(int i=0; i<m_dimension; i++)
	{
		for(int j=0; j<m_dimension; j++)
		{
			negate[i][j] = (-1) * m_ptr_to_data[i][j];
		}
	}
}

template<class T>
Matrix<T>& Matrix<T> :: operator-(const Matrix<T>& source)
{
	//if(m_dimension != source.m_dimension)	throw Exception(5);
	
	Matrix<T> difference(m_dimension);
	
	for(int i=0; i<m_dimension; i++)
	{
		for(int j=0; j<m_dimension; j++)
		{
			difference[i][j] = m_ptr_to_data[i][j] - source[i][j];
		}
	}

	return difference;
}

template<class T>
Matrix<T>& Matrix<T> :: operator*(const Matrix<T>& source)
{
	//if(m_dimension != source.m_dimension)	throw Exception(5);
	
	Matrix<T> product(m_dimension);

	for(int i=0; i<m_dimension; i++)
	{
		for(int j=0; j<m_dimension; j++)
		{
			for(int k=0; k<m_dimension; k++)
			{
				product[i][j]+=m_ptr_to_data[i][k]*source[k][j];
			}
		}
	}
	return product;
}

template<class T>
Matrix<T>& Matrix<T> :: operator*(const vector<T>& source)
{
	//if(m_dimension != source.getSize())	throw Exception(4);
	vector<T> product(m_dimension);

	for(int i=0; i<m_dimension; i++)
	{
		for(int j=0; j<m_dimension; j++)
		{
			product[i] += m_ptr_to_data[i][j]*source[i];
		}
	}
	return product;
}

template<class T>
Matrix<T>& Matrix<T> :: operator*(const T mult)
{
	Matrix<T> product(m_dimension);
	for(int i=0; i<m_dimension; i++)
	{
		for(int j=0; j<m_dimension; j++)
		{
			product[i][j] = mult * this[i][j];
		}
	}

	return product;
}

template<class S>
ostream& operator <<(ostream& out, const Matrix<S>& source)
{
	for(int i=0; i<source.dimension(); i++)
	{
			out << source.m_ptr_to_data[i] << endl;
	}
	return out;
}

template<class S>
istream& operator >>(istream& in, Matrix<S>& source)
{
	for(int i=0; i<source.dimension(); i++)
	{
		for(int j=0; j<source.dimension(); j++)
		{
			in >> source[i][j];
		}
	}
	return in;
}

template<class T>
void Matrix<T> :: copy(const Matrix<T>& source)
{
	m_dimension=source.m_dimension;
	for(int i=0; i<m_dimension; i++)
	{
		m_ptr_to_data[i]=source[i];
	}
}
