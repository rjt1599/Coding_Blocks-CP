// bitset occupies less space
// space optimization for large arrays;
#include<bits/stdc++.h>
#include<iostream>
#include<bitset>
#include<vector>
#define ll long long

using namespace std;

const int limit = 1000000;	
std::vector<ll> primes;

std::bitset<1000006> arr;

void bitset_sieve()
{
	
	arr.set();

	arr[0] = arr[1] = 0;

	for(ll i = 2; i <= limit; i++)
	{
		if(arr[i])
		{	
			primes.push_back(i);
			for(ll j = i * i; j <= limit; j += i)
			{
				arr[i] = 0;
			}
		}
		
	}
}

bool isPrime(ll No)
{	
	if(No <= limit)
	{
		return (bool)arr[No];
	}
	for(int i = 0; primes[i] * primes[i] <= No; i++)
	{
		if(No % primes[i] == 0)
		{
			return false;
		}
	}

	return true;
}

int main ()
{
	
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txtb
    freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	bitset_sieve();
	ll n;
	std::cin >> n;

	if(isPrime(1234567899))
	{
		std::cout << "Yes it is!!";
	}
	else
	{
		std::cout << "Sadly Not!";
	}

	return 0;
}
