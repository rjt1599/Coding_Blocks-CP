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

	ll n, p, w, d;
	std::cin >> n >> p >> w >> d;

	if( n * w < p)
	{
		std::cout << -1;
		return 0;
	}
	ll x, y, z;
	for(ll i = 0; i < w; i++)
	{
		y = i;
		
		if((p - d * y) % w != 0) continue;
		
		x = (p - d *y) / w;
		if(x < 0) continue;

		z = n - x - y;
		if(z < 0) continue;

		std::cout << x << " " << y << " " << z;
		return 0;
	}

	std::cout << -1;
    
    return 0;
}