#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9+9;

int dp[2][151][151][151]; //i dong, x xu1, y xu2, z xu3
int n, nmax;

int retdp(int x, int y, int z)
{
	if(x<0||y<0||z<0)
	{
		return 0;
	}
	return dp[0][x][y][z];
}

void reprep(bool sad)
{
	int ans=0;
	for(int x=0; x<=nmax; x++)
	{
		for(int y=0; y<=nmax; y++)
		{
			for(int z=0; z<=nmax; z++)
			{
				if(sad)
				{
					ans+=dp[0][x][y][z];
					ans%=mod;
				}
				else
				{
					dp[0][x][y][z]=dp[1][x][y][z];
					dp[1][x][y][z]=0;
				}
			}
		}
	}
	if(sad)
	{
		cout<<ans%mod;
	}
	return;
}

void subtask1()
{
	for(int i=1; i<=n; i++)
	{
		for(int x=0; x<=nmax; x++)
		{
			for(int y=0; y<=nmax; y++)
			{
				for(int z=0; z<=nmax; z++)
				{
					dp[1][x][y][z]+=retdp(x-1, y, z);
					dp[1][x][y][z]+=retdp(x+1, y-1, z);
					dp[1][x][y][z]+=retdp(x+1, y+1, z-1);
					if(y==0)
					{
						dp[1][x][y][z]+=retdp(x+3, y, z-1);
					}
					dp[1][x][y][z]%=mod;
				}
			}
		}
		reprep(false);
	}
	reprep(true);
}

signed main()
{
	freopen("ICECREAM.INP", "r", stdin);
	freopen("ICECREAM.OUT", "w", stdout);
	{
		cin>>n>>nmax;
		int x, y, z;
		cin>>x>>y>>z;
		dp[0][x][y][z]=1;
		if(nmax*nmax*nmax*n<100000000)
		{
			subtask1();
		}
	}
}
