#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
#include<cstring>
#include<string>
#include<queue>
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

    std::priority_queue<ll> h;
    int n, k;
    std::cin >> n >> k;
    int count = 0;
    for(int i = 1;  i <= n ; i++)
    {
    	int type;
    	std::cin >>type;
    	if(type == 1)
    	{
    		int x, y;
    		std::cin >> x >> y;
    		ll dist = x * x + y * y;
    		if(h.size() < k)
    		{
    			h.push(dist);
    		}
    		else
    		{
    			if(h.top() > dist)
    			{	
    				h.pop();
    				h.push(dist);
    			}
    		}
    	}
    	else if(type == 2)
    	{	
    		if(count != 0) std::cout << std::endl;
    		count++;
    		std::cout << h.top();
    	}
    }
    
    return 0;
}