#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
#include<cstring>
#include<string>
#define ll unsigned long long
#define REP(i,l,r) for((i)=(l);(i)<=(r);++(i))
#define REP2(i,l,r) for((i)=(l);(i)!=(r);++(i))

void primeFactors(ll n, std::vector<ll> &prime, std::vector<ll> &pre)
{
	if(n % 2 == 0)
	{	
		prime.push_back(2);
		ll cnt = 0;
		while(n % 2 == 0)
		{
			cnt++;
			n = n / 2;
		}	
		pre.push_back(cnt);
	}

	for(ll i = 3; i * i <= n; i+=2)
	{
		if(n % i == 0)
		{
			prime.push_back(i);
			ll cnt = 0;
			while(n % i == 0)
			{
				cnt++;
				n = n /i;
			}
			pre.push_back(cnt);
		}
	}

	if(n > 2)
	{
		prime.push_back(n);
		pre.push_back(1);
	}

}

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

    std::vector<ll> prime;
    std::vector<ll> pre;
    std::vector<ll>count;

    while(t--)
    {
    	ll n, k;
    	std::cin >> n >> k;

    	primeFactors(k, prime, pre);

    	ll min = LLONG_MAX;

    	// std::cout << n << " " << k << std::endl;

    	for(ll i = 0; i < prime.size(); i++)
    	{
    		ll val = prime[i];
    		ll cnt = 0;
    		while(val <= n)
    		{
    			// std::cout << n << " "<< val << std::endl;
    			cnt += n / val;
    			val *= prime[i];
    			
    		}
    		count.push_back(cnt / pre[i]);
    		// std::cout << cnt << std::endl;
    		if(min > count[i])
    		{
    			min = count[i];
    		}
    	}

    	// for(ll i = 0; i < prime.size(); i++)
    	// {
    	// 	std::cout << prime[i] << " " << pre[i] << " " << count[i] << std::endl;
    	// }

    	// if(min == LLONG_MAX)
    	// 	min = 0;

    	std::cout << min << std::endl;
    	
    	prime.clear();
    	pre.clear();
    	count.clear();
    }

    return 0;
}