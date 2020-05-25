#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
#include<cstring>
#include<string>
#include<list>
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

    std::list<int> l1 {1, 2, 3, 4, 5};
    std::cout << l1.front()<<std::endl;
    std::cout << l1.back()<<std::endl;

    //remove element by the values
    // erase removes them by the iterator position

    l1.remove(3);

    for(const auto &x: l1)
    {
    	std::cout << x << "-->";
    }
    std::cout << std::endl;


//   auto it = l1.begin() + 5 // does not work here
    // no linear access. non contigous allocation

    // use it++.

    auto it = l1.begin();
    it++;
    it++;
    l1.insert(it, 3);


   for(const auto &x: l1)
    {
    	std::cout << x << "-->";
    }
    std::cout << std::endl;

    return 0;
}