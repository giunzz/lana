#include<bits/stdc++.h>
using namespace std;
const int N=5e4+6;
int p[N],par[N],n,k,trace[N],ans=2e9,res;
bool vis[15];
map<int,int> val[N];
map<int,bool> edge[N];
vector<int> a[N];
void dfs(int u, int pre){
	for(int i=0;i<(int)a[u].size();++i){
		int v=a[u][i];
		if (v==pre) continue;
		trace[v]=u;
		dfs(v,u);
	}
}
void check(){
	res=0;
	for(int i=1;i<=k;++i) vis[i]=false;
	for(int i=1;i<=n;++i)
		for(int j=0;j<(int)a[i].size();++j)
			edge[a[i][j]][i]=edge[i][a[i][j]]=false;
	for(int i=1;i<=k;++i){
		if (!vis[i] && !vis[par[i]]){
			dfs(p[i],0);
			vis[i]=vis[par[i]]=true;
			int x=p[par[i]];
			int tmp=0;
			while(x!=p[i]){
				if (edge[x][trace[x]] || edge[trace[x]][x]){
					return; 
				}
				edge[x][trace[x]]=edge[trace[x]][x]=true;
				tmp+=val[x][trace[x]];
				x=trace[x];
			}
			res=max(res,tmp);
		}
	}
}
void scan(int i){
	if (i==k+1){
		for(int j=1;j<=k;++j)
			if (j!=par[par[j]]) return;
		check();
		if (res!=0) ans=min(ans,res);
		return;
	}
	if (par[i]!=-1) scan(i+1);
	for(int j=1;j<=k;++j){
		if (par[j]==-1 && i!=j){
			par[i]=j;
			par[j]=i;
			scan(i+1);
			par[i]=-1;
			par[j]=-1;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("bubbletea.inp","r",stdin);
	freopen("bubbletea.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i) par[i]=-1;
	for(int i=1;i<=k;++i) cin>>p[i];
	for(int i=1;i<n;++i){
		int u,v,w;
		cin>>u>>v>>w;
		a[u].push_back(v);
		a[v].push_back(u);
		val[u][v]=val[v][u]=w;
	}
	scan(1);
	cout<<ans;
}
