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
// const limit = 3000;
int track[3000];
// int prime[3000];


int prime_sieve(int limit)
{	
	int count = 0;
	for(int i = 0; i <= limit;i++)
	{
		track[i] = 0;
		// prime[i] = 0;
	}
	// track[0] = track[1] = 0;
 // 	track[2] = 0;

	for(int i = 2; i <= limit; i++)
	{	
		if(track[i] == 0)
		{
			
			for(int j = i; j <= limit; j += i)
			{
				track[j]++;
			}
		}
		else if(track[i] == 2)
		{
			count++;
		}
	}


	return count;
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
	int count = 0;
	count = prime_sieve(n);

	std::cout << count;

    
    return 0;
}