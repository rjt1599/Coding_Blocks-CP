#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
#include<string>
#define ll long long
#define REP(i,l,r) for((i)=(l);(i)<=(r);++(i))
#define REP2(i,l,r) for((i)=(l);(i)!=(r);++(i))
using std::string;
int main()
{
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	#endif

    string s0;
    string s1("Hello");

    string s2 = "Hello World!";
    string s3(s2);

    string s4 = s3;

    char a[] = {'a', 'b', 'c', '\0'};

    string s5(a);

    std::cout << s0 << std::endl;
    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;
    std::cout << s3 << std::endl;
    std::cout << s4 << std::endl;
    std::cout << s5 << std::endl;

    if(s0.empty()) std::cout << "s0 is empty"<<std::endl;

    // append
    s0.append("I love C++");
    std::cout << s0 << std::endl;
    s0 += " and Python";
    std::cout << s0 << std::endl;

    // Remove
    std::cout << s0.length() << std::endl;
    s0.clear();
    std::cout << s0.length() <<std::endl;

    // Compare the strings 

    s0 = "Apple";
   	s1 = "Mango";
   	std::cout << s1.compare(s0) << std::endl;
   		
   	if( s1 > s0)
   	{
   		std::cout << "Mango is lexi greater than Apple"<< std::endl;
   	}

   	//find substrings

   	string s = "I want apple Juice";
   	string word = "apple";
   	int index = s.find(word);

   	// remove the word
   	s.erase(index, word.length() + 1);
   	std::cout << s << std::endl;

   	//iterate all the elements
   	// three ways

   	// using indexes
   	for(int i = 0; i < s.length(); i++)
   	{
   		std::cout << s[i] << ":";
   	}
   	std::cout << std::endl;

   	// using iterators
   	for( string::iterator it = s.begin(); it != s.end(); it++ )
   	{
   		std::cout << *it << ".";
   	}
    std::cout << std::endl;

    // using for each loop
    for(const char &c: s)
    {
    	std::cout << c << ";";
    }
    std::cout << std::endl;

    return 0;
}