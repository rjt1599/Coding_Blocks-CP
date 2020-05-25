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

ll x, y, GCD;

void extended_euclid(int a, int b)
{
	// base case
	if(b == 0)
	{
		x = 1;
		y = 0;
		GCD = a;
		// std::cout << x << " " << y << std::endl;
		return;
	}

	//recursive case
	extended_euclid(b, a % b);
	int Cx, Cy;
	Cx = y;
	Cy = x -(a / b) * y;

	x = Cx;
	y = Cy;
	// std::cout << x << " " << y << std::endl;
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

    ll a, b, m;
    std::cin >> a >> m;
    extended_euclid(a, m);
    if(GCD == 1)
    {
    	std::cout << (x + m) % m << std::endl;
    }
    else
    {
    	std::cout << "NONE" << std::endl;
    }
    // std::cout << GCD << std::endl;
    // std::cout << b << std::endl;
    return 0;
}