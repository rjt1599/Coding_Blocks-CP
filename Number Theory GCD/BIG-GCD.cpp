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

ll ans;

void gcd(ll a,ll b)
{
	if(b == 0)
	{
		ans = a;
		return;
	}
	else
	{
		gcd(b, a % b);	
	}	
}

ll modulo(std::string s, ll m)
{
	ll b = 1;
	ll n = s.size();
	ll sum = 0;

	for(ll i = 1; i <= n; i++)
	{
		ll val = static_cast<ll>(s[n - i] - '0');
		val = val % m;

		sum = (sum + (b * val)%m) % m;

		b = (b * 10) % m;
	}
	return sum;
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
	std::string s;
	std::cin >> n;
	std::cin >> s;

	// std::cout << n << std::endl;
	// std::cout << s << std::endl;

	ll y = modulo(s, n);
	// std::cout << y << std::endl;

	// ans = gcd(n, y);
	gcd(n, y);

	std::cout << ans << std::endl;

    
    return 0;
}