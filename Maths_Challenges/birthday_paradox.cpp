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

    float p;
    std::cin >> p;

    float x = 1.0;
    int n = 0;

    int num = 365;
    int denom = 365;

    while(x > 1 - p)
    {
    	x = x * (num / (denom * 1.0));
    	n++;
    	num--;
    }
    std::cout << n << std::endl;
    
    return 0;
}	