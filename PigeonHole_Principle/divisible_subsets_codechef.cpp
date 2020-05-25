/*
https://www.codechef.com/problems/DIVSUBS
*/
// Subarrays check karke hi kaam ho jaate according to pigeon hole principle


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

    ll n;
    // std::vector<ll>()

    while(t--)
    {
    	std::cin >> n;
    	std::vector<ll> v (n, 0);

    	ll sum = 0;

    	bool done = false;
    	for(int i = 1; i <= n; i++)
    	{
    		ll val;
    		std::cin >> val;
    		if(done) continue;

    		sum = (sum + val % n) % n;
    		if(sum == 0 || v[sum] != 0)
    		{
    			std::cout << i - v[sum] << std::endl;
    			// std::cout << i << std::endl;
    			for(ll j = v[sum] + 1; j <= i; j++)
    			{
    				std::cout << j << " ";
    			}
    			std::cout << std::endl;
    			done = true;
    			continue;
    		}
    		// if(v[sum] != 0)
    		// {
    		// 	std::cout << v[sum] << std::endl;
    		// 	std::cout << i << std::endl;
    		// 	done = true;
    		// 	continue;
    		// }
    		else
    		{
    			v[sum] = i;
    		}
    	}
    }
    
    return 0;
}