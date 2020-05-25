#include<iostream> 
#define ll long long

ll bitmask_approach(ll N, ll P)
{
	ll res = 1;
	while(P > 0)
	{	
		if(P & 1)
		{
			res = res * N;
		}
		N = N * N;
		P = P >> 1;
	}
	return res;
}
// don't forget the base case in recursion
ll recursive_approach(ll N, ll P)
{
	ll interm;
	ll res;
	// std::cout << N <<" " << P << std::endl;
	if(P == 1) return N;
	if(P & 1)
	{
		res = N * recursive_approach(N, P -1);
	}
	else
	{	
		interm = recursive_approach(N, P/2);
		res = interm * interm;
	}
	// std::cout << res << " ";
	return res;
}

int main() {

	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	#endif

	
	ll N, P;
	std::cin >> N >> P;
	
	//bitmasking approach
	// std::cout << bitmask_approach(N, P) << std::endl;
	// recursive approach
	std::cout << recursive_approach(N, P) << std::endl;
	
	return 0;
}