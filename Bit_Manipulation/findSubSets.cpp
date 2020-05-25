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

void filterChars(int n, std::string s)
{		
	int lastbit = 0;
	int j = 0;
	while(n > 0)
	{
		lastbit = n & 1;
		if(lastbit)
		{
			std::cout << s[j];
		}
		n = n >> 1;
		j++;
	}
}

void printSubset(std::string s)
{
	int n = s.size();

	for(int i = 0; i < (1 << n);i++ )
	{
		filterChars(i, s);
		std::cout << std::endl;
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

    std::string s;
    std::cin >> s;

    printSubset(s);
    
    return 0;
}