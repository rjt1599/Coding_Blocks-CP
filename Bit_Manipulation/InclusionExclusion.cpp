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

	int prime[] = {2, 3, 5, 7, 11, 13, 17, 19};

	int t;
    std::cin >> t;
	while(t--)
	{
		ll n;
		std::cin >> n;

		ll limit = 1 << 8;
		ll ans = 0;

		for(ll i = 1; i < limit; i++)
		{
			// ll mask = 1;
			// ll ans = 0;
			ll temp = i;
			ll countSetBits = __builtin_popcount(i);
			ll denom = 1;
			ll j = 0;
			while(temp > 0)
			{
				
				if(temp & 1 > 0)
				{
					denom = denom * prime[j];
				}

				// mask = mask << 1;
				temp = temp >> 1;
				j++;
			}
			if(countSetBits & 1)
			{
				ans += n / denom;
			}
			else
			{
				ans -= n /denom;
			}
		}
        std::cout << ans << std::endl;
	}

    
    return 0;
}