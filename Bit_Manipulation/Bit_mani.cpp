#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
#include<cstring>
#include<string>
#define ll long long
#define REP(i,l,r) for((i)=(l);(i)<=(r);++(i))
#define REP2(i,l,r) for((i)=(l);(i)!=(r);++(i))

bool isOdd(int n)
{
	return n & 1;
}

int getBit(int n, int i)
{
	int mask = 1 << i;

	return mask & n ? 1:0;
}
void setBit(int &n, int i)
{
	int mask = 1 << i;
	n = n | mask;
}
void clearBit(int &n, int i)
{
	int mask = ~(1<<i);
	n = mask & n;
}
void updateBit(int &n, int i, int v)
{
	// if(v)
	// {
	// 	setBit(n,i);
	// }
	// else
	// {
	// 	clearBit(n, i);
	// }
	int mask = ~(1 << i);
	int cleared_no = n & mask;
	n = cleared_no | (v << i);

}
int clearLastIBits(int n, int i)
{
	int mask = (-1) << i;
	return n & mask;
}
int clearRangeBits(int n, int i, int j)
{
	// int mask = ((-1) << j + 1) | (~((-1) << i));
	int mask = ((-1) << j + 1) | ((1 << i) - 1);
	return n & mask;
}
int main()
{
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	#endif

    int n;
    std::cin >>n;

    if(isOdd(n))
    {
    	std::cout << n << " is Odd"<< std::endl;
    }
    else
    {
    	std::cout << n << " is Even" << std::endl;
    }
    int i;
    std::cin >> i;

    std::cout << "The Bit at the "<<i<<"th position is "<<getBit(n, i)<<std::endl;

    setBit(n, i);
    std::cout << "The Bit at the "<<i<<"th position is set to "<<1<<std::endl; 
    std::cout << "The value is now: "<< n << std::endl;

    clearBit(n,i);
    std::cout << "The Bit at the "<<i<<"th position is cleared to "<<0<<std::endl; 
    std::cout << "The value is now: "<< n << std::endl;

    int v = 1;
	updateBit(n,i, v);
    std::cout << "The Bit at the "<<i<<"th position is updated to "<<v<<std::endl; 
    std::cout << "The value is now: "<< n << std::endl;    

    std::cout << clearRangeBits(31, 1, 3);


    return 0;
}