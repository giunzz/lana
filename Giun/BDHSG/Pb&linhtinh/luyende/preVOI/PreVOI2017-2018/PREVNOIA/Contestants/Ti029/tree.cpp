#include<bits/stdc++.h>
#define task "tree"
#define ll long long
#define ff(i,a,b) for(int i=a; i<=b; ++i)
#define fd(i,a,b) for(int i=a; i>=b; --i)
#define rr(i,a,b) for(int i=a; i<b; ++i)
#define rd(i,a,b) for(int i=a; i>b; --i)
#define pb push_back
#define mp make_pair
using namespace std;

const int maxn=5E3+3;
const int inf=1E9+7;
int f[maxn][maxn];
int res, n, a[maxn];
vector<int> e[maxn];

void dfs(int x, int par)
{
	int childs=0, c1, c2;
	for(int i=0; i<e[x].size(); ++i)if(e[x][i]!=par)
	{
		childs++; if(childs==1)c1=e[x][i]; else if(childs==2)c2=e[x][i];
		dfs(e[x][i], x);
	}
	if(childs==1)
	{
		ff(i, 0, n)f[x][i] = min( f[x][i], abs(a[x]-i) + f[c1][i]);
	} else
	if(childs==2)
	{
		ff(i, 0, n)
			ff(j, 0, i)f[x][i] = min(f[x][i], abs(a[x]-i) + f[c1][j] + f[c2][i-j]);
	} else
	if(childs==0)
	{
		f[x][0] = a[x]-0;
		f[x][1] = abs(a[x]-1);
	}
}

int main()
{
	freopen(task".inp","r",stdin);
	freopen(task".out","w",stdout);
	scanf("%d",&n);
	ff(i, 1, n)scanf("%d",&a[i]);
	ff(i, 1, n-1)
	{
		int x, y;
		scanf("%d%d",&x,&y);
		e[x].pb(y);
		e[y].pb(x);
	}
	ff(i, 1, n)
		ff(j, 0, n)f[i][j]=inf;
	dfs(1, 0);
	res=inf;
	ff(i, 1, n)res = min(res, f[1][i]); //cout<<f[1][2]<<endl;
	cout<<res;
	return 0;
}
