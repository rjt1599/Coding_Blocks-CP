// good for n < 3 * 10 ^ 8

// due to overflow need modular multiplication

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

ll modular_multiplication(ll a, ll b, ll n)
{
	ll res = 0;
	a = a % n;
	while(b > 0)
	{
		if(b & 1)
		{
			res = (res + a) % n;
		}
		b = b >> 1;
		a = ( a + a) % n;
	}
	return res;
}

ll modular_exponentiation(ll a, ll d, ll n)
{
	a = a % n;
	ll res = 1;
	while(d >  0)
	{
		if(d & 1)
		{
			// res = (res * a) % n;// will need modular multipilication due to overflow
			res = modular_multiplication(res, a, n);
		}
		d =  d >> 1;
		a = modular_multiplication(a, a, n);
	}
	return res;
}

bool miller_rabin(ll n)
{
	if(n == 1) return false;
	if(n == 2) return true;
	if(n % 2 == 0) return false;

	// now the number is odd and >= 3
	ll d = n - 1;
	ll s = 0;
	while(d % 2 == 0)
	{
		d /= 2;
		s++;
	}

	// create vector on a's
	std::vector<ll>A{2, 3, 5, 7, 9, 11, 13, 17, 19};

	for(ll i = 0; i < A.size(); i++)
	{	
		ll a = A[i];
		if( a > (n - 2)) continue;

		ll ad = modular_exponentiation(a, d, n);
		if(ad == 1) continue;

		bool prime = false;		
		for(ll r = 0; r <= s -1; r++ )
		{	
			// calculates 2 ^ r
			ll rr = 1 << r;
			ll ard = modular_exponentiation(ad, rr, n);
			if(ard == n - 1)
			{
				prime = true;
				break;
			}
		}
		if(prime == false)
		{
			return false;
		}

	}
	return true;		
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
    int t;
    std::cin >> t;
    while(t--)
    {	
	    ll n;
	    std::cin >> n;

	    if(miller_rabin(n))
	    {
	    	std::cout << "Prime" << std::endl;
	    }
	    else
	    {
	    	std::cout << "Not Prime" << std::endl;
	    }
	}   
    return 0;
}