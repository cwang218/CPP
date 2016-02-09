//////////////////////////////////////////////////////////////////////
/// @file gauss-seidel.hpp
/// @author Christine Wang CS5201
/// @brief GaussSeidel Iteration Function Definition
//////////////////////////////////////////////////////////////////////

template<class T>
GaussSeidel<T> :: GaussSeidel(vector<vector<T> >& source, double tolerance)
{
	m_vectors.setsize(source.getsize());

	for(int i=0; i<source.getsize(); i++)
	{
		m_vectors[i].setsize(source.getsize());
	}

	m_xs.setsize(source.getsize());
	m_xs=0;
	m_tolerance = tolerance;
}

template<class T>
void GaussSeidel<T> :: solve()
{
	// check if v1 and v2 are multiples of each other
	bool solved = checkMultiple();	
	
	// if not multiples, use gauss-seidel iteration
	if(!solved)
		solved = iteration(m_xs,2);

	printResult(solved);	
}

template<class T>
bool GaussSeidel<T> :: checkMultiple()
{
	vector<T> vect1 = m_vectors[0];
	vector<T> vect2 = m_vectors[1];

	double mult = vect1[0]/vect2[0];

	for(int x=1; x<vect1.getsize(); x++)
	{
		// check if all quotients of variables are the same
		// if not, return false
		if(vect1[x]/vect2[x]!= mult)
			return false;
	}
	return true;
}

template<class T>
bool GaussSeidel<T> :: iteration(vector<T>& x_old, int num)
{
	m_xs.setsize(num);

	double error=1;
	double currerror=1;
	double olderror=1;

	// set first guesses for x-values
	m_xs[0] = m_vectors[num][0] / m_vectors[0][0];
	for(int x=1; x<num; x++)
	{
		m_xs[x] = m_vectors[num][x];
		for(int y=x-1; y<num; y++)
		{
			if(y==x)
			{
				y++;
			}
			m_xs[x] -= (m_xs[y]*m_vectors[y][x]);
		}
		m_xs[x] /= m_vectors[x][x];
	}

	error = 1;

	// calculate error for guesses, save largest
	for(int x=0; x<num; x++)
	{
		currerror = (m_xs[x]-x_old[x])/m_xs[x];
		if(currerror>error || error == 1)
			error = currerror;
	}

	// if not converging, try again with one more vector
	if(error > olderror)
	{
		return iteration(m_xs, num);
	}
	else
	{
		vector<T> sum;
		vector<T> rhs;
		sum.setsize(num);
		rhs.setsize(num);
		sum=0;

		// check if x-values satisfy equation
		for(int x=0; x<num; x++)
		{
			sum[x] += (m_vectors[x][x]*m_xs[x]);
			rhs[x] = m_vectors[num][x];
		}

		// if correct x-values, linearly dependent
		if(sum==rhs)
		{
			return false;
		}
		else
		{
			num++;
			// if all vectors have been checked, linearly independent
			if(num>=m_vectors.getsize())
			{
				return true;
			}
			// if x-values not valid and not all vectors have been checked,
			// try again with one more vector
			return iteration(m_xs, num);
		}
	
	}

}

template<class T>
void GaussSeidel<T> :: printResult(bool result)
{
	cout << "The vectors are ";
	if(result)
	{
		cout << "linearly independent." << endl;
	}
	else
	{
		cout << "linearly dependent." << endl
				 << "Linear combination found: " << m_xs << endl;
	}
	cout << "Tolerance: " << m_tolerance << endl << endl;
}
