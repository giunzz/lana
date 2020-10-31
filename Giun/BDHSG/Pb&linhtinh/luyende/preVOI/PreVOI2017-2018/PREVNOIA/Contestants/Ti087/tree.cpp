#include <bits/stdc++.h>
#define oo (INT_MAX/2)
using namespace std;

int f[5007][5007],val[5007],par[5007],l[5007],r[5007],ar[5007];

void dfs(int node)
{
	if(node==0) return ;
	dfs(l[node]);
	dfs(r[node]);
	if(l[node]==0) val[node]=1; else val[node]=val[l[node]]+val[r[node]];
	if(val[l[node]]>val[r[node]]) swap(l[node],r[node]); 
	return ;
}

void calu(int node)
{
	if(node==0) return ;
	calu(l[node]);
	calu(r[node]);
	if(l[node]==0)
	{
		f[node][1]=abs(ar[node]-1);
		f[node][0]=abs(ar[node]);
		return;
	}
	if(r[node]==0)
	{
		for(int i=0;i<=val[node];i++)
		{
			f[node][i]=min(f[node][i],f[l[node]][i]);
			f[node][i]+=abs(ar[node]-i);
		}
		return ;
	}
	for(int i=0;i<=val[node];i++)
	{
		for(int j=max(0,i-val[r[node]]);j<=min(i,val[l[node]]);j++)
		{
			f[node][i]=min(f[node][i],f[l[node]][j]+f[r[node]][i-j]);
		}
		f[node][i]+=abs(ar[node]-i);
	}
	return ;
}

int main()
{
	freopen("tree.inp","r",stdin);
	freopen("tree.out","w",stdout);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> ar[i];
	}
	for(int i=1;i<n;i++)
	{
		int a,b;
		cin >> a >> b;
		par[b]=a;
		if(l[a]==0) l[a]=b; else r[a]=b;
	}
	dfs(1);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=val[i];j++)
		{
			f[i][j]=oo;
		}
	}
	calu(1);
	int ans=oo;
	for(int i=0;i<=val[1];i++) ans=min(ans,f[1][i]);
		cout << ans << endl;
	return 0;
}