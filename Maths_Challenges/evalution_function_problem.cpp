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

std::string add_string(std::string s1, std::string s2)
{	
	std::string res;
	int carry = 0;
	int i = 0;
	int n1  = s1.size(), n2 = s2.size();
	for(; i < std::min(n1, n2); i++)
	{	
		std::cout << static_cast<int>(s1[n1 - i]) << std::endl;
		int val = carry + static_cast<int>(s1[n1 - i] - '0') + static_cast<int>(s2[n2 - i] - '0');
	 	if( val > 9)
	 	{
	 		val = val - 10;
	 		carry = 1;
	 	}
	 	res.push_back(val + '0');
	 	// std::cout << val;
	}

	std::string s = n1 > n2 ? s1 : s2;

	int n = s.size();
	for(; i < n; i++)
	{
		char val = carry + s[n - i];

		if( val > 9)
	 	{
	 		val = val - 10;
	 		carry = 1;
	 	}
	 	res.push_back(val + '0');
	} 	

	if(carry != 0)
	{
		res.push_back(carry + '0');
	}

	// std::cout << res;
	std::reverse(res.begin(), res.end());
	return res;
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

    std::string x, y;
    std::cin >> x >> y;
    std::cout << add_string(x, y);
    // std::cout << add_string(x, y);
    
    return 0;
}