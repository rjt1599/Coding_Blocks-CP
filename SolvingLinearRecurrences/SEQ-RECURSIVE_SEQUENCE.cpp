#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
#include<cstring>
#include<string>
#define ll long long
#define REP(i,l,r) for((i)=(l);(i)<=(r);++(i))
#define REP2(i,l,r) for((i)=(l);(i)!=(r);++(i))

#define MOD 1000000000

std::vector<std::vector<ll>> multiply(std::vector<std::vector<ll>> A, std::vector<std::vector<ll>> B, int k)
{
	// Step -1 Store the container
	std::vector<std::vector<ll>> C(k + 1, std::vector<ll>(k + 1, 0));

	//Step-2 finally multiply the terms
	for(int x = 1; x <= k; x++)
	{
		for(int y = 1; y <= k; y++)
		{
			for(int z = 1; z <= k; z++)
			{
				C[x][y] = (C[x][y] + (A[x][z] * B[z][y])% MOD) % MOD;
				// if(x == 1)
				// {
				// 	std::cout << B[z][y] << " ";
				// }
			}
		}
	}
	return C;
}

std::vector<std::vector<ll>> pow(std::vector<std::vector<ll>> T, ll n, int k)
{	
	// Step - 1 return simple base cases
	if(n == 1) return T;

	if(n & 1)
	{	
		std::vector<std::vector<ll>> res = pow(T, n-1, k);
		return multiply(T, res, k);
	}
	else
	{	
		std::vector<std::vector<ll>> res = pow(T, n/2, k);
		return multiply(res, res, k);
	}
}

ll  compute(std::vector<ll> b, std::vector<ll> c, ll n,  int k)
{
	// directly return the base cases
	if(n == 0) return 0;

	if(n <= k)  return b[n];

	//Step - 1 Inititialize the transformation matrix
	std::vector<std::vector<ll>> T(k + 1, std::vector<ll>(k + 1));

	for(int i = 1; i <= k; i++)
	{
		for(int j = 1; j <= k; j++)
		{
			if(i < k)
			{	
				if( i + 1== j)
				{
					T[i][j] = 1;
				}
				else
				{
					T[i][j] = 0;
				}
			}
			else
			{
				T[i][j] = c[k - j + 1];
			}
			// std::cout << T[i][j] << " ";
		}
		// std::cout << std::endl;
	}

	//Step 2 Calculate T^(n - 1)
	// std::vector<std::vector<ll>> C;
	T = pow(T, n -1, k);

	// Step -3 Finally calculate the value of fn
	ll res = 0;
	for(int i = 1; i <= k; i++)
	{
		res = (res + (T[1][i] * b[i]) % MOD) % MOD;

		// std::cout << T[1][i];
	}
	return res;
}

int main()
{
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	#endif

    //input the no. of test cases
    int t;
    std::cin >> t;

    //variables for different test cases
    int k;
    std::vector<ll> b;
    std::vector <ll> c;
    ll n;


    while(t--)
    {
		// Step -1 Input for the different test cases  
		std::cin >> k;
		b.resize(k + 1); // for indexing from one
		c.resize(k + 1);

		for(int i = 1; i <=k; i++)
		{
			ll val;
			std::cin >> val;
			b[i] = val;
		}

		for(int i = 1; i <=k; i++)
		{
			ll val;
			std::cin >> val;
			c[i] = val;
		}

		std::cin >> n;

		//step 2

		std::cout << compute(b, c, n, k) << std::endl;

		// will have to clear the vector at the end.
		b.clear();
		c.clear();

    }
    
    return 0;
}