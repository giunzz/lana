#include <bits/stdc++.h>
using namespace std;
int n, sz[5005], dp[5005][5005], c[5005];
vector <int> G[5005];
int tmp[5005];
void dfs(int u,int p){
	if (u != 1 && G[u].size() == 1){
		dp[u][0] = c[u];
		dp[u][1] = abs(c[u]-1);
		sz[u] = 1;
		return;
	}
	
	for(int i=0;i<(int)G[u].size();i++){
		int v = G[u][i];
		if (v == p) continue;
		dfs(v,u);
		
		for(int j=0;j<=sz[u]+sz[v];j++)	tmp[j] = (int) 1e9;
		for(int j=0;j<=sz[u];j++)
			for(int k=0;k<=sz[v];k++)
				tmp[j+k] = min(tmp[j+k], dp[u][j] + dp[v][k]);
		sz[u] += sz[v];
		for(int j=0;j<=sz[u];j++)
			dp[u][j] = tmp[j];
	}
	
	for(int j=0;j<=sz[u];j++)
		dp[u][j] += abs(j - c[u]);
}
int main(){
	freopen("tree.inp","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	if (n == 1){
		printf("%d", min(c[1], abs(c[1] - 1)));
		return 0;
	}
	dfs(1,1);
	int ans = (int) 1e9;
	for(int i=0;i<=sz[1];i++) ans = min(ans, dp[1][i]);
	printf("%d",ans);
}
