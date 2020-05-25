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
    std::vector<int> v(n , 0);
    // v.reserve(n);
    int res = 0;

    for(int i = 0; i < n; i++)
    {
    	int val;
    	std::cin >> val;
    	res ^= val;
    	v[i] = val;
    }

    int pos = res & (-res);
    int x = 0, y = 0;

    // std::cout << pos << std::endl;

    for(int i = 0;i < n; i++)
    {
    	if(v[i] & pos)
    	{
    		x ^= v[i];
    	}
    }

    y = res ^ x;
    std::cout << std::min(x, y)<< " " << std::max(x, y) << std::endl;
    
    return 0;
}