#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
const lli N=109, K=209;
lli m, n, k, dp[N][N][K], trace[N][N][K], a[N], b[N];

void Inp()
{
	cin>>m>>n>>k;
	for(int i=m;i>=1;i--)
	{
		cin>>a[i];
	}
	for(int i=n;i>=1;i--)
	{
		cin>>b[i];
	}
}
void Sub1()
{
	fill_n(&dp[0][0][0], sizeof(dp)/sizeof(dp[0][0][0]), -1);
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			dp[i][j][0]=0;
		}
	}
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			for(int x=1;x<=k;x++)
			{
				if(i&&dp[i-1][j][x]!=-1)
				{
					dp[i][j][x]=dp[i-1][j][x];
					trace[i][j][x]=3;
				}
				if(j&&dp[i][j-1][x]!=-1&&(dp[i][j-1][x]<dp[i][j][x]||dp[i][j][x]<0))
				{
					dp[i][j][x]=dp[i][j-1][x];
					trace[i][j][x]=4;
				}
				if(i&&dp[i-1][j][x-1]!=-1&&(a[i]<=dp[i][j][x]|dp[i][j][x]<0))
				{
					dp[i][j][x]=a[i];
					trace[i][j][x]=1;
				}
				if(j&&dp[i][j-1][x-1]!=-1&&(b[j]<dp[i][j][x]||dp[i][j][x]<0))
				{
					dp[i][j][x]=b[j];
					trace[i][j][x]=2;
				}
			}
		}
	}
}
void Trace1()
{
	lli x=m, y=n, z=k;
	while(z>0)
	{
		if(trace[x][y][z]==3)
		{
			x--;
			continue;
		}
		if(trace[x][y][z]==4)
		{
			y--;
			continue;
		}
		if(trace[x][y][z]==2)
		{
			cout<<dp[x][y][z]<<" ";
			y--;
			z--;
			continue;
		}
		if(trace[x][y][z]==1)
		{
			cout<<dp[x][y][z]<<" ";
			x--;
			z--;
			continue;
		}
	}
}
int main()
{
	freopen("SEQUENCE.INP","r",stdin);
	freopen("SEQUENCE.OUT","w",stdout);
	Inp();
	if(m<=100&&n<=100)
	{
		Sub1();
		Trace1();
	}
}
