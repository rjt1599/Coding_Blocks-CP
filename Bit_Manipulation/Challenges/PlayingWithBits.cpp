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
	

int countSetBits(int n)
{	
	int ans = 0;
	while(n)
	{
		n = n & (n - 1);
		ans++;
	}
	return ans;

}

int main()
{
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	#endif

    int t;
    std::cin >> t;

    while(t--)
    {
    	int a, b;
    	std::cin >> a >> b;
    	int sum  = 0;
    	while( a <= b)
    	{
    		// std::cout << countSetBits(a);
    		sum += countSetBits(a);
    		a++;
    	}
    	std::cout << sum << std::endl;
    }
    
    return 0;
}