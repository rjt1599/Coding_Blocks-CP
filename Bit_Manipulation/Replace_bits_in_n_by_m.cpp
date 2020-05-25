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
	
int clearRangeBits(int n, int i, int j)
{
	// int mask = ((-1) << j + 1) | (~((-1) << i));
	int mask = ((-1) << j + 1) | ((1 << i) - 1);
	return n & mask;
}

int replaceBits(int n, int m, int i , int j)
{
	int cleared_no = clearRangeBits(n, i, j);
	return cleared_no | (m << i);
}

int main()
{
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	#endif

    int N, M;
    int i , j;

    N = 9;
    M = 3;
    i = 1;
    j = 1;

    std::cout <<replaceBits(N, M, i, j);



    
    return 0;
}