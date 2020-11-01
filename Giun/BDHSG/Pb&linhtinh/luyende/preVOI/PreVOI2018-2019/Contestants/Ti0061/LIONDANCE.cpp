#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
const lli N=4009;
lli n, k, a[N], b[N], last[N][N], trace[N][N], dp[N][N], last1[N][N];

void Inp()
{
	cin>>n>>k;
	for(int i=n;i>=1;i--)
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
	for(int i=1;i<=n;i++)
	{
		if(a[i]==b[1])
		{
			dp[i][1]=1;
			trace[i][1]=3;
			last[i][1]=a[i];
		}
		else
		{
			trace[i][1]=1;
		}
		if(b[i]==a[1])
		{
			dp[1][i]=1;
			trace[1][i]=3;
			last[1][i]=b[i];
		}
		else
		{
			trace[1][i]=2;
		}
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=2;j<=n;j++)
		{
			dp[i][j]=dp[i-1][j];
			trace[i][j]=1;
			last[i][j]=last[i-1][j];
			last1[i][j]=last1[i-1][j];
			if(dp[i][j]<dp[i][j-1]||(dp[i][j]==dp[i][j-1]&&last[i][j]<last[i][j-1]))
			{
				dp[i][j]=dp[i][j-1];
				trace[i][j]=2;
				last[i][j]=last[i][j-1];
				last1[i][j]=last1[i][j-1];
			}
			if(a[i]==b[j])
			{
				trace[i][j]=3;
				last[i][j]=a[i];
				for(int x=i-1;x>=1;x--)
				{
					for(int y=j-1;y>=1;y--)
					{
						if(a[x]==b[y]&&trace[x][y]==3&&abs(a[x]-a[i])<=k)
						{
							if(dp[i][j]<dp[x][y]+1||(dp[i][j]==dp[x][y]+1&&a[x]>last1[i][j]))
							{
								dp[i][j]=dp[x][y]+1;
								last1[i][j]=a[x];
							}
						}
					}
				}
				if(dp[i][j]==0||(dp[i][j]==1&&last[i][j]<a[i]))
				{
					dp[i][j]=1;
					trace[i][j]=3;
					last[i][j]=a[i];
				}
			}
		}
	}
}
void Trace1()
{
	lli x=n, y=n;
	cout<<dp[n][n]<<endl;
	while(x&&y)
	{
		if(trace[x][y]==3)
		{
			cout<<a[x]<<" ";
			x--;
			y--;
			continue;
		}
		if(trace[x][y]==1)
		{
			x--;
			continue;
		}
		if(trace[x][y]==2)
		{
			y--;
			continue;
		}
	}
}
int main()
{
	freopen("LIONDANCE.INP","r",stdin);
	freopen("LIONDANCE.OUT","w",stdout);
	Inp();
	if(n<=100)
	{
		Sub1();
		Trace1();
	}
}
