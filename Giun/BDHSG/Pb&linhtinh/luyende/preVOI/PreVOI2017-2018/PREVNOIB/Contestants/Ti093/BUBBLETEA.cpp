#include <bits/stdc++.h>

using namespace std;
const int maxN = int(5e4 + 5);
int n, k, a[maxN], deg[maxN];
typedef pair<int , int> II;
vector <II> g[maxN];
int Input(){
    scanf("%d %d",&n , &k);
    for(int i = 1 ; i <= k ; ++ i) {
        scanf("%d", &a[i]);
    }
    for(int i = 1 ; i <= n - 1 ; ++ i){
        int u, v, L;
        scanf("%d %d %d", &u, &v, &L);
        g[u].push_back(II(v,L)), ++ deg[u];
        g[v].push_back(II(u,L)), ++ deg[v];
    }
    return 0;
}
int cl[maxN],pd[maxN],depth[maxN];
int64_t kc[maxN];
int DFS(int u){
    cl[u] = 1;
    for(int i = 0 ; i < deg[u] ; ++i){
        int v = g[u][i].first, L = g[u][i].second;
        if(cl[v] == 0){
            pd[v] = u;
            kc[v] = kc[u] + L;
            depth[v] = depth[u] + 1;
            DFS(v);
        }
    }
    return 0;
}

int UseDFS(){
    for(int i = 1 ; i <= n ; ++ i) cl[i] = 0;
    DFS(1);
    return 0;
}

int F[maxN][24];
int PreLCA(){
    for(int i = 1 ; i <= n ; ++ i) F[i][0] = pd[i];
    int lg2 = log2(n) + 1;
    for(int k = 1 ; k <= lg2 ; ++ k)
        for(int i = 1 ; i <= n ; ++ i) F[i][k] = F[F[i][k - 1]][k - 1];
    return 0;
}

int LCA(int u,int v){
    while(depth[u] > depth[v]){
        int k = log2(depth[u] - depth[v]);
        u = F[u][k];
    }
    while(depth[v] > depth[u]){
        int k = log2(depth[v] - depth[u]);
        v = F[v][k];
    }
    if(u!=v){
        int k = log2(depth[u]) + 1;
        while(k>=0){
            if(F[u][k] != F[v][k]){
                u = F[u][k],v = F[v][k];
            }
            --k;
        }
        u = F[u][0],v = F[v][0];
    }
    return u;
}

int64_t Get(int u, int v){
    int w = LCA(u,v);
    return kc[u] + kc[v] - 2 * kc[w];
}

const int64_t INF = 10000000000000000LL;
vector <int> vect[maxN];
int x[maxN];
int64_t ds;
int Process(){
    for(int i = 1 ; i <= k ; ++ i) vect[x[i]].push_back(a[i]);
    int64_t kq = 0;
    for(int i = 1 ; i <= k / 2 ; ++ i) {
        kq = max(kq, Get(vect[i][0], vect[i][1]));
    }
    ds = min(ds, kq);
    return 0;
}

int Count[maxN];
int Try(int i){
    if(i > k) {Process(); return 0;}
    for(int j = 1 ; j <= k / 2 ; ++ j){
        if(Count[j] < 2){
            x[i] = j;
            ++ Count[j];
            Try(i + 1);
            -- Count[j];
        }
    }
    return 0;
}

int Solve(){
    UseDFS();
    PreLCA();
    ds = INF;
    Try(1);
    printf("%I64d",ds);
    return 0;
}

#define TASK "BUBBLETEA"
int main(){
    #ifdef TASK
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    #else
    freopen("main.inp","r",stdin);
    #endif // TASK
    Input();
    Solve();
}
