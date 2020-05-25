#include<iostream>
#define ll long long
#define LIMIT 1000000
int arr[1000005];
ll count [1000005];

void prime_sieve()
{	
	for(ll i = 0;i <= LIMIT; i++)
	{
		count[i] = 0;
	}
	for(ll i = 0;i <= LIMIT; i++)
	{
		arr[i] = 1;
	}

	// base cases
	arr[2] = 1;
	arr[0] = arr[1] = 0;


	for(ll i = 4; i <= LIMIT; i += 2)
	{
		arr[i] = 0;
	}

	for(ll i = 0; i <= LIMIT; i += 1)
	{	
		count[i] = count[i - 1] + arr[i];
		if(arr[i] == 1)
		{
			for(ll j = i * i; j <= LIMIT; j += i)
			{
				arr[j] = 0;
			}
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

	prime_sieve();

	ll n;
	std::cin >> n;

	while(n--)
	{
		ll a, b;
		std::cin >> a >> b;
		ll counter = count[b] - count[a] + arr[a];

		
		std::cout << counter << std::endl;

	}

	return 0;
}