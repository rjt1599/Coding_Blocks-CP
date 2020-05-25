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

    ll t;
    std::cin >> t;
    while(t--)
    {
    	ll num;
    	std::cin >> num;
    	ll digit;

    	ll pos = 1;
    	ll index = 0;

    	while(num > 0)
    	{
    		digit = num %10;
    		num = num / 10;

    		if(digit == 7)
    		{
    			index += pos;
    		}

    		pos = pos << 1;
    	}
    	index += pos - 1;
    	std::cout << index <<std::endl;
    }
    
    return 0;
}