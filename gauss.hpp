/////////////////////////////////////////////////////////////////////
/// @file gauss.hpp
/// @author Christine Wang
/// @brief Gaussian Elimination Elmination Template Class
//////////////////////////////////////////////////////////////////////

template<class T>
Gauss<T> :: Gauss(Matrix<T>& A, vector<T>& B)
{
	m_A = A;
	m_B = B;
	m_X = B;
	m_Y = B;
	m_U = UMatrix<T>(A.dimension());
	m_L = LMatrix<T>(A.dimension());

	int n = m_A.dimension();

for(int k=0; k<n; k++)
{
    m_U[k][k]=1;
    for(int i=k; i<m_L[k].getSize(); i++)
    {
        float sum=0;
        for(int p=0; p<k-1; p++)
            sum+=m_L[i][p]*m_U[p][k];
        m_L[i][k]=m_A[i][k]-sum;
    }

    for(int j=k+1; j<m_U[k].getSize(); j++)
    {
        float sum=0;
        for(int p=0; p<k-1; p++)
            sum+=m_L[k][p]*m_U[p][j];
        m_U[k][j]=(m_A[k][j]-sum)/m_L[k][k];
    }
}


	//forward substitution
	for(int i=0; i<n; i++)
	{
		m_Y[i] = m_B[i];
		for(int j=0; j<i; j++)
		{
			m_Y[i] -= m_L[i][j]*m_Y[j];
		}
		m_Y[i] /= m_L[i][i];
	}


	//back substitution
	m_X[n-1]=m_Y[n-1]/m_U[n-1][n-1];
	for(int i=n-2; i>1; i--)
	{
		m_X[i] = m_Y[i];
		for(int j=i; j<n; j++)
		{
			m_X[i] += m_U[i][j]*m_Y[j];
		}
		m_X[i]/=m_U[i][i];
	}

	cout << "\nSolution Set:\n" << m_X << endl;
}
