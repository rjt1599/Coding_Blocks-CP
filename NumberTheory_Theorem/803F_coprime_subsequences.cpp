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
#define limit 100001

const long long p = 1000000000 + 7;


int freq[limit] {0};
int prime_count[limit] {0};
ll a [limit] {1};
int mob[limit];

ll modular_exponentiation(ll a, ll n, ll p)
{
	ll res = 1;
	while(n > 0)
	{
		if(n & 1)
		{
			res = (res * a) % p;
		}
		a = (a * a) % p;
		n = n >> 1;
	}
	return res;
}

void cal_mobius()
{	
	int n = limit;
	mob[1] = -1;

    for(int i = 0; i < limit; i++)
    {
        a[i] = 1;
    }


	for(int i = 2; i < n; i++ )
	{
		if(prime_count[i]) continue;
		for(int j = i; j < n; j += i)
		{
			prime_count[j]++;
			a[j] *= i;
		}
	}

	for(int i = 2; i < n; i++)
	{
		if(a[i] == i)
		{
			// square free number
			if(prime_count[i] % 2 == 0) mob[i] = 1;
			else mob[i] = -1;
		}
		else
		{
			mob[i] = 0;
		}
	}
}

void solve(int n)
{
	cal_mobius();

	ll ans = modular_exponentiation(2, n, p) - 1;
	// std::cout << ans << std::endl;
	for(int i = 2; i < limit; i++)
	{
		if(mob[i] == 0) continue;

		// std::cout << i << freq[i] << std::endl;

		ll count = 0;
		for(int j = i; j < limit; j += i)
		{
			count += freq[j];
		}
		
		ll mod = modular_exponentiation(2, count, p) - 1;
		
		ans = (ans + (mod * mob[i]) ) % p;
		
		ans = (ans + p) % p;
	}
	
    std::cout << ans;

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
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
    	int val;
    	std::cin >> val;
    	freq[val]++;
    }
    solve(n);
    
    return 0;
}