#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
#include<cstring>
#include<string>
#define ll long long
#define ull unsigned long long
#define REP(i,l,r) for((i)=(l);(i)<=(r);++(i))
#define REP2(i,l,r) for((i)=(l);(i)!=(r);++(i))

int main()
{
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	#endif

    ull n;
    std::cin >> n;

    if(n >= 130) 
    {
    	std::cout << "Yes";
    	return 0;
    }

    std::vector<ull> v(n);

    for(ull i = 0; i < n; i++)
    {
    	ull val;
    	std::cin >> val;
    	v[i] = val;
    }

    std::sort(v.begin(), v.end());

    

    for(ull i = 0; i < n; i++)
    {
    	ull interm = 0;
    // 	interm ^= v[i];
    	for(ull j = i + 1; j < n; j++)
    	{	
    		// interm ^= v[j];
    		for(ull k = j + 1; k < n; k++)
    		{
    			interm = v[i] ^ v[j] ^ v[k];
    			if(std::binary_search(v.begin() + k + 1, v.end(), interm))
    			{	
    				std::cout << "Yes";
    				return 0;
    			}
    			interm = 0;
    		}
			// interm ^= v[j];
    	}
		// interm ^= v[i];
    }
    
    std::cout << "No";
    return 0;
}