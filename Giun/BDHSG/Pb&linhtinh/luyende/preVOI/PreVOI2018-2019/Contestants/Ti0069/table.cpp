#include <bits/stdc++.h>
using namespace std;

const long long oo=1e18;
int n,m,k;
long long a[300][300],dp[50][50],dis[101][101][101][101];

void sub1()
{
	for(int g=1;g<=k;g++)
	{
		int u,v,p,q;
		cin>>u>>v>>p>>q;
		long long res=oo;
		for(int x=u;x<=p;x++)
			for(int y=v;y<=q;y++)
			{
				if((x==u && y==v) || (x==p && y==q)) continue;
				memset(dp,0,sizeof(dp));
				for(int i=u;i<=p;i++)
					for(int j=v;j<=q;j++)
					{
						if(i==x && j==y) 
						{
							dp[i][j]=0;
							continue;
						}
						dp[i][j]=max(dp[i-1][j],dp[i][j-1])+a[i][j];
					}
				res=min(res,dp[p][q]);
			}
		cout<<res<<'\n';
	}
}

bool inside(int x,int y,int u,int v,int p,int q)
{
	return (u<=x && x<=p && v<=y && y<=q);
}

void sub2()
{
	for(int u=1;u<=n;u++)
		for(int v=1;v<=m;v++)
			for(int i=u;i<=n;i++)
				for(int j=v;j<=m;j++) dis[u][v][i][j]=max(dis[u][v][i-1][j],dis[u][v][i][j-1])+a[i][j];
	for(int g=1;g<=k;g++)
	{
		int u,v,p,q;
		cin>>u>>v>>p>>q;
		long long res=oo;
		for(int x=u;x<=p;x++)
			for(int y=v;y<=q;y++)
			{
				if((x==u && y==v) || (x==p && y==q)) continue;
				if(dis[u][v][x][y]+dis[x][y][p][q]-a[x][y]!=dis[u][v][p][q]) continue;
				long long tmp=0;
				if(inside(x-1,y+1,u,v,p,q)) tmp=max(tmp,dis[u][v][x-1][y+1]+dis[x-1][y+1][p][q]-a[x-1][y+1]);
				if(inside(x+1,y-1,u,v,p,q)) tmp=max(tmp,dis[u][v][x+1][y-1]+dis[x+1][y-1][p][q]-a[x+1][y-1]);
				res=min(res,tmp);
			}	
		cout<<res<<'\n';
	}
}

int main()
{
	freopen("table.inp","r",stdin);
	freopen("table.out","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) cin>>a[i][j];			
	if(n<=30 && m<=30 && k<=30) sub1(); else sub2();
}