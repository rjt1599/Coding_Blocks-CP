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

ll fastModExpo(int a, int n, int m)
{
	ll res = 1;

	while(n > 0)
	{
		if(n & 1)
		{
			res = ((res % m) * (a % m)) % m;
		}
		a = ((a % m) * (a % m )) % m;
		n = n >> 1;
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

    int a, n, m;
    std::cin >> a >> n >> m;

    std::cout << fastModExpo(a, n, m);
    
    return 0;
}