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

void multiply(int * a, int n, int & digits)
{
	int carry = 0;

	for(int i = 0;i <digits; i++)
	{
		a[i] = a[i] * n + carry;
		carry = a[i] / 10;
		a[i] = a[i] %10;
	}
	while(carry)
	{
		a[digits] = carry % 10;
		carry = carry / 10;
		digits++;
	}
}

void big_factorial(int n)
{
	int * a;
	a = new int [1000];
 
	for(int i = 0; i < 1000; i++)
	{
		a[i] = 0;
	}
 
	int digits = 0;

	a[0] = 1;
	digits = 1;

	for(int i = 1; i <= n; i++)
	{
		multiply(a, i, digits);
	}

	for(int i = digits - 1; i >=0; i--)
	{
		std::cout << a[i];
	}
	std::cout << std::endl;

	delete [] a;

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
    big_factorial(n);
    
    return 0;
}