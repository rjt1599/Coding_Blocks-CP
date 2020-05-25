#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
#include<cstring>
#include<string>
#include<stack>
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

	std::stack<int> ls ;

	int i = 0;
	for(; i < 5; i++)
	{
		ls.push(i);
	}

	while(!ls.empty())
	{
		std::cout << ls.top() << ", ";
		ls.pop();
	}
	\
	std::cout << std::endl << "Done with the stack!!"<<std::endl;
    
    return 0;
}