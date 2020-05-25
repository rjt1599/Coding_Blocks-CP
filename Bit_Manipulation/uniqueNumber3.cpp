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
    std::vector<int> v;
    v.reserve(n);

    // int sum = 0;
    int sum[64] {0};

    for(int i = 0;i < n; i++)
    {
    	int val;
    	std::cin >> val;
    	v.push_back(val);
    		
    	int p = 1;
    	for(int i = 0; i < 64; i++)
    	{
    		sum[i] += val & (1 << i);
    		sum[i] = sum[i] % 3; 
    	}
    }

    

    // int pos = 0;
    // while(sum > 0)
    // {
    // 	arr[pos] = sum & 1;
    // 	sum = sum >> 1;
    // 	pos++;
    // }

    int ans = 0;
    for(int i = 0; i < 64; i++)
    {
    	ans = ans | (sum[i] << i);
    }

    std::cout << ans;
    
    return 0;
}