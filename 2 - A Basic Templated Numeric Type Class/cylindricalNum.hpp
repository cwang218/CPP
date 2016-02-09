//////////////////////////////////////////////////////////////////////
/// @file cylindricalNum.hpp
/// @author Christine Wang CS5201
/// @brief cylindricalNum Function Definition
//////////////////////////////////////////////////////////////////////

template<class T>
cylindricalNum<T> :: cylindricalNum()
{
	//Default initialized to zero
	m_r = 0;
	m_theta = 0;
	m_z = 0;
}

template<class T>
cylindricalNum<T> :: cylindricalNum(const T r, const T theta, const T z)
{
	m_r = r;
	m_theta = theta;
	m_z = z;
}

template<class T>
cylindricalNum<T> :: cylindricalNum(const cylindricalNum<T>& source)
{
	m_r = source.m_r;
	m_theta = source.m_theta;
	m_z = source.m_z;
}

template<class T>
cylindricalNum<T> :: ~cylindricalNum()
{
	//Empty
}

template<class T>
cylindricalNum<T> cylindricalNum<T> :: operator -() const
{
	cylindricalNum<T> negation((-1)*(m_r), m_theta, m_z);
	return negation;
}

template<class T>
cylindricalNum<T> cylindricalNum<T> :: operator !() const
{
	cylindricalNum<T> conjugate(m_r, m_theta, (-1)*(m_z));
	return conjugate;
}

template<class T>
T cylindricalNum<T> :: operator ~() const
{
	return abs(m_r);
}

template<class T>
cylindricalNum<T> cylindricalNum<T> :: operator =(const cylindricalNum<T>& source)
{
	cylindricalNum<T> copy;

	copy.m_r = source.m_r;
	copy.m_theta = source.m_theta;
	copy.m_z = source.m_z;

	return copy;
}

template<class T>
T cylindricalNum<T> :: operator [](const int coord_choice) const
{
	if(coord_choice==0)
	{
		return m_r;
	}
	else if(coord_choice==1)
	{
		return m_theta;
	}
	else if(coord_choice==2)
	{
		return m_z;
	}
	else
	{
		return 0;
	}
}

template<class T>
bool cylindricalNum<T> :: operator <(const cylindricalNum<T>& source) const
{
	return m_r < source.m_r;
}

template<class T>
bool cylindricalNum<T> :: operator >(const cylindricalNum<T>& source) const
{
	return m_r > source.m_r;
}

template<class T>
bool cylindricalNum<T> :: operator ==(const cylindricalNum<T>& source) const
{
	return (m_z == source.m_z && m_theta == source.m_theta && m_z ==  source.m_z);
}

template<class T>
bool cylindricalNum<T> :: operator !=(const cylindricalNum<T>& source) const
{
	return !(m_z == source.m_z && m_theta == source.m_theta && m_z ==  source.m_z);
}

template<class S>
ostream& operator <<(ostream& out, const cylindricalNum<S>& source)
{
	out << "(" << source.m_r << ", " << source.m_theta << ", " << source.m_z
			<< ")";
	return out;
}

template<class S>
istream& operator >>(istream& in, cylindricalNum<S>& source)
{
	in >> source.m_r >> source.m_theta >> source.m_z;

	return in;
}

template<class T>
string cylindricalNum<T> :: to_cartesian()
{

	std::ostringstream sout;
	sout << "(" << m_r * cos(m_theta) << ", " << m_r * sin(m_theta) << ", "
			 << m_z << ")";
	std::string cart = sout.str();

	return cart;
}

template<class T>
T cylindricalNum<T> :: getR() const
{
	return m_r;
}

template<class T>
T cylindricalNum<T> :: getTheta() const
{
	return m_theta;
}

template<class T>
T cylindricalNum<T> :: getZ() const
{
	return m_z;
}
