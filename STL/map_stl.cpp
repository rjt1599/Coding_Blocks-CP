#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
#include<cstring>
#include<string>
#include<map>
#define ll long long
#define REP(i,l,r) for((i)=(l);(i)<=(r);++(i))
#define REP2(i,l,r) for((i)=(l);(i)!=(r);++(i))
// maps stored as pair objects in self balancing BST.
int main()
{
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	#endif

	std::map<std::string, int > m;

	//1.Insert
	m.insert(std::make_pair("Mango", 300));

	m["Apple"] = 120;

	std::pair<std::string, int> p;
	p.first = "Banana";
	p.second = 30;
	m.insert(p);

	//2.Query

	//Using iterator
	auto it = m.find("Banana");
	if(it != m.end())
	{
		std::cout << "The price of "<< it->first << " " << it->second <<std::endl;
	}
	else
	{
		std::cout << "Could'nt find"<<std::endl;
	}
	if(m.count("Mango"))
	{
		std::cout << "The price of "<< "Mango" << " " << m["Mango"] <<std::endl;
	}
	else
	{
		std::cout << "Could'nt find"<<std::endl;
	}
    
    //3.erase
    m.erase("Banana");
     it = m.find("Banana");
	if(it != m.end())
	{
		std::cout << "The price of "<< it->first << " " << it->second <<std::endl;
	}
	else
	{
		std::cout << "Could'nt find"<<std::endl;
	}

	m["Litchi"] = 350;
	m["Pinapple"] = 120;

	//iterate over the elements
	for(auto it = m.begin(); it != m.end(); it++)
	{
		std::cout << it->first << " " << it->second <<std::endl;
	}


	for(auto p : m)
	{
		std::cout << p.first << " " << p.second << std::endl;
	}

    return 0;
}