#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
#include<cstring>
#include<string>

#define ll long long int
#define REP(i,l,r) for((i)=(l);(i)<=(r);++(i))
#define REP2(i,l,r) for((i)=(l);(i)!=(r);++(i))

ll fast_modulo(ll x, ll n, ll m)
{
	ll ans = 1;
	x = x % m;

	while( n > 0)
	{
		if(n & 1)
		{
			ans = (ans * x) % m;
		}
		x = (x * x) % m;
		n = n >> 1;
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
    ll ans;
    ll x, n, m;
    std::cin >> x >> n >> m;

    ans = fast_modulo(x, n,m);
    std::cout << ans << std::endl;

    return 0;
}