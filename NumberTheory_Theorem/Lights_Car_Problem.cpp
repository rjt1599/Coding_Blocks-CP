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

const int p = 1000000007;

ll stringToint(std::string a, ll m)
{	
	ll A = 0;
	for(int i = 0; i < a.size(); i++)
    {
    	int val = a[i] - '0';
    	A = ((A * 10) + val) % (m);
    }
    return A;
}

ll fastModuloExpo(ll x, ll y, ll m)
{
	ll ans = 1;
	x = (x % m);
	while(y > 0)
	{
		if( y & 1)
		{
			ans = (ans * x) % m;
		}
		x = (x * x) % m;
		y = y >> 1;
	}	

	return ans;
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

    std::string a, b;
    std::cin >> a >> b;

    ll A, B;
    A = 0;
    B = 0;

    A = stringToint(a, p);
    B = stringToint(b, p - 1);

    ll ans = fastModuloExpo(A, B, p);
    std::cout << ans;


    return 0;
}