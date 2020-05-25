#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
#include<cstring>
#include<string>
#include<deque>
#define ll long long
#define REP(i,l,r) for((i)=(l);(i)<=(r);++(i))
#define REP2(i,l,r) for((i)=(l);(i)!=(r);++(i))

std::vector<ll> a;

void opti(ll n, ll k)
{
	std::deque<std::pair<ll, ll>> d;

	for(int i = 0; i < n; i++)
	{	
		if(d.empty())
		{
			d.push_front(std::make_pair(a[i], i));
		}
		else
		{	
			auto it = d.front();
			if(a[i] >= it.first)
			{
				d.clear();
				d.push_front(std::make_pair(a[i], i));
			}
			else
			{
				auto  it = d.back();
				while(a[i] >= it.first)
				{
					d.pop_back();
					it = d.back();
				}
				d.push_back(std::make_pair(a[i], i));
			}

		}
		if(i >= k - 1)
		{	
			auto it = d.front();
			std::cout << it.first << " ";
			if((i - it.second + 1) >= k)
			{
				d.pop_front();
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

	/*
	//Use fast i/o at starting of main() i.e.

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	*/

    ll n, k;
    std::cin >> n;
    a.resize(n);

    for(int i = 0; i < n; i++)
    {
    	std::cin >>a[i];
    }
    std::cin >> k;

    opti(n, k);

    
    return 0;
}