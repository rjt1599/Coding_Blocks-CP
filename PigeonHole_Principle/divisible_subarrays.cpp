/*

https://hack.codingblocks.com/app/practice/3/1065/problem

link of the problem......

*/



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

    int t;
    std::cin >> t;

    std::vector<ll> pre;

    while(t--)
    {
    	ll n;
    	std::cin >> n;
    	pre.resize(n, 0);

    	pre[0] = 1; // initially 1 hoga;

    	ll val;
    	ll sum = 0;
    	for(ll i = 0; i < n; i++)
    	{
    		std::cin >> val;
    		sum = (sum + val % n)%n;
    		sum = (sum + n) % n;

    		pre[sum]++;
    	}

    	ll ans = 0;
    	for(ll i= 0; i < n; i++)
    	{	
    		ll m = pre[i];
    		ans += 	m * (m - 1) / 2;
    	}

    	std::cout << ans << std::endl;

    	pre.clear();
    }
    
    return 0;
}