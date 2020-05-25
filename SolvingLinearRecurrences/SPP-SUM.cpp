/*
*********************************
Note modulus difference aata hai toh kabhi add karke positive karna mat bhoolna !!!!!!!!!!!!!!!!!!

***********************************
*/
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

// #define p 1000000000
ll p;
std::vector<ll> b;
std::vector <ll> c;

std::vector<std::vector<ll>> multiply(std::vector<std::vector<ll>> A, std::vector<std::vector<ll>> B, ll k)
{
	// Step -1 Store the container
	std::vector<std::vector<ll>> C(k + 1, std::vector<ll>(k + 1, 0));

	//Step-2 finally multiply the terms
	for(ll x = 1; x <= k; x++)
	{
		for(ll y = 1; y <= k; y++)
		{
			for(ll z = 1; z <= k; z++)
			{
				C[x][y] = (C[x][y] + (A[x][z] * B[z][y])%p) %p;
				// if(x == 1)
				// {
				// 	std::cout << B[z][y] << " ";
				// }
			}
		}
	}
	return C;
}

std::vector<std::vector<ll>> pow(std::vector<std::vector<ll>> T, ll n, ll k)
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

ll  compute(ll n,  ll k)
{
	// directly return the base cases
	if(n == 0) return 0;

	// if(n <= k)  return b[n];
	ll Sk = 0;
	for(ll i = 1; i <=k ; i++)
	{
		Sk = (Sk + (b[i]) % p) % p;
		if(n == i)
		{
			return Sk;
		}
	}

	//Step - 1 Inititialize the transformation matrix
	std::vector<std::vector<ll>> T(k + 2, std::vector<ll>(k + 2));

	for(ll i = 1; i <= k + 1; i++)
	{
		for( ll j = 1; j <= k + 1; j++)
		{	
			if(i == 1)
			{
				if(j == 1) T[i][j] = 1;
				else
				{
					T[i][j] = c[k - j + 2];
				}
			}
			else if(1 < i && i < k + 1)
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
				if(j == 1) T[i][j] = 0;
				else
				{	
					T[i][j] = c[k - j + 2];
				}
			}
			// std::cout << T[i][j] << " ";
		}
		// std::cout << std::endl;
	}

	//Step 2 Calculate T^(n - 1)
	// std::vector<std::vector<ll>> C;
	T = pow(T, n - k, k + 1);

	// Step -3 Finally calculate the value of fn

	std::vector<ll> Fk(k + 2);
	for(ll i = 1; i <= k + 1; i++)
	{
		if(i == 1) Fk[i] = Sk;
		else
		{
			Fk[i] = b[i - 1];
		}
	}

	ll res = 0;
	for(ll i = 1; i <= k + 1; i++)
	{
		res = (res + (T[1][i] * Fk[i]) % p) % p;

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
    ll t;
    std::cin >> t;

    //variables for different test cases
    ll k;
    
    ll m, n;


    while(t--)
    {
		// Step -1 Input for the different test cases  
		std::cin >> k;
		b.resize(k + 1); // for indexing from one
		c.resize(k + 1);

		for(ll i = 1; i <=k; i++)
		{
			ll val;
			std::cin >> val;
			b[i] = val;
		}

		for(ll i = 1; i <=k; i++)
		{
			ll val;
			std::cin >> val;
			c[i] = val;
		}

		std::cin >> m >> n >> p;

		//step 2

        ll X = compute(n, k) % p;
        ll Y = compute(m - 1, k) % p;

		ll ans = X - Y;

		if(ans < 0)
		{
			ans = (ans + p) %p;
		}
		std::cout << ans << std::endl;
		// will have to clear the vector at the end.
		b.clear();
		c.clear();

    }
    
    return 0;
}