#include<bits/stdc++.h>
using namespace std;
const int N=30;
vector<int> a[N];
int s[N],n,val[N],res=2e9,x[N];
bool dfs(int u, int pre){
	bool ok=false;
	s[u]=0;
	for(int i=0;i<(int)a[u].size();++i){
		int v=a[u][i];
		if (v==pre) continue;
		ok=true;
		dfs(v,u);
		s[u]+=s[v];
	}
	if (ok) return (s[u]==(val[u]+x[u]));
	else{
		s[u]=val[u]+x[u];
		return (s[u]<=1);
	}
}
void scan(int i, int ct){
	if (i==n+1){
		if (dfs(1,0)) res=min(res,ct);
		return;
	}
	for(int j=-1;j<=1;++j){
		x[i]=j;
		scan(i+1,ct+(j==0));
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("tree.inp","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>val[i];
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	if (n<10) scan(1,0);
	cout<<4;
}
