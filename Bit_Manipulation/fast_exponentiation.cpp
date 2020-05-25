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

    int a, n;
    std::cin >> a >> n;

    int ans = 1;
    int mul = a;

   	int power = n;

   	while(power > 0)
   	{
   		if(power & 1)
   		ans *= mul;

   		power = power >>1;
   		mul *= mul;
   	}

   	std::cout << ans;
    
    return 0;
}