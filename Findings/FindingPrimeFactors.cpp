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

void primeFactors(int n)
{
	while(n % 2 == 0)
	{
		std::cout << 2 <<" ";
		n /= 2;
	}

	// Now left only are odd prime factors
	for(int i = 3; i * i <= n; i+= 2)
	{
		while(n % i == 0)
		{
			std::cout << i << " ";
			n /= i;
		}
		if(n == 1) break;
	}

	if(n > 2) std::cout << n << " ";

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

   	primeFactors(n);

    
    return 0;
}