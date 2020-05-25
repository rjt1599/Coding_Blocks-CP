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
#define uint unsigned int

#define LIMIT 100005;

// uint least_primes[LIMIT];

// void lpf()
// {

// }

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
	// lpf();

	int t;
	std::cin >> t;
	while(t--)
	{	
		ll N;
		std::cin >> N;
		ll n = N;
		// int count = 0;
		std::vector<std::pair<ll, ll>> factors;
		for(ll i = 2; i * i <= n; i++)
		{
			if(n % i == 0)
			{	
				ll count = 0;
				// factors.push_back(i);
				while(n % i == 0)
				{
					count++;
					n = n / i;
				}
				factors.push_back(std::make_pair(i, count));
			}
		}
		if(n > 1)
		{
			factors.push_back(std::make_pair(n, 1));
		}

		if(factors.size() >= 3)
		{
			std::cout << "YES" << std::endl;
			std::cout << factors[0].first << " " << factors[1].first << " " << N / factors[0].first / factors[1].first<< std::endl;
		}
		else if(factors.size() == 2)
		{
			ll a, b, c;
			a = factors[0].first;
			b = factors[1].first;
			c = N / (a * b);
			if(c == 1 || c == a || c == b) std::cout << "NO" << std::endl;
			else
			{
				std::cout << "YES" << std::endl;
				std::cout << a << " " << b << " " << c << std::endl;
			}
		}
		else
		{
			if(factors[0].second < 6) std::cout << "NO" << std::endl;
			else
			{	
				ll a, b, c;
				a = factors[0].first;
				b = a * a;
				c = N / (a * b);
				std::cout << "YES"<< std::endl;
				std::cout << a << " " << b << " " << c << std::endl;
			}
		}
	}

    
    return 0;
}