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

void cal_mobius(ll n)
{
	std::vector<ll>a(n +1, 1);
	std::vector<ll>prime_count(n + 1, 0);

	for(ll i = 2; i <=n; i++)
	{
		if(prime_count[i]) continue;
		else
		{
			for(ll j = i; j <= n; j += i)
			{
				prime_count[j]++;
				a[j] = a[j] * i;
			}
		}
	}

	for(ll i = 1; i <= n ; i++)
	{
		if(a[i] == i)
		{
			// now it is a square free integer
			if(prime_count[i] % 2 == 0)
			{
				std::cout << i << " " << 1 << std::endl;
			}
			else
			{
				std::cout << i << " " << -1 << std::endl;
			}
		}
		else
		{	
			// a squared prime integer.
			std::cout <<i << " " << 0  << std::endl;
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
    ll n;
    std::cin >> n;
    cal_mobius(n);
    
    return 0;
}