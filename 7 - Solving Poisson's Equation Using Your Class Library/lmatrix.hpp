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
	m_dimension = dimension;
	m_ptr_to_data = new MyVect<T>[m_dimension];
	for(int i=0; i<m_dimension; i++)
	{
		m_ptr_to_data[i].setSize(i+1);
	}

	for(int i=0; i<m_dimension; i++)
	{
		for(int j=0; j<i+1; j++)
		{
			m_ptr_to_data[i][j] = 0;
		}
	}
}


template<class T>
LMatrix<T> :: LMatrix(const LMatrix<T>& source)
{
	m_dimension = source.m_dimension;
	m_ptr_to_data = new MyVect<T>[m_dimension];
	copy(source);
}


template<class T>
LMatrix<T> :: ~LMatrix()
{
	clean();
}


template <class T>
MyVect<T>& LMatrix<T>::operator [] (int i)
{
    return m_ptr_to_data[i];
}

template <class T>
const MyVect<T>& LMatrix<T>::operator[] (int i)const
{
    return m_ptr_to_data[i];
}

template<class T>
T& LMatrix<T> :: operator()(const int i, const int j)
{
	T ret = 0;
	if(j>i)
		return ret;
	else
		return m_ptr_to_data[i][j];
}

template<class T>
T LMatrix<T> :: operator()(const int i, const int j) const
{
	T ret = 0;
	if(j>i)
		return ret;
	else
		return m_ptr_to_data[i][j];
}

template<class T>
LMatrix<T>& LMatrix<T> :: operator=(const LMatrix<T>& source)
{
	copy(source);
	return *this;
}

template<class T>
LMatrix<T>& LMatrix<T> :: operator+(const LMatrix<T>& source)
{
//		if(m_dimension != source.m_dimension)	throw Exception(5);
		LMatrix<T> sum(m_dimension);

		for(int i=0; i<m_dimension; i++)
		{
			for(int j=0; j<i+1; j++)
			{
				sum(i,j) = m_ptr_to_data[i][j] + source(i,j);
			}
		}

		copy(sum);
		return *this;
}

template<class T>
LMatrix<T>& LMatrix<T> :: operator-(const LMatrix<T>& source)
{
//		if(m_dimension != source.m_dimension)	throw Exception(5);
		LMatrix<T> difference(m_dimension);

		for(int i=0; i<m_dimension; i++)
		{
			for(int j=0; j<i+1; j++)
			{
				difference(i,j) = m_ptr_to_data[i][j] - source(i,j);
			}
		}

		copy(difference);
		return *this;
}

template<class T>
LMatrix<T>& LMatrix<T> :: operator-()
{
//		if(m_dimension != source.m_dimension)	throw Exception(5);
		LMatrix<T> negative(m_dimension);

		for(int i=0; i<m_dimension; i++)
		{
			for(int j=0; j<i+1; j++)
			{
				negative(i,j) = m_ptr_to_data[i][j]*(-1);
			}
		}

		copy(negative);
		return *this;
}

template<class T>
LMatrix<T>& LMatrix<T> :: operator*(const T mult)
{
//		if(m_dimension != source.m_dimension)	throw Exception(5);
		LMatrix<T> product(m_dimension);

		for(int i=0; i<m_dimension; i++)
		{
			for(int j=0; j<i+1; j++)
			{
				product(i,j) = m_ptr_to_data[i][j] * mult;
			}
		}

		copy(product);
		return *this;
}


template<class T>
void LMatrix<T> :: copy(const LMatrix<T>& source)
{
	clean();
	m_dimension = source.size();
	m_ptr_to_data = new MyVect<T>[m_dimension];
	for(int i=0; i<m_dimension; i++)
	{
		m_ptr_to_data[i].setSize(i+1);
	}

	for(int i=0; i<m_dimension; i++)
	{
		for(int j=0; j<i+1; j++)
		{
			m_ptr_to_data[i][j] = source(i,j);
		}
	}
}

template <class T>
MyVect<T> &LMatrix<T>:: operator* (const MyVect<T> &s)
{
    if (m_dimension != s.size ())
    {
        throw MatrixError(2);
    }
    MyVect<T> *pro;
    pro = new MyVect<T> (m_dimension);
    for (int i = 0; i < m_dimension; i++)
    {
        pro[i] = 0;
        for (int j = 0; j < i+1; j++)
        {
            pro[i] = pro[i] + (m_ptr_to_data[i][j] * s[i]);
        }
    }
    return *pro;
}


template<class T>
void LMatrix<T> :: clean()
{
	delete [] m_ptr_to_data;
}

template<class T>
UMatrix<T>& LMatrix<T> :: transpose()
{
	UMatrix<T> u(size());
	for(int i=0; i<size(); i++)
	{
		for(int j=0; j<i+1; j++)
			u[j][i] = m_ptr_to_data[i][j];
	}
}

template<class S>
ostream& operator <<(ostream& out, const LMatrix<S>& source)
{
	for(int i=0; i<source.size(); i++)
	{
		out << "| ";
		for(int j=0; j<i+1; j++)
		{
			out << source(i,j) << " ";
		}
		for(int j=i+1; j<source.size(); j++)
		{
			out << "0 ";
		}
		out << " |\n";
	}
	return out;
}

template<class S>
istream& operator >>(istream& in, LMatrix<S>& source)
{
	for(int i=0; i<source.size(); i++)
	{
		for(int j=0; j<i+1; j++)
		{
			in >> source(i,j);
		}
	}
	return in;
}
