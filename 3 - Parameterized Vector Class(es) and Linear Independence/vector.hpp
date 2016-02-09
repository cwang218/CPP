//////////////////////////////////////////////////////////////////////
/// @file vector.hpp
/// @author Christine Wang CS5201
/// @brief vector Function Definition
//////////////////////////////////////////////////////////////////////

template<class T>
vector<T> :: vector()
{
	// Empty vector by default
	m_size = 0;
	m_ptr_to_data = 0;
}

template<class T>
vector<T> :: vector(const int size)
{
	m_size=size;
	m_ptr_to_data = new T[size];	
}

template<class T>
vector<T> :: vector(const vector<T>& source)
{
	m_size  = source.m_size;
	m_ptr_to_data = new T[m_size];
	vectorcopy(source);
}

template<class T>
vector<T> :: ~vector()
{
	clean();
}

template<class T>
void vector<T> :: clean()
{
  if(m_ptr_to_data != NULL)
  {
    delete [] m_ptr_to_data;
    m_ptr_to_data = NULL;
    m_size = 0;
  }
}

template<class T>
T& vector<T> :: operator[](const int index)
{
	return m_ptr_to_data[index];
}

template<class T>
const T& vector<T> :: operator[](const int index) const
{
	return m_ptr_to_data[index];
}

template<class T>
vector<T>& vector<T> :: operator=(const vector<T>& source)
{
	if(m_ptr_to_data != source.m_ptr_to_data)
	{
		m_size = source.m_size;
		vectorcopy(source);
	}

	return *this;
}

template<class T>
vector<T>& vector<T> :: operator=(const float source)
{
	T* p = m_ptr_to_data + m_size;
	
	while(p > m_ptr_to_data)
	{
		*--p = source;
	}

	return *this;
}

template<class T>
bool vector<T> :: operator==(vector<T>& rhs) const
{
	return (m_ptr_to_data==rhs.m_ptr_to_data);
}

template<class T>
vector<T> vector<T> :: operator+(const vector<T>& source) const
{	
	vector<T> sum(m_size);	
	for(int x = 0; x < m_size; x++)
	{
		sum[x] = m_ptr_to_data[x] + source[x];
	}
	return sum;
}

template<class T>
vector<T> vector<T> :: operator-() const
{
	vector<T> negate(m_size);
	for(int x=0; x<m_size; x++)
	{
		negate[x] = (-1) * m_ptr_to_data[x];
	}
	return negate;
}

template<class T>
vector<T> vector<T> :: operator-(const vector<T>& source) const
{
	vector<T> difference(m_size);
	for(int x = 0; x < m_size; x++)
	{
		difference[x] = m_ptr_to_data[x] - source[x];
	}
	return difference;
}

template<class T>
T vector<T> :: operator*(const vector<T>& source) const
{
	T dot_product=0;
	for(int x = 0; x < m_size; x++)
	{
		dot_product += m_ptr_to_data[x]*source[x];
	}
	return dot_product;
}

template<class T>
vector<T> vector<T> :: operator*(const T mult) const
{
	for(int x=0; x<getsize(); x++)
		m_ptr_to_data[x] = m_ptr_to_data[x]*mult;
}


template<class T>
int vector<T> :: getsize() const
{
	return m_size;
}

template<class T>
void vector<T> :: setsize(const int size)
{
	if(size != m_size)
	{
		clean();
		m_size = size;
		m_ptr_to_data = new T[size];
	}
}

template<class S>
ostream& operator <<(ostream& out, vector<S>& source)
{
	out << "<";
	for(int x=0; x<source.getsize(); x++)
	{
		out << source[x];
		if(x<source.getsize()-1)
			out << ", ";
	}
	out << ">";
	return out;
}

template<class S>
istream& operator >>(istream& in, vector<S>& source)
{
	for(int x=0; x<source.getsize(); x++)
	{
		in >> source[x];
	}
	return in;
}

template<class T>
void vector<T> :: vectorcopy(const vector<T>& source)
{
	T* p = m_ptr_to_data + m_size;
	T* q = source.m_ptr_to_data + m_size;

	while(p>m_ptr_to_data)
	{
		*--p = *--q;
	}

}
