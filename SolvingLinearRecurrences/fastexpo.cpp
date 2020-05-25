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


int expo(int a, int n)
{
	if(n == 0)
	{
		return 1;
	}

	int subprob = expo(a, n/2) * expo(a, n/2);

	if(n & 1)
	{
		subprob = a * subprob;
		return subprob;
	}
	else
	{
		return subprob;
	}
}

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

    int res;

    res = expo(a, n);

    std::cout << res;
    
    return 0;
}