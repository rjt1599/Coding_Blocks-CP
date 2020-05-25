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

ll getindex(ll p)
{
	ll ans = 0;
	while(p)
	{
		p = p >> 1;
		ans++;
	}
	return ans - 1;
}

int main()
{
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	#endif

    ll n, a, b;
    std::cin >> n >> a >>b;

    std::vector<ll> v(n);

    for(ll i = 0; i < n; i++)
    {	
    	ll val;
    	std::cin >> val;
    	v[i] = val;
    }

    ll l1 = 1 << (n/2), l2 = 1 << (n - n/2);

    std::vector<ll> s1(l1);
    std::vector<ll> s2 (l2);

    for(ll i = 0; i < l1; i++)
    {
    	ll sum = 0;
    	ll temp = i;
    	ll p;
    	while(temp)
    	{
    		p = temp & (-temp);
    		temp = temp - p;
    		sum += v[getindex(p)];
    	}
    	s1[i] = sum; 
    }

    for(ll i = 0; i < l2; i++)
    {
    	ll sum = 0;
    	ll temp = i;
    	ll p;
    	while(temp)
    	{
    		p = temp & (-temp);
    		temp = temp - p;
    		sum += v[getindex(p) + n/2];
    	}
    	s2[i] = sum; 
    }

    ll count = 0;

    std::sort(s2.begin(), s2.end());

    for(ll i = 0; i < l1; i++)
    {
    	auto low = lower_bound(s2.begin(), s2.end(), a - s1[i]);
    	auto high = upper_bound(s2.begin(), s2.end(), b - s1[i]);
    	count += static_cast<ll>(high - low);
    }

	// ll limit = (1 << n) ;
	// ll count = 0;

	// for(ll i = 0; i < limit; i++)
	// {
	// 	ll sum = 0;
	// 	ll temp = i;
	// 	ll p;
	// 	while(temp)
	// 	{
	// 		p = temp & (-temp);
	// 		temp = temp - p;
	// 		sum += v[getindex(p)];
	// 	}
	// 	if(sum >= a && sum <=b) count++;
	// }    
    
	std::cout << count;

    return 0;
}