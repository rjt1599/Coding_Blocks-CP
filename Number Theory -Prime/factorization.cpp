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

void printFactors(int n)
{
	for(int i = 2; i * i <=n; i++)
	{
		while(n % i == 0)
		{
			std::cout << i << " ";
			n = n / i;
		}
	}
	if(n >=2)
	{
		std::cout << n;
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

	/*
	//Use fast i/o at starting of main() i.e.

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	*/

    int n;
    std::cin >> n;
    printFactors(n);
    
    return 0;
}