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


std::vector<int> a;

void opti(int n, int k)
{
	

    int sum = 0;
    int min = INT_MAX;
    
    int i = 0, j = 0;
    while(i < n && j < n)
    {
    	while(sum < k)
    	{
    		sum += a[j];
    		j++;
    	}
    	if(sum == k)
    	{
    		int len = j - i;
    		// std::cout << i << " "<< j << std::endl;
    		if(min > len)
    		{
    			min = len;
    		}
    		sum = sum - a[i];
    	}
    	else
    	{
    		sum = sum - a[i];
    	}
    	i++;
    }
    std::cout << min << std::endl;
}

void brute(int n, int k)
{

    int sum = 0;
    int min = INT_MAX;
    // std::cout << n << " " << k << std::endl;

    for(int i = 0; i <n; i++)
    {
    	for(int j = 0; j < n; j++)
    	{	
    		sum = 0;
    		for(int l = i; l <=j; l++)
    		{
    			sum += a[l];
    			if(sum > k)
    			{
    				break;
    			}
    			if( sum == k)
    			{
    				int len = l - i + 1;
    				if(min > len)
    				{
    					min = len;

    				}
    				break;
    			}

    		}
    	}
    }
    std::cout << min << std::endl;
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

    int n, k;
    std::cin >> n >> k;

   	a.resize(n);

    for(int i = 0; i <n; i++)
    {
    	std::cin >> a[i];
    }
    
  	// optimized method
  	// opti(n, k);
  	// brute force
  	brute(n, k);
    
    return 0;
}