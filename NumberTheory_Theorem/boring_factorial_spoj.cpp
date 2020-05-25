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

ll modular_exponentiation(ll a, ll n, ll m)
{
	ll res = 1;
	a = a % m;
	while( n > 0)
	{
		if(n & 1)
		{
			res = (res * a) % m;
		}
		n = n >> 1;
		a = (a * a) % m;
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

	/*
	//Use fast i/o at starting of main() i.e.

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	*/
	ll n, p;
    int t;
    std::cin >> t;
    while(t--)
    {
    	std::cin >> n >> p;
    	if(n >= p)
    	{
    		std::cout << 0 << std::endl;
    	}
    	else
    	{	
    		ll res = 1;
    		for(ll i = n + 1; i <= p -1; i++)
    		{
    			ll mod = modular_exponentiation(i, p -2, p);
    			res = (res * mod) % p;
    		}
    		
    		res = (-res + p) % p;

    		std::cout << res << std::endl;
    	}
    }
    
    return 0;
}