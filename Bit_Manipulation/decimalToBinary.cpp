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

void decimal_to_binary(int n)
{
	int p = 1;
	int ans = 0;
	int last = 0;
	int mask = 1;
	while(n > 0)
	{	
		last = mask & n;
		ans += p * last;
		n = n >> 1;
		p *= 10;
	}

	std::cout << ans;
}

int main()
{
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	#endif

    void(35);
    
    return 0;
}