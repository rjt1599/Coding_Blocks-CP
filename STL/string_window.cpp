#include<iostream>
#include<string>
#include<climits>
#define ll long long

int main()
{
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	#endif

	std::string s1, s2;
	std::getline(std::cin ,s1);
	// std::cin.get();
	std::getline(std::cin, s2);

	if(s1.length() < s2.length())
	{
		std::cout << "No String";
		return 0;
	}

	int len1, len2;
	len1 = s1.length();
	len2 = s2.length();

	int hash_s2[256] {0};
	int hash_s1[256] {0};

	for(int i = 0; i < len2; i++ )
	{
		hash_s2[s2[i]]++;
	}

	int count = 0;
	int start, start_index, min_length;
	start_index = -1;
	min_length = INT_MAX;
	start = 0;

	for(int i = 0; i < len1; i++)
	{
		hash_s1[s1[i]]++;	
		if(hash_s2[s1[i]] != 0 && hash_s1[s1[i]] <= hash_s2[s1[i]] ){
			count++;

		} 

		if(count == len2){
			// start = i;
			while(hash_s2[s1[start]] == 0 || hash_s1[s1[start]] > hash_s2[s1[start]])
			{	
				if(hash_s1[s1[start]] > hash_s2[s1[start]])
				{
					hash_s1[s1[start]]--;
				}
				start++;
			}
			int len = i - start + 1;
			if(min_length > len)
			{
				min_length = len;
				start_index = start;
			}
			i = start + len - 1;
		}

	}
	if(start_index == -1 )
	{
		std::cout << "No String";
		return 0;
	}
    else
    	std::cout << s1.substr(start_index, min_length);
    return 0;
}