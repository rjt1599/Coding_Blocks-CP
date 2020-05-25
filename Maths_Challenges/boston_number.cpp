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

int sumOfDigits(int n)
{	
	int sum = 0;
	while(n > 0)
	{
		sum += n % 10;
		n = n / 10;
	}
	return sum;
}

int sumofPrime(int n)
{
	int sum = 0;

	while(n % 2 == 0)
	{
		n /= 2;
		sum += 2;
	}

	for(int i = 3; i * i <= n; i += 2)
	{
		while(n % i == 0)
		{
			n /= i;
			sum += sumOfDigits(i);
		}
	}
	if(n >2) sum += sumOfDigits(n);

	return sum;
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

    int x = sumOfDigits(n);
    int y = 0;

    y = sumofPrime(n);

    if(x == y)
    {
    	std::cout << "YES" << std::endl;
    }
    else std::cout << "NO" << std::endl;
    
    return 0;
}