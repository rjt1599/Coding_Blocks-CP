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

//O(logn)
int countBitsm1(int n)
{	
	int mask = 1;
	int ans = 0;
	while(n > 0)
	{
		ans += mask & n;
		n = n >> 1;
	}
	return ans;
}

//O(no.of.set.bits)
int countBitsFastm2(int n)
{
	int ans = 0;
	while(n > 0)
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

    int n;
    n = 15;

    std::cout << countBitsm1(n) << std::endl;
    std::cout << countBitsFastm2(n) << std::endl;
    //method3 using buitlin function

    std::cout << __builtin_popcount(n) << std::endl;
    return 0;
}