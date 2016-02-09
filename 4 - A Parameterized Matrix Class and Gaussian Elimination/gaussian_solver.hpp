//////////////////////////////////////////////////////////////////////
/// @file gaussian_solver.hpp
/// @brief Gaussian Elimination with Scaled Partial Pivoting
///				 Function Definition
/// @brief Gaussian Solver Class Template
//////////////////////////////////////////////////////////////////////

template<class T>
GaussianSolver<T> :: GaussianSolver(const matrix<T>& source_A, const vector<T>& source_B)
{
	m_dim = source_B.getSize();
	m_scalars = new T[source_B.getSize()];
	m_A = source_A;
	m_B = source_B;
	m_X.setSize(m_dim);
}

template<class T>
void GaussianSolver<T> :: solve()
{
	fillScalars();

	for(int x=0; x<m_dim; x++)
	{
		swap(x, findBiggest(x));
		eliminate(x);
	}
	substitute();
	printResult();
}

template<class T>
void GaussianSolver<T> :: fillScalars()
{
	for(int x=0; x<m_dim; x++)
	{
		m_scalars[x] = m_A[x].findAbsMax();
	}
}

template<class T>
void GaussianSolver<T> :: swap(int index1, int index2)
{
	vector<T>*	 tempA = new vector<T>(m_A[index1]);
	T tempB = m_B[index1];

	m_A[index1] = m_A[index2];
	m_B[index1] = m_B[index2];

	m_A[index2] = *tempA;
	m_B[index2] = 	tempB;
}

template<class T>
void GaussianSolver<T> :: eliminate(int row)
{
	if(row<0 || row>=m_dim)	throw Exception(1);
	for(int j=row+1; j<m_dim; j++)
	{
		vector<T>* curr_row = new vector<T>(m_A[j]);
		vector<T>* subtract = new vector<T>(m_A[row]*(m_A[j][row]/m_A[row][row]));
		m_A[row] = curr_row - subtract;
	}
}

template<class T>
void GaussianSolver<T> :: substitute()
{
	if(m_dim == 0)	throw Exception(3);
	m_X[m_dim-1] = m_B[m_dim-1]/m_A[m_dim-1][m_dim-1];
	for(int i=m_dim-2; i>=0; i--)
	{
		float summation = 0;
		for(int j=i+1; j<m_dim; j++)
		{
			summation += m_A[i][j]*m_X[j];
		}
		m_X[i] = (1/m_A[i][i])*(m_B[i]-summation);
	}
}

template<class T>
int GaussianSolver<T> :: findBiggest(int row)
{
	if(row<0 || row>=m_dim)	throw Exception(1);
	T max = m_A[0][row]/m_scalars[0];
	int max_index = 0;
	for(int x=row+1; x<m_dim; x++)
	{
		T temp = m_A[x][row]/m_scalars[x];
		if(temp >= max)
		{
			max_index = x;
			max = temp;
		}
	}
	return max_index;
}

template<class T>
void GaussianSolver<T> :: printResult()
{
	if(m_X.getSize() == 0) throw(3);
	cout << "\n\nThe solution is:\n";

	for(int x=0; x<m_dim; x++)
	{
		cout << "x" << x+1 << "=" << m_X[x] << endl;
	}
	cout << endl << endl;
}
