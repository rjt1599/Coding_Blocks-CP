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

    int t;
    std::cin >> t;
    while(t--)
    {
    	std::string s1, s2;
    	std::cin >> s1 >> s2;

    	for(int i = 0; i < s1.size(); i++)
    	{
    		int val = (static_cast<int>(s1[i]) - 48) ^ (static_cast<int>(s2[i]) - 48);
    		std::cout << val ;
    	}
    	std::cout << std::endl;
    }
    
    return 0;
}
