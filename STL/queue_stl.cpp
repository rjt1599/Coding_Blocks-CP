#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
#include<cstring>
#include<string>
#include<queue>
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
    std::queue<int> qs;

    for(int i = 1; i <= 5; i++)
    {
    	qs.push(i);
    }

    for(int i = 1; i <= 5;i++)
    {
    	std::cout << qs.front() << "<--";
    	qs.pop();
    }
    std::cout << std::endl;
    std::cout << "Done with the queue!!";
    
    return 0;
}