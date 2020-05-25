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

void least_prime(int n)
{
	int * a;
	a = new int [n + 1];	
	memset(a, 0, sizeof(int) * (n + 1));

	a[1] = 1;

	std::cout << 1 << " " << 1 << std::endl;
	for(int i = 2; i <=n; i++)
	{	
		if(a[i] == 0)
		{	
			std::cout << i << " " << i << std::endl;
			a[i] = i;
			for(int j = i * i; j <=n; j += i)
			{
				if(a[j] == 0)
					a[j] = i;
			} 
		}
		else
		{
			std::cout << i << " " << a[i] << std::endl;
		}
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

    int n;
    std::cin >> n;
    least_prime(n);
    
    return 0;
}