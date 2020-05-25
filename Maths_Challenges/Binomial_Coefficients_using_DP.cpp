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
#define ull unsigned long long


ll c_top_down(ll n, ll k)
{	
	k = std::min(k, n - k);
	std::vector<std::vector<ll>> c(n + 1, std::vector<ll>(k + 1, -1));

	for(ll i = 1; i <=n; i++)
	{
		for(ll j = 0; j <= std::min(i, k); j++)
		{
			if(j == 0 || j == i) c[i][j] = 1;
			else
			{
				c[i][j] = c[i -1][j] + c[i -1][j - 1];
			}
		}
	}
	return c[n][k];
}

ll c_memorization(ll n, ll k, auto & a)
{
	if(k == 0 || k == n)
	{
		a[n][k] = 1;
	}
	else if(a[n][k] != -1) return a[n][k];
	else
	{
		a[n][k] = c_memorization(n - 1, k, a) + c_memorization(n - 1, k -1, a);
	}
	return a[n][k];
}



int main()
{
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	#endif

    ll n, k;
    std::cin >> n >> k;

    std::cout << c_top_down(n, k) << std::endl;

    std::vector<std::vector<ll>> a(n + 1, std::vector<ll>(k + 1, -1));

    std::cout << c_memorization(n, k, a) << std::endl;

    
    return 0;
}