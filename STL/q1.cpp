#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
bool comparefc(const std::string & lhs, const std::string & rhs)
{
	if(lhs[0] < rhs[0]) return true;
	else if(lhs[0] > rhs[0]) return false;
	else
	{
		if(rhs.find(lhs) == 0) return false;
		else if(lhs.find(rhs) == 0) return true;
		else{
			return lhs < rhs;
		}
	}
}
int main() {

	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	#endif

	int n;
	std::cin >> n;
	std::vector<std::string> v;
	v.reserve(n);
	for(int i = 0; i < n; i++)
	{
		std::string s;
		std::cin >> s;
		v.push_back(s);
	}
	std::sort(v.begin(), v.end(), comparefc);

	for(int i = 0; i < n; i++)
	{
		std::cout << v[i] << std::endl;
	}
	return 0;
}