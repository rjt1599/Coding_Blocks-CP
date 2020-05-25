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

void UniqueNumber2()
{	
	int n;
	std::cin >> n;
	std::vector<int> arr;
	arr.reserve(n);

	int res = 0;
	for(int i = 0; i < n; i++)
	{
		int  val;
		std::cin >> val;
		arr.push_back(val);

		res = res ^ val;
	}

	int temp = res;
	int pos = 0;

	while((temp & 1) == 0)
	{
		temp >> 1;
		pos++;
	}

	int mask = 1 << pos;

	int x = 0;
	int y = 0;
	for(int i = 0; i < n; i++)
	{
		if((arr[i] & mask) > 0)
		{
			x = x ^ arr[i];
		}
	}

	y = res ^ x;

	std::cout << std::min(x, y) << " " << std::max(x, y);

}

int main()
{
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	#endif

    UniqueNumber2();
    
    return 0;
}