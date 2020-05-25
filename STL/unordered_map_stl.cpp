#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
#include<cstring>
#include<string>
#include<unordered_map>
#define ll long long
#define REP(i,l,r) for((i)=(l);(i)<=(r);++(i))
#define REP2(i,l,r) for((i)=(l);(i)!=(r);++(i))


class Student
{
public:
	int rollno;
	std::string firstname;
	std::string lastname;

	Student(int r, std::string f, std::string l)
	{
		rollno = r;
		firstname = f;
		lastname = l;
	}

	bool operator ==(const Student &x) const
	{
		return x.rollno == rollno;
	}
};

class HashFcn
{
public:
	size_t operator()(const Student & x) const
	{
		return x.firstname.length() + x.lastname.length();
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

    Student s1 (10, "Prateek", "Narang");
    Student s2 (23, "Rahul", "Kumar");
    Student s3 (30, "Prateek", "Gupta");
    Student s4 (120, "Rahul", "Kumar");

    std::unordered_map<Student, int, HashFcn> m;

    m.insert(std::make_pair(s1, 20));
    m.insert(std::make_pair(s2, 50));
    m.insert(std::make_pair(s3, 90));
    m.insert(std::make_pair(s4, 120));

    for(auto & x:m)
    {
    	std::cout << x.first.firstname << " " << x.first.lastname<< " Marks "<< x.second<< std::endl;
    }

    m.erase(s2);

    std::cout << std::endl;
    for(auto & x:m)
    {
    	std::cout << x.first.firstname << " " << x.first.lastname<< " Marks "<< x.second<< std::endl;
    }

    return 0;
}