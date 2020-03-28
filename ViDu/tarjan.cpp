#include <bits/stdc++.h>
#define vec(type) vector<type>
#define pp(type) pair<type, type>
using namespace std;

vec(vec(int)) g;
int n, m, num[107], low[107] = {INT_MAX};
bool d[107] = {0};

void enter(){
    int u, v;
    cin >> n >> m;
    g.resize(n + 1);
    for(int i = 1; i <= m; i++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

void dfs(int u){
    int v;
    for (int i = 1; i <= g[u].size(); i++){
        v = g[u][i];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.inp", "r", stdin);
    freopen("output.txt", "w", stdout);
    enter();
    dfs(1);
}