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

int main()
{
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	#endif

    std::vector<int> v {1, 2, 3, 4};

    v.insert(v.begin() + 2, 3, 100);

    for(const int & x: v)
    {
    	std::cout << x << ", ";
    }
    std::cout << std::endl;

std::vector<int> b {100, 200, 300};
v.insert(v.begin() + 5, b.begin(), b.end());    
    
    for(const int & x: v)
    {
    	std::cout << x << ", ";
    }
    std::cout << std::endl;

    v.erase(v.begin() + 2);
    for(const int & x: v)
    {
    	std::cout << x << ", ";
    }
    std::cout << std::endl;

    v.erase(v.begin() + 2, v.begin() + 5);
    for(const int & x: v)
    {
    	std::cout << x << ", ";
    }
    std::cout << std::endl;
        
    return 0;
}


