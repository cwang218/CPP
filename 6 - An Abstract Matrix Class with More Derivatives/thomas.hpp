//////////////////////////////////////////////////////////////////////
/// @file thomas.hpp
/// @author Christine Wang CS5201
/// @brief Thomas Algorithm Class
//////////////////////////////////////////////////////////////////////


template<class T>
Thomas<T> :: Thomas(TMatrix<T> t, vector<T> v)
{
	m_a = t;
	m_b = v;
	m_l = new LMatrix<T>(m_a.dimension());
	m_u = new UMatrix<T>(m_a.dimension());
}

template<class T>
vector<T> Thomas<T> :: solve()
{
	//decomposition
	m_a(1,1) = m_a(1,1)/m_a(0,1);
	m_a(1,0) = m_a(1,0)/m_a(1,1);

	//modify array A
	for(int i=2; i<t.dimension(); i++)
	{
		m_a(i,1) = m_a(i,1)/m_a(i,0);
		m_a(i,0) = m_a(i,0)/m_a(i,1);
	}

	//LU decomposition
	for(int i=0; i< m_dimension; i++)
	{
		for(int j=0; j<=i; j++)
		{
			if(j==m_l[i].size()-1)
				m_l(i,j) = 1;
			else
				m_l(i,j+i) = m_a(i,0);
			m_u(i,j) = m_a(i,i+j);
		}
	}

	//forward substitution
	for(int i=1; i<m_b.size(); i++)
	{
		m_b[i] = m_b[i] - m_a(i,0)*m_b[i-1];
	}

	//back substitution
	m_b[m_b.size()-1] /= m_u(m_dimension-1, 0);
	for(int i=m_b.size()-2; i>=0; i--)
	{
		m_b[i] = (m_b[i]-m_u(i,1)*m_b[i-1])/m_u(i,0);
	}

	return m_b;
}
