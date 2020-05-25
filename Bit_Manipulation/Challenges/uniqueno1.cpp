#include<iostream>
int main() {
	// return 0;

	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	#endif

	int n;
	int ans = 0;
	std::cin >> n;

	while(n--)
	{
		int val;
		std::cin >> val;
		ans = ans ^ val;
	}
	std::cout << ans;
	return 0;
}