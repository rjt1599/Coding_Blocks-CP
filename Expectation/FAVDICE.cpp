#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
#include<cstring>
#include<string>
#include<cstdio>
#include<iomanip>
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

    int n, t;
    std::cin >> t;

    while(t--)
    {
    	std::cin >> n;
    	double ans = 0.0;

    	for(int i = 1; i <=n; i++)
    	{
    		ans += (n * 1.0) / (n - i + 1);
    	}
    	// std::cout << ans << std::endl;
    	// printf("%.2lf\n", ans);
    	std::cout << std::fixed << std::setprecision(2) << ans << std::endl;
    }
    
    return 0;
}