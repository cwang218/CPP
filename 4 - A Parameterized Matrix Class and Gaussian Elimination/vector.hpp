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
	if(size<0)	throw Exception(0);
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
	if(index<0 || index >= m_size)	throw Exception(1);
	return m_ptr_to_data[index];
}

template<class T>
const T& vector<T> :: operator[](const int index) const
{
	if(index<0 || index >= m_size)	throw Exception(1);
	return m_ptr_to_data[index];
}

template<class T>
vector<T>& vector<T> :: operator=(const vector<T>& source)
{
	if(m_ptr_to_data != source.m_ptr_to_data)
	{
		clean();
		setSize(source.m_size);
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
	if(m_size != source.m_size)	throw Exception(2);
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
	if(m_size != source.m_size)	throw Exception(2);
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
	if(m_size != source.m_size)	throw Exception(2);
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
	for(int x=0; x<getSize(); x++)
		m_ptr_to_data[x] = m_ptr_to_data[x]*mult;
}


template<class T>
int vector<T> :: getSize() const
{
	return m_size;
}

template<class T>
void vector<T> :: setSize(const int size)
{
	if(size < 0)	throw Exception(0);
	if(size != m_size)
	{
		clean();
		m_size = size;
		m_ptr_to_data = new T[size];
	}
}

template<class T>
T vector<T> :: findAbsMax()
{
	if(m_size==0)	throw Exception(3);
	T max = m_ptr_to_data[0];
	for(int x=1; x<m_size; x++)
	{
		if(m_ptr_to_data[x]>max)
			max = m_ptr_to_data[x];
	}
	return max;
}

template<class S>
ostream& operator <<(ostream& out, vector<S>& source)
{
	out << "<";
	for(int x=0; x<source.getSize(); x++)
	{
		out << source[x];
		if(x<source.getSize()-1)
			out << ", ";
	}
	out << ">";
	return out;
}

template<class S>
istream& operator >>(istream& in, vector<S>& source)
{
	for(int x=0; x<source.getSize(); x++)
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
