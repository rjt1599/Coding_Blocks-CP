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
#define RANGE 100000

std::vector<ll> primes;
int arr[RANGE];

void sieve()
{
	for(ll i = 0; i < RANGE; i++)
	{
		arr[i] = 1;
	}

	arr[0] = arr[1] = 0;

	for(ll i = 2; i < RANGE; i++)
	{
		if(arr[i] == 1)
		{	
			primes.push_back(i);
			for(ll j = i * i; j < RANGE; j += i)
			{
				arr[j] = 0;
			}
		}
	}

}

int main()
{
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	#endif

	/*
	//Use fast i/o at starting of main() i.e.

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	*/
	sieve();
	// std::cout << primes[3] << std::endl;
    // std::cout << arr[3] << arr[5] << std::endl;
	int t;
	std::cin >> t;
	
	while(t--)
	{
		ll m, n;
		std::cin >> m >> n;

		std::vector<bool> segment(n- m + 1, true);

		// mark the boundary cases;
		if(m == 1) segment[0] = false;

		for(auto x : primes)
		{
			if(x * x > n)
			{
				break;
			}

			ll start = ((m + x - 1) / x) * x;
			if(x >= m && x <=n)
			{
				start += x;
			}
			for(; start <= n; start += x)
			{
				segment[start - m] = false;
			}

		}

		// ll count = 0;
		for(ll i = 0; i < (n - m + 1); i++)
		{
			if(segment[i])
			{
				std::cout << m + i<< std::endl;
			}

		}
		std::cout << std::endl;
	}

    
    return 0;
}