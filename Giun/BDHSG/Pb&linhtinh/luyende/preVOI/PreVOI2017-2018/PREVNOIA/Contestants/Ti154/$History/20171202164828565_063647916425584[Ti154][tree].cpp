#include<bits/stdc++.h>
using namespace std;
const int N=5e3+3;
int res,n,a[N],b[N],la[N];
vector <int > ds[N];

void read()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("tree.inp","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;++i) cin>>a[i];
	for (int i=1;i<n;++i)
	{
		int u,v;
		cin>>u>>v;
		ds[u].push_back(v);
	}
}

int dfs(int u)
{
	if (b[u]!=-1) return b[u];
	int tmp=0;
	for (int i=0;i<ds[u].size();++i)
		tmp+=dfs(ds[u][i]);
	b[u]=tmp;
	return tmp;
}

int dfs2(int u)
{
	//cerr<<u<<'\n';
	if (ds[u].size()==0) return 1;
	int tmp=0;
	for (int i=0;i<ds[u].size();++i)
		tmp+=dfs2(ds[u][i]);
	return tmp;
}

void solve()
{
	int dem=0;
	for (int i=1;i<=n;++i) if (ds[i].size()==0) la[++dem]=i;

	res=1e9+7;
	for (int mask=0;mask<(1<<dem);++mask)
	{
		memset(b,-1,sizeof(b));
		for (int i=0;i<dem;++i)
			if (mask & (1<<i)) b[la[i+1]]=1;
				else b[la[i+1]]=0;
		for (int i=1;i<=n;++i) b[i]=dfs(i);
		int tmp=0;
		for (int i=1;i<=n;++i) tmp+=abs(a[i]-b[i]);
		res=min(res,tmp);
	}
	cout<<res;
}

void solve2()
{
	for (int i=1;i<=n;++i)
		b[i]=dfs2(i);
	for (int i=1;i<=n;++i) res+=abs(a[i]-b[i]);
	cout<<res;
}

int main()
{
	read();
	if (n<=30) solve();
		else solve2();
}