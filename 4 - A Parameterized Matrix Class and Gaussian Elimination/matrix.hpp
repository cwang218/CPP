//////////////////////////////////////////////////////////////////////
/// @file matrix.hpp
/// @brief vector Function Definition
/// @brief Matrix Class Template
//////////////////////////////////////////////////////////////////////

template<class T>
matrix<T> :: matrix()
{
	m_dimension = 0;
	m_ptr_to_data = 0;
}
	
template<class T>
matrix<T> :: matrix(int dimension)
{
	if(dimension<0)	throw Exception(0);

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
matrix<T> :: matrix(const matrix<T>& source)
{
	m_dimension = source.m_dimension;
	m_ptr_to_data = new vector<T>[m_dimension];
	matrixcopy(source);
}

template<class T>
matrix<T> :: ~matrix()
{
	clean();
}

template<class T>
void matrix<T> :: clean()
{
	delete [] m_ptr_to_data;
}

template<class T>
vector<T>& matrix<T> :: operator[](const int i)
{
	if(i<0 || i>= m_dimension)	throw Exception(2);
	return m_ptr_to_data[i];
}

template<class T>
const vector<T>& matrix<T> :: operator[](const int i) const
{
	if(i<0 || i>= m_dimension)	throw Exception(2);
	return m_ptr_to_data[i];
}

template<class T>
matrix<T>& matrix<T> :: operator=(const matrix<T>& source)
{
	if(m_ptr_to_data != source.m_ptr_to_data)
	{
		clean();
		m_dimension = source.m_dimension;
		m_ptr_to_data = new vector<T>[m_dimension];
		for(int x=0; x<m_dimension; x++)
		{
			m_ptr_to_data[x].setSize(m_dimension);
		}
	}
	matrixcopy(source);
	return *this;
}

template<class T>
bool matrix<T> :: operator==(matrix<T>& rhs) const
{
	return(m_ptr_to_data == rhs.m_ptr_to_data);
}

template<class T>
matrix<T> matrix<T> :: operator+(const matrix<T>& source) const
{
	if(m_dimension != source.m_dimension)	throw Exception(5);
	matrix<T> sum(m_dimension);
	for(int i=0; i<m_dimension; i++)
	{
			sum[i] = m_ptr_to_data[i] + source[i];
	}

	return sum;
}

template<class T>
matrix<T> matrix<T> :: operator-() const
{
	matrix<T> negate(m_dimension);
	for(int i=0; i<m_dimension; i++)
	{
		for(int j=0; j<m_dimension; j++)
		{
			negate[i][j] = (-1) * m_ptr_to_data[i][j];
		}
	}
}

template<class T>
matrix<T> matrix<T> :: operator-(const matrix<T>& source) const
{
	if(m_dimension != source.m_dimension)	throw Exception(5);
	
	matrix<T> difference(m_dimension);
	
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
matrix<T> matrix<T> :: operator*(const matrix<T>& source) const
{
	if(m_dimension != source.m_dimension)	throw Exception(5);
	
	matrix<T> product(m_dimension);

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
matrix<T> matrix<T> :: operator*(const vector<T>& source) const
{
	if(m_dimension != source.getSize())	throw Exception(4);
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
matrix<T> matrix<T> :: operator*(const T mult) const
{
	matrix<T> product(m_dimension);
	for(int i=0; i<m_dimension; i++)
	{
		for(int j=0; j<m_dimension; j++)
		{
			product[i][j] = mult * this[i][j];
		}
	}

	return product;
}

template<class T>
int matrix<T> :: getDimension() const
{
	return m_dimension;
}

template<class T>
void matrix<T> :: setDimension(const int dimension)
{
	if(dimension < 0)	throw Exception(0);
	if(dimension != m_dimension)
	{
		clean();
		m_dimension = dimension;
		m_ptr_to_data = new vector<T>[dimension];
		for(int i=0; i<dimension; i++)
		{
			m_ptr_to_data[i].setSize(dimension);
		}
	}
}

template<class T>
matrix<T> matrix<T> :: transpose() const
{
	matrix<T> transpose(m_dimension);
	for(int i=0; i<m_dimension; i++)
	{
		for(int j=0; j<m_dimension; j++)
		{
			transpose[i][j]=m_ptr_to_data[j][i];
		}
	}
	return transpose;
}

template<class S>
ostream& operator <<(ostream& out, const matrix<S>& source)
{
	for(int i=0; i<source.getDimension(); i++)
	{
		out << source.m_ptr_to_data[i] << endl;
	}
	return out;
}

template<class S>
istream& operator >>(istream& in, matrix<S>& source)
{
	for(int i=0; i<source.getDimension(); i++)
	{
		for(int j=0; j<source.getDimension(); j++)
		{
			in >> source[i][j];
		}
	}
	return in;
}

template<class T>
void matrix<T> :: matrixcopy(const matrix<T>& source)
{
	m_dimension=source.m_dimension;
	for(int i=0; i<m_dimension; i++)
	{
		m_ptr_to_data[i]=source[i];
	}
}
