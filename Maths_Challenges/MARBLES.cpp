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

using namespace std;

ll C(ll n, ll k)
{	
	ll res = 1;
	if(k > n- k) k = n -k;
	if(k == 0) return 1;

	ll num = n;
	// ll denom = 1;


	// ** Important **
	// There is a number number in i consecutive numbers divisible by i
	for(ll i = 1; i <=k; i++)
	{
		// num = n;
		// denom = i;
		res *= (num);
		res /= i;
		num--;
		// k--;
	}
	// res = num / denom;
	return res;
}

int main()
{
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	#endif

    int t;
    std::cin>> t;
    while(t--)
    {
    	ll n, k;
    	std::cin >> n >> k;

    	if(n < k)
    	{
    		std::cout << 0;
    		// return 0;
    	}
    	else if(n == k)
    	{
    		std::cout << 1;
    		// return 0;
    	}
    	else
    	{
    		std::cout << C(n - 1, k - 1);
    	}
    	// return 0;
    	std::cout << std::endl;
    }
    
    // return 0;

    //     int testCases;
    // cin >> testCases;
    // while (testCases--) {
    //     ll n,r;
    //     cin >> n >> r;
    //     if(n-r < r-1) {
    //         r=n-r+1;
    //     }

    //     if(r == 1) {
    //         cout << 1 << endl;
    //         continue;
    //     }

    //     //Ans = (n-1)!/((r-1)! * (n-r)!)

    //     ll ans = 1;
    //     for(ll i=n-1; i>=n-r+1;i--) {
    //         ans = ans*i;
    //         ans = ans/(n-i);
    //     }

    //     cout << ans << endl;
    // }



    return 0;

}