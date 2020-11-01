#include <bits/stdc++.h>
using namespace std;

const int M=4e2+1;
const int base=1e9+9;
int n,mx,m50,m1,m2,dp[2][M][M][M];

int main()
{
	freopen("icecream.inp","r",stdin);
	freopen("icecream.out","w",stdout);
	cin>>n>>mx;
	cin>>m50>>m1>>m2;
	int flag=0;
	dp[flag][m50][m1][m2]=1;
	for(int i=0;i<n;i++)
	{
		for(int x=0;x<=mx;x++)
			for(int y=0;y<=mx;y++)
				for(int z=0;z<=mx;z++)
					if(dp[flag][x][y][z])
					{
						if(x+1<=mx) dp[1-flag][x+1][y][z]=(dp[1-flag][x+1][y][z]+dp[flag][x][y][z])%base;
						if(y+1<=mx && x>0) dp[1-flag][x-1][y+1][z]=(dp[1-flag][x-1][y+1][z]+dp[flag][x][y][z])%base;
						if(z+1<=mx)
						{
							if(x>=3) dp[1-flag][x-3][y][z+1]=(dp[1-flag][x-3][y][z+1]+dp[flag][x][y][z])%base; else
							if(x>0 && y>0) dp[1-flag][x-1][y-1][z+1]=(dp[1-flag][x-1][y-1][z+1]+dp[flag][x][y][z])%base;
						}
						dp[flag][x][y][z]=0;
					}
		flag=1-flag;
	}
	int ans=0;
	for(int x=0;x<=mx;x++)
		for(int y=0;y<=mx;y++)
			for(int z=0;z<=mx;z++) ans=(ans+dp[flag][x][y][z])%base;
	cout<<ans;
}