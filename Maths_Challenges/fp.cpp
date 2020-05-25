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
	// #ifndef ONLINE_JUDGE
    // // for getting input from input.txt
    // freopen("input.txt", "r", stdin);
    // // for writing output to output.txt
    // freopen("output.txt", "w", stdout);
	// #endif

    int t;
    ll n, k;

    std::cin >> t;

    // ll * a;
    ll sum = 0;

    while(t--)
    {
    	std::cin >> n >> k;
    	std::vector<int> a(n, 0);
    	sum = 0;

    	// memset(a, 0, (n) * sizeof(int));

    	for(ll i = 1; i * k <= n; i++)
    	{
    		a[i * k - 1] = a[i - 1] + 1;
    		sum += a[i * k - 1];
    	}

    	std::cout << sum << std::endl;

    	a.clear();
    }
    
    return 0;
}