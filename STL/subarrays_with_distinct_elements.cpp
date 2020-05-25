#include<iostream>
#include<vector>
#include<unordered_set>
#define ll long long


int main()
{
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	#endif
    std::vector<ll>v;
    ll n;
    std::cin >> n;
    for(ll i = 0 ;i < n; i++)
    {	
    	ll val;
    	std::cin >> val;
    	v.push_back(val);
    }

    ll sum = 0;

    for(ll i = 0;  i <n; i++)
    {
    	std::unordered_set<int> s;
    	ll j = i;
    	while(j < n)
    	{
    		auto it = s.insert(v[j]);
    		if(it.second == false)
    		{
    			sum += (j - i)*(j - i + 1)/2;
    			break;
    		}
    		j++;
    	}
    	if(j == n)
    	{
    		sum += (j - i)*(j - i + 1)/2;	
    	}
    }
    std::cout << sum;
    return 0;
}