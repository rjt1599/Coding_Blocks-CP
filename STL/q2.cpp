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

    std::vector<int> v1, v2;
    v1.reserve(n);
    v2.reserve(n);

    for(int i = 0; i < n; i++)
    {
    	int val;
    	std::cin >> val;
    	v1.push_back(val);
    }
    
    for(int i = 0; i < n; i++)
    {
    	int val;
    	std::cin >> val;
    	v2.push_back(val);
    }

    int i1 = -1, i2 = -1;
    for(int i = 0; i < n; i++)
    {
    	if(v1[i1 + 1] < v2[i2 + 1]){
    		i1++;
    		if(i == n-1)
    		{
    			std::cout << v1[i1];
    		}
    	}
    	else
    	{
    		i2++;
    		if(i == n- 1)
    		{
    			std::cout << v2[i2];
    		}
    	}
    }

    return 0;
}