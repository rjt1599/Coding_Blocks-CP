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

std::vector<ll> b;

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

ll compute(ll n, int k)
{
	if(n == 0) return 1;
	if(n <= k)
	{
		return b[n];
	}

	std::vector<std::vector<ll>> T(k + 1, std::vector<ll>(k + 1));

	for(int i =1; i <=k; i++)
	{
		for(int j = 1; j <=k; j++)
		{
			if(i < k)
			{
				if(i + 1 == j)
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
				T[i][j] = 1;
			}
		}
	}

	T = pow(T, n - 1, k);


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
    int t;
    std::cin >> t;
    int k = 3;
    b.resize(k +1);
	b[1] = 1;
	b[2] = 2;
	b[3] = 4;
    
    while(t--)
    {	
	    ll n;
	    std::cin >> n; 

	    std::cout << compute (n ,k) <<std::endl;

	    // b.clear();
    }
    return 0;
}