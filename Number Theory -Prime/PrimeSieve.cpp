#include<iostream>
#include<cstring>
#define ll long long

void prime_sieve(ll * arr, ll limit)
{
	memset(arr, 0, sizeof(ll) * (1000005));

	for(ll i = 4; i <= limit; i += 2)
	{
		arr[i] = -1;
	}
	// std::cout << arr[3];
	for(ll i = 3; i <= limit; i += 2)
	{	
		if(arr[i] == 0)
		{
			for(ll j = i * i; j <= limit; j += i)
			{
				arr[j] = -1;
			}
		}
	}


	//base cases
	arr[2] = 0;
	arr[1] = arr[0] = -1;
}

int main(int argc, char * argv[])
{	

	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	#endif


	ll limit;
	std::cin >> limit;

	// std::cout <<limit;
	ll arr[1000005];

	prime_sieve(arr, limit);

	for(int i = 0; i <= limit; i++)
	{	
		if (arr[i] == 0)
		{	
			std::cout << i << " ";
		}
	}

	return 0;

}