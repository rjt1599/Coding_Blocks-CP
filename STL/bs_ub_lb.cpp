#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
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

	int arr [] {10, 29, 45, 67};
	int n = sizeof(arr)/sizeof(arr[0]);

	int key;
	std::cin >> key;
	bool pre = std::binary_search(arr, arr + n, key);

	if(pre) std::cout << "Present";
	else std::cout << "Absent!";
	std::cout << std::endl;

	auto lb = std::lower_bound(arr, arr + n, key);
	auto ub = std::upper_bound(arr, arr + n, key);

	std::cout << "The lower bound is "<< lb - arr <<std::endl;
	std::cout << "The upper bound is "<< ub - arr << std::endl;

	std::cout << "The number of occurences are: "<< ub -lb << std::endl;
    
    return 0;
}