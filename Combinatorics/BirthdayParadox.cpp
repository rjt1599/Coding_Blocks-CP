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
    std:: cin >> p;

    int n = 0;
    float x = 1.0;
    int num = 365;
    int denom = 365;

    if(p == 1.0)
    {
    	std::cout << 366;
    	return 0;
    }

    while(x > 1- p)
    {
    	
    	x = (x * num) / denom;
    	n++;
    	num--;

    	std::cout << "Value of x is " << x << " and of n is " << n << std::endl;
    }

    
    return 0;
}