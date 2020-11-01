#include <bits/stdc++.h>
using namespace std;
ifstream fin("tree.inp");
ofstream fo("tree.out");
#define cin fin
#define cout fo
#define mp make_pair
#define pb push_back
#define fi first
#define se second
int n;
const int N=5007;
int a[N],u,v,ans=0,dp[5007][5007],sz[5007],par[5007],vis[5007];
vector <int> edge[5007];
queue <int> q;
void dfs(int u){
	for(int i=0;i<(int)edge[u].size();i++){
		int v=edge[u][i];
		if(par[u]==v) continue;
		par[v]=u;
		dfs(v);
		sz[u]+=sz[v]+1;
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=5003;j++){
			dp[i][j]=1e9;
		}
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		cin>>u>>v;
		edge[u].pb(v);
		edge[v].pb(u);
	}
	dfs(1);
	for(int i=1;i<=n;i++){
		if(sz[i]==0){
			q.push(i);
		}
	}
	while(!q.empty()){
		u=q.front();
		q.pop();
		if(vis[u]==1) continue;
		if(u==0) break;
		int ok=1;
		for(int i=0;i<(int)edge[u].size();i++){
			int v=edge[u][i];
			if(par[u]==v) continue;
			if(vis[v]==0){
				ok=0;
				break;
			}
		}
		if(ok==0){
			q.push(u);
			continue;
		}
		vis[u]=1;
		if(sz[u]==0){
			dp[u][0]=a[u];
			dp[u][1]=abs(a[u]-1);
			q.push(par[u]);
			continue;
		}
		int cnt=0,child1=0,child2=0;
		for(int i=0;i<(int)edge[u].size();i++){
			int v=edge[u][i];
			if(par[u]==v) continue;
			cnt++;
			if(cnt==1) child1=v;
			else child2=v;
		}
		if(cnt==1){
			for(int i=0;i<=sz[u];i++) dp[u][i]=dp[child1][i]+abs(a[u]-i);
		}
		else{
			int l=0,r=0;
			for(int i=0;i<=sz[u];i++){
				if(n<=300){
					if(sz[child1]==0 || sz[child2]==0){
						dp[u][i]=min(dp[u][i],dp[child1][0]+dp[child2][i]+abs(a[u]-i));
						if(i>=1) dp[u][i]=min(dp[u][i],dp[child1][1]+dp[child2][i-1]+abs(a[u]-i));
					}
					else{
						for(int j=0;j<=min(i,sz[child1]);j++){
							dp[u][i]=min(dp[u][i],dp[child1][j]+dp[child2][i-j]+abs(a[u]-i));
						}
					}
					continue;
				}
				if(i>0){
					int val1=dp[child1][l+1]-dp[child1][l],val2=dp[child2][r+1]-dp[child2][r];
					if(val1<=val2){
						l++;
					}
					else r++;
				}
				dp[u][i]=dp[child1][l]+dp[child2][r]+abs(a[u]-i);
			}
		}
		q.push(par[u]);
	}
	int ans=1e9;
	for(int i=0;i<=sz[1];i++) ans=min(ans,dp[1][i]);
	cout<<ans;
}
