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

    ll n, k;
    std::cin >> n >> k;
    std::vector<ll> v(n + 1);
    std::vector<ll> h(n + 1);
   

    for(ll i = 1; i <= n; i++)
    {
    	ll val;
    	std::cin >> val;
    	v[i] = val;
    	h[v[i]] = i;
    }
    for(int i = 1; i <= n; i++)
    {
    	if(v[i] != n - i + 1)
    	{	v[h[n - i + 1]] = v[i];

    		h[v[i]] = h[n - i + 1];
    		h[n - i + 1] = i;
   	
   			v[i] = n - i + 1;
   			k--;
   			if(k == 0) break;
    	}
    }

    for(int i = 1; i <= n; i++)
    {
    	std::cout << v[i] << " ";
    }
    
    return 0;
}