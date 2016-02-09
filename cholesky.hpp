//////////////////////////////////////////////////////////////////////
/// @file cholesky.hpp
/// @author Christine Wang
/// @brief Cholesky Decomposition Class
//////////////////////////////////////////////////////////////////////


template<class T>
Cholesky<T> :: Cholesky(SymMatrix<T> s, MyVect<T> v)
{
	SymMatrix<T> m_a(s);
	MyVect<T> m_b(v);
	MyVect<T> m_z(v.size());
	MyVect<T> m_x(v.size());
	LMatrix<T> m_l(s.size());

	int n = s.size();
	double sum = 0;

	//decomp
	for(int k=0; k<n; k++)
	{
		for(int i=0; i<m_l[k].size(); i++)
		{
			if(i!=k)
			{
				sum = m_a[k][i];
				for(int j=0; j<i; j++)
				{
					sum -= m_l[i][j]*m_l[k][j];
				}
				sum /= m_l[i][i];
				m_l[k][i] = sum;	
			}
			else
			{
				sum = m_a[k][k];
				for(int j=0; j<k; j++)
				{
					sum -= pow(m_l[k][j],2);
				}
				m_l[k][k] = sqrt(sum);
			}
		}
	}

	//forward substitution
	for(int i=0; i<n; i++)
	{
		m_z[i] = m_b[i];
		for(int j=0; j<i; j++)
			m_z[i] -= m_l[i][j]*m_z[j];
		m_z[i]/=m_l[i][i];
	}

	//back substitution
	m_x[n-1] = m_z[n-1]/m_l[n-1][n-1];
	for(int i=n-2; i>=0; i--)
	{
		m_x[i]=m_z[i];
		for(int j=i+1; j<n; j++)
			m_x[i] -= m_l[j][i]*m_x[j];
		m_x[i]/=m_l[i][i];
	}
	

	cout << m_x << endl << endl;
}
