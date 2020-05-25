/*
https://codeforces.com/contest/846/problem/F
*/

// Linear DP

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
#include<cstring>
#include<string>
#include<iomanip>
#define ll long long
#define REP(i,l,r) for((i)=(l);(i)<=(r);++(i))
#define REP2(i,l,r) for((i)=(l);(i)!=(r);++(i))


ll a[1000006] = {0};
ll lastOccurrence[1000006] = {0};
ll ans[1000006] = {0};

ll sum = 0;

int main()
{
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	#endif

    ll n;
    std::cin >> n;

    // base cases
    ans[0] = 0;


    for(ll i = 1; i <=n; i++)
    {
   		std::cin >> a[i];
   		ans[i] = ans[i - 1] + (i - lastOccurrence[a[i]]);

   		lastOccurrence[a[i]] = i;

   		sum += ans[i];
    }

    // for(int i = 1; i <=2; i++)
    // {
    // 	std::cout << ans[i] << " "<< std::endl;
    // }

    double final;

    final = (2 * (sum - n) + n) / (n * n * 1.0);

    std::cout << std::setprecision(4) << std::fixed << final;
    
    return 0;
}