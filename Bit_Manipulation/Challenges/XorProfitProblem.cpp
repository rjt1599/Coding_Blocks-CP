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

    ll x, y;
    std::cin >> x >> y;
    //simple solutiosn
    /*
    int max = INT_MIN;
    for(int a = x; a <= y; a++)
    {
    	for(int b = a; b <= y; b++)
    	{
    		int temp = a ^ b;
    		if(max < temp)
    		{
    			max = temp;
    		}
    	}
    }
    std::cout << max;
    */

    //Optimised Solution
    ll max = 0;

    ll res = x ^ y;
    ll p = 0;
    while(res)
    {
    	p = res & (-res);
    	res = res - p;
    }
    if(p == 0)
    {
        std::cout << 0;
        return 0;
    }
    max = (p - 1) + p;
    std::cout << max;
    return 0;
}