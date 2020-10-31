#include<bits/stdc++.h>

using namespace std;

const int maxn = 5010;
const int oo = 1e9;

int n;
int a[maxn], f[maxn][maxn];
bool visited[maxn];
vector<int> adj[maxn];


void dfs_1(int x){
    visited[x] = true;
    vector<int> c;
    for (int i = 0; i < adj[x].size(); i++)
        if (!visited[adj[x][i]]){
            c.push_back(adj[x][i]);
            dfs_1(adj[x][i]);
        }
    if (c.size() == 0){
        f[x][0] = a[x];
        f[x][1] = abs(a[x] - 1);
    } else if (c.size() == 1){
        int v = c[0];
        for (int i = 0; i <= n; i++) f[x][i] = min(f[x][i], f[v][i] + abs(a[x] - i));
    } else {
        int v1 = c[0], v2 = c[1];
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= i; j++)
                f[x][i] = min(f[x][i], f[v1][j] + f[v2][i - j] + abs(a[x] - i));
    }
}

void dfs_2(int x){
    visited[x] = true;
    vector<int> c;
    for (int i = 0; i < adj[x].size(); i++)
        if (!visited[adj[x][i]]){
            c.push_back(adj[x][i]);
            dfs_2(adj[x][i]);
        }
    if (c.size() == 0){
        f[x][0] = a[x];
        f[x][1] = abs(a[x] - 1);
    } else if (c.size() == 1){
        int v = c[0];
        for (int i = 0; i <= n; i++) f[x][i] = min(f[x][i], f[v][i] + abs(a[x] - i));
    } else {
        int v1 = c[0], v2 = c[1];
        int l = 0, r = 0;
        f[x][0] = f[v1][0] + f[v2][0] + a[x];
        for (int i = 1; i <= n; i++){
            if (f[v1][l] + f[v2][r + 1] < f[v1][l + 1] + f[v2][r]) r++; else l++;
            f[x][i] = min(f[x][i], f[v1][l] + f[v2][r] + abs(a[x] - i));
        }
    }
}

int main(){
    freopen("tree.inp", "r", stdin);
    freopen("tree.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i < n; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= n; j++)
            f[i][j] = oo;
    int ans;

    if (n <= 300) dfs_1(1); else dfs_2(1);
    ans = oo;
    for (int i = 0; i <= n; i++) ans = min(ans, f[1][i]);
    printf("%d", ans);

    return 0;
}
