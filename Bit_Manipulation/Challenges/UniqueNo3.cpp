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

    int n;
    std::cin >> n;

    int sum [64] = {0};

    while(n--)
    {
    	int val;
    	std::cin >> val;
    	int i = 0;
    	while(val)
    	{
    		sum[i] = (sum [i] + (val & 1)) % 3;

    		val = val >> 1;
    		i++;
    	}
    }
    
    int ans = 0;
    int p = 1;
    for(int i = 0; i < 64;i++)
    {
    	ans += sum[i] * p;
    	p = p << 1;
    }

    std::cout << ans;

    return 0;
}