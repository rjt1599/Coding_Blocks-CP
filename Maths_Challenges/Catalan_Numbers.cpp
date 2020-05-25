#include<iostream>
#define ull unsigned long long
int main() {

	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	#endif

	int n;
	std::cin >> n;
	ull res = 1;
	if(n ==  0 || n == 1) std::cout << n;
	else
	{
		for(int i = 1; i <= n;i++)
		{
			res *= (2 * n - i + 1);
			res /= i;
		}
		res /= (n + 1);
		std::cout << res;
	}

	return 0;
}