/*
https://www.spoj.com/problems/HOLI/
*/
// ** use of dfs and pigeon hole principle
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
#include<cstring>
#include<string>
#include<list>
#define ll long long
#define REP(i,l,r) for((i)=(l);(i)<=(r);++(i))
#define REP2(i,l,r) for((i)=(l);(i)!=(r);++(i))

class Graph
{
	ll v;
	std::list<std::pair<ll, ll>> * l;

	public:
		Graph(ll V)
		{
			v = V;
			l = new std::list<std::pair<ll, ll>> [V +1];
		}

		void addEdge(ll u, ll v, ll cost)
		{
			l[u].push_back(std::make_pair(v, cost));
			l[v].push_back(std::make_pair(u, cost));
			// std::cout << u << " " << l[u].back().first << " "<< l[u].back().second << std::endl;
		}

		ll dfs()
		{
			// std::vector<bool> visited(v, false);
			// std::vector<ll> count(v, 0);

			bool * visited;
			ll * count;

			visited = new bool[v + 1];
			count = new ll [v + 1];

			for(ll i = 1; i <= v; i++)
			{
				visited[i] = false;
				count[i] = 0;
			}

			ll ans = 0;
			dfs_helper(1, visited, count, ans);

			return ans;

		}

		ll dfs_helper(ll node, bool * visited, ll * count, ll &ans)
		{
			visited[node] = true;
			count[node] = 1;

			for(auto it = l[node].begin(); it != l[node].end(); it++)
			{	
				ll nbr = it->first;
				ll wt = it->second;
				if(!visited[nbr])
				{	
					ll nx, ny;
					
					nx = dfs_helper(nbr, visited, count, ans);
					count[node] += nx;
					ny = v - nx;
					ans += 2 * std::min(nx, ny) * wt;
				}

			}
			return count[node];
		}

};

int main()
{
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	#endif

    ll t;
    std::cin >> t;
    
    ll i = 1;
    
    while(t--)
    {
    	ll n;
    	std::cin >> n;

    	Graph g(n);

    	ll X, Y, Z;
    	for(ll i = 0; i < n - 1; i++)
    	{
    		std::cin >> X >> Y >> Z;
    		g.addEdge(X, Y, Z);
    	}

    	ll ans = 0;
    	ans = g.dfs();

    	std::cout << "Case #"<<i << ": "<< ans;
    	if(t >= 1)
    	std::cout << std::endl;
    	
    	i++;
    }
    
    return 0;
}