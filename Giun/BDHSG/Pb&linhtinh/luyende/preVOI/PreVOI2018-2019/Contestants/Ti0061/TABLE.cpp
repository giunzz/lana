#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
const lli N=309, N2=81;
lli m, n, k, a[N][N], dp[N2][N2][N2][N2];
void Inp()
{
	cin>>m>>n>>k;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
}
void Pre()
{
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			lli s=0;
			for(int x=i;x<=m;x++)
			{
				s+=a[x][j];
				dp[i][j][x][j]=s;
			}
			s=0;
			for(int y=j;y<=n;y++)
			{
				s+=a[i][y];
				dp[i][j][i][y]=s;
			}
			for(int x=i+1;x<=m;x++)
			{
				for(int y=j+1;y<=n;y++)
				{
					dp[i][j][x][y]=max(dp[i][j][x-1][y], dp[i][j][x][y-1])+a[x][y];
				}
			}
		}
	}
}
void Sub1()
{
	while(k--)
	{
		lli u, v, p, q, kq;
		cin>>u>>v>>p>>q;
		for(int i=u;i<=p;i++)
		{
			for(int j=v;j<=q;j++)
			{
				lli maxx=0;
				if((i==u&&j==v)||(i==p&&j==q))
				{
					continue;
				}
				if(j<n)
				{
					for(int x=u;x<i;x++)
					{
						maxx=max(maxx, dp[u][v][x][j+1]+dp[x][j+1][p][q]-a[x][j+1]);
					}
				}
				if(i<m)
				{
					for(int y=v;y<j;y++)
					{
						maxx=max(maxx, dp[u][v][i+1][y]+dp[i+1][y][p][q]-a[i+1][y]);
					}
				}
				kq=min(kq, maxx);
			}
		}
		cout<<kq<<endl;
	}
}
int main()
{
	freopen("TABLE.INP","r",stdin);
	freopen("TABLE.OUT","w",stdout);
	Inp();
	if(m<=80&&n<=80)
	{
		Pre();
		Sub1();
		return 0;
	}
}
