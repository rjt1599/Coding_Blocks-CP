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

    //find uses linear search. for unsorted arrays;

    int arr[5] { 1, 2, 3, 4, 5};

    int val;
    std::cin >> val;

  	auto it = std::find(arr, arr + 5, val);

  	if(it - arr == 5) std::cout << val <<" Not found in the array.";
  	else std::cout << val << " found at "<< "index "<< it - arr; 
    
    return 0;
}