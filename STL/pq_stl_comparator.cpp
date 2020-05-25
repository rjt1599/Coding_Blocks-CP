#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
#include<queue>
#include<cstring>
#include<string>
#define ll long long
#define REP(i,l,r) for((i)=(l);(i)<=(r);++(i))
#define REP2(i,l,r) for((i)=(l);(i)!=(r);++(i))

using std::string;
class Person
{
public:
	int age;
	std::string name;

	Person(){

	}
	Person(const string & n, const int & a)
	{
		age = a;
		name = n;
	}

};

class PersonCompare
{
public:
	bool operator()(const Person & lhs, const Person & rhs)
	{	
		std::cout << "Comparing " << lhs.name << " and "<< rhs.name << std::endl;
		return (lhs.age > rhs.age);
	}
};
int main()
{
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	#endif

    std::priority_queue<Person, std::vector<Person>, PersonCompare> pq;
    int n;
    std::cin >> n;

    for(int i = 0; i < n; i++)
    {
    	int age;
    	string name;
    	std::cin >> age;
    	std::getline(std::cin,name);
    	std::cout << age << " " << name << std::endl;

    	pq.push(Person(name, age));
    }

    for(int i = 0; i < 2; i++)
    {
    	std::cout << "Name " << pq.top().name << " Age" << pq.top().age<<std::endl;
    	pq.pop();
    }
    return 0;
}