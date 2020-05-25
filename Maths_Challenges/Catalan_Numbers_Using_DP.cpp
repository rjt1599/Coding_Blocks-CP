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
#define ull unsigned long long

ull naive_approach(int n)
{
	if(n <= 1) return 1;

	ull res = 0;
	for(int i = 0; i < n; i++)
	{
		res += naive_approach(i) * naive_approach(n - i - 1);
	}
	return res;
}

ull * a;

ull dp_memorization(int n)
{	
	ull res = 0;
	if(a[n] != 0) return a[n];
	else
	{	

		for(int i = 0; i < n; i++)
		{
			res += dp_memorization(i) * dp_memorization(n - i - 1);
		}
		a[n] = res;
	}
	return res;
}

ull dp_topdown(int n)
{
	// ull res = 0;	
	for(int i = 2; i <=n; i++)
	{
		for(int j = 0; j < i; j++)
		{
			a[i] += a[j] * a[i - j - 1];
		}
	}
	return a[n];
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
    std::cin >> n;
    std::cout << naive_approach(n) << std::endl; // takes a lot of time for n = 31; 
 
    // MEMORIZATION APPROACH
    a = new ull [n + 1];
    memset(a, 0, sizeof(ull) * (n + 1));
    a[0] = 1;
    a[1] = 1;
    std::cout << dp_memorization(n) << std::endl;
	delete [] a;

	// TOP DOWN APPROACH
	a = new ull [n + 1];
	memset(a, 0, sizeof(ull) * (n + 1));
	a[0] = 1;
    a[1] = 1;
    std::cout << dp_topdown(n) << std::endl;
	delete [] a;


    return 0;
}