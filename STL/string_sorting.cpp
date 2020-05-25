#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
#include<string>
#define ll long long
#define REP(i,l,r) for((i)=(l);(i)<=(r);++(i))
#define REP2(i,l,r) for((i)=(l);(i)!=(r);++(i))

using namespace std;

bool compare(string a, string b)
{
	if(a.length() == b.length())
	{
		return a < b;
	}
	return a.length() > b.length();
}


int main()
{
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	#endif

    int n;
    std::cin >> n;
    cin.get();

    std::vector<string> str(n);

    for(int i = 0; i < n; i++)
    {
    	std::getline(std::cin, str[i]); // cin.getline() not available for string class
    }

    std::sort(str.begin(), str.end()); // default lexicographical ordering

    for(int i = 0; i < n; i++)
    {
    	std::cout << str[i]<<std::endl;
    }

    std::cout << "Now diff ordering"<<std::endl;

    std::sort(str.begin(), str.end(), compare);

    for(int i = 0; i < n; i++)
    {
    	std::cout << str[i]<<std::endl;
    }

    
    return 0;
}