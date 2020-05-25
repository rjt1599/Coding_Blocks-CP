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

int GCD;
int limit;

void gcd(int a, int b)
{
	if(b==0)
	{
		GCD = a;
		return;
	}
	gcd(b, a % b);
}
int lcm(int a, int b )
{
	gcd(a, b);
	return a * b / GCD;
}

std::vector<int> create_prefix(int a, int b)
{
	
	std::vector<int> prefix(limit, 0);

	for(int i = 0; i < limit; i++)
	{
		if(((i % a) % b) != ((i % b) % a))
		{	
			if(i == 0)
				prefix[i] = 1;
			else
				prefix[i] = prefix[i - 1] + 1;
		}
		else
		{	
			if(i != 0)
			prefix[i] = prefix[i - 1];
		}
	}
	return prefix;
}

ll counter(std::vector<int> &prefix, ll r)
{
	// int limit = lcm(a, b);
	// if(r == 0) return 0;
	ll ans = 0;
	ans = (r / limit) * prefix[limit - 1];
	ans += prefix[r % limit];

	return ans;

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
    	int a, b, q;
    	std::cin >> a >> b >> q;
    	limit = lcm(a, b);
    	// std::cout << limit << std::endl;
    	std::vector<int>prefix = create_prefix(a, b);
    	for(int i = 0; i < q; i++)
    	{
    		ll l, r;
    		std::cin >> l >> r;

    		ll ans_r = counter(prefix, r);
    		ll ans_l = counter(prefix, l - 1);

    		std::cout << ans_r - ans_l << " ";

    	}
    	std::cout << std::endl;
    }
    
    return 0;
}