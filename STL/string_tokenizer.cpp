#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
// #include<cstring>
#include<climits>
#include<string>
#define ll long long
#define REP(i,l,r) for((i)=(l);(i)<=(r);++(i))
#define REP2(i,l,r) for((i)=(l);(i)!=(r);++(i))

char * strtok(char * s, char * delim)
{	
	static char *orig;
	if(s != NULL) orig = s;
	
	if(*orig = '\0')
	{
		return NULL;
	}
	
	char * str = orig;

	char * end = NULL;

	char * ptr1 = orig;
	char * ptr2 = delim;
	// int count = 0;
	while(*ptr1 != '\0')
	{
		if(*ptr1 == *ptr2)
		{	
			
			// ptr2 = delim;
			char * start = ptr1;
			ptr1++;
			ptr2++;
			bool correct = true;
			while(*ptr2 != '\0')
			{
				if(*ptr1 != *ptr2)
				{
					correct = false;
					ptr2 = delim;
					break;

				}
				ptr1++;
				ptr2++;

			}
			if(correct)
			{
				end = start;
				break;
			}
		}
		ptr1++;
	}

	// if(end == NULL)
	// {
	// 	orig = ptr1;
	// 	return str;
	// }
	// else
	// {
	// 	*end = '\0';
	// 	orig = ptr1;
	// 	return str
	// }
	if(!end)
	{
		*end = '\0';
	}

	orig = ptr1;
	return str;


}

int main()
{
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	#endif

    char str[100] = "Today is a rainy day!";
    char delim[] = " ";

    std::cout << str<<std::endl;

    char * ptr = strtok(str, delim);
    while(ptr != NULL)
    {
    	std::cout << ptr<<std::endl;
    	ptr = strtok(NULL, delim);
    }

    std::cout << str;

    return 0;
}