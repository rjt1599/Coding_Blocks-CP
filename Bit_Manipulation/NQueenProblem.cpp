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

int ans = 0, DONE;
int n;
int board[100][100] {0};

int getcolumn(int p)
{
	int j = 0;
	while(p)
	{
		p = p >> 1;
		j++;
	}
	return --j;
}

void solve (int rowmask, int ld, int rd, int row)
{
	if(rowmask == DONE)
		{
			ans++; 
			std::cout << ans << std::endl;
			for(int i = 0; i < n; i++)
			{
				for(int j = 0; j < n; j++)
				{
					std::cout << board[i][j] << " ";
				}
				std::cout << std::endl;
			}
			std::cout << std::endl;

			return;
		}

	int safe = DONE & ~(rowmask | ld | rd);

	int p;
	while(safe)
	{
		p = safe & (-safe);
		safe = safe - p;
        int col = getcolumn(p);
		board[row][col] = 1;
		solve(rowmask | p, (ld|p) << 1, (rd|p) >> 1, row + 1);
		board[row][col] = 0;
	}

}

int main()
{
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	#endif

    
    std::cin >> n;


    DONE = (1 << n) - 1;
    solve(0, 0, 0, 0);

    
    return 0;
}