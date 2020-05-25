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
    int t = 10;
    while(t--)
    {
	    int s[101] {0};
	    int k[101] {0};

	    char ch;
	    int n1 = 0;
	    while((ch = std::cin.get()) != '\n')
	    {
	    	s[n1] = ch - '0';
	    	n1++;
	    }

	    int n2 = 0;
	    while((ch = std::cin.get()) != '\n')
	    {
	    	s[n2] = ch - '0';
	    	n2++;
	    }

	    
	}

    
    return 0;
}