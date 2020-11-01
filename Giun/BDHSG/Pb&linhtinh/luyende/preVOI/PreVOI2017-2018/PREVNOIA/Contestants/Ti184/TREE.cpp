#include<bits/stdc++.h>
const int N = 5005;
const int inf = 1e9;
using namespace std;

ifstream fi ("TREE.inp");
ofstream fo ("TREE.out");

vector <int> adj[N];

int n, a[N], dp[N][N], num[N], ans = inf;

void dfs(int u, int p){
    adj[u].erase(remove(adj[u].begin(), adj[u].end(), p), adj[u].end());
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        dfs(v, u), num[u] += num[v];
    }
    if (adj[u].size() == 0) {
        num[u] = 1;
        dp[u][0] = a[u];
        dp[u][1] = abs(a[u] - 1);
    }
    else if (adj[u].size() == 1){
        for (int i = 0; i <= num[adj[u][0]]; i++) dp[u][i] = dp[adj[u][0]][i] + abs(a[u] - i);
    }
    if (adj[u].size() == 2){
        int x = adj[u][0], y = adj[u][1];
        for (int i = 0; i <= num[x]; i++) for (int j = 0; j <= num[y]; j++)
            dp[u][i+j] = min(dp[u][i+j], dp[x][i] + dp[y][j]);
        for (int i = 0; i <= num[u]; i++) dp[u][i] += abs(a[u] - i);
    }
}

int main(){
    fi >> n;
    for (int i = 1; i <= n; i++) fi >> a[i];
    for (int i = 1; i <  n; i++){
        int u, v; fi >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) dp[i][j] = inf;
    dfs(1, 1);
    for (int i = 0; i < N; i++) ans = min(ans, dp[1][i]);
    fo << ans;
}
/*
5
5 1 3 0 1
1 2
1 3
3 4
3 5
*/
