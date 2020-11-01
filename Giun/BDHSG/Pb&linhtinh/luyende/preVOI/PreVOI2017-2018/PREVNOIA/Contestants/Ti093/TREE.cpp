#include <bits/stdc++.h>
using namespace std;
int Read_Int(){
    char c;
    for(c = getchar(); c < '0' || c > '9'; c = getchar());
    int ans = c - '0';
    for(c = getchar(); c >= '0' && c <= '9'; c = getchar())
        ans = ans * 10 + c - '0';
    return ans;
}
void Write_Int(int x){
    if(x > 9) Write_Int(x / 10);
    putchar(x % 10 + '0');
}
const int INF = int(1e9) + 1;
const int maxN = 5005;
int n, a[maxN], deg[maxN];
vector <int> g[maxN];
int Input(){
    n = Read_Int();
    for(int i = 1 ; i <= n ; ++ i) a[i] = Read_Int();
    for(int i = 1 ; i <= n - 1 ; ++ i){
        int u = Read_Int(), v = Read_Int();
        g[u].push_back(v), ++ deg[u];
    }
    return 0;
}

int cl[maxN], tp[maxN], sltp;
int DFS(int u){
    cl[u] = 1;
    for(int i = 0 ; i < deg[u] ; ++ i){
        int v = g[u][i];
        if(cl[v] == 0){
            DFS(v);
        }
    }
    tp[++ sltp] = u;
    return 0;
}

int UseDFS(int xp){
    sltp = 0;
    for(int i = 1 ; i <= n ; ++ i) cl[i] = 0;
    DFS(1);
    reverse(tp + 1, tp + sltp + 1);
    return 0;
}
int W[maxN], ds;
int Solve(){
    UseDFS(1);
    for(int i = 1 ; i <= n ; ++ i) W[i] = a[i];
    for(int i = n ; i > 0 ; -- i){
        int u = tp[i];
        if(deg[u] == 0) W[u] = 1;
    }
    for(int i = n ; i > 0 ; -- i){
        int u = tp[i];
        if(deg[u] == 2){
            int Left = g[u][0], Right = g[u][1],
                t = W[Left] + W[Right];
            W[u] = t;
        }
    }
    ds = 0;
    for(int i = 1 ; i <= n ; ++ i) ds += abs(W[i] - a[i]);
    Write_Int(ds);
    return 0;
}

int B[maxN], x[maxN], m;
int Process(){
    memset(W, 0 ,sizeof(W));
    for(int i = 1 ; i <= m ;++ i) W[B[i]] = x[i];
    for(int i = n ; i > 0 ; -- i){
        int u = tp[i];
        if(deg[u] == 2){
            int Left = g[u][0], Right = g[u][1],
                t = W[Left] + W[Right];
            W[u] = t;
        }
    }
    int T = 0;
    for(int i = 1 ; i <= n ; ++ i) T += abs(W[i] - a[i]);
    ds = min(T, ds);
    return 0;
}

int Try(int i){
    if(i > m){Process(); return 0;}
    for(int j = 0 ; j <= 1 ; ++ j){
        x[i] = j;
        Try(i + 1);
    }
    return 0;
}

int Solve_Brute(){
    UseDFS(1);
    m = 0;
    for(int i = n ; i > 0 ; -- i){
        int u = tp[i];
        if(deg[u] == 0) B[++ m] = u;
    }
    ds = INF;
    Try(1);
    Write_Int(ds);
    return 0;
}

#define TASK "TREE"
int main(){
    #ifdef TASK
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    #else
    freopen("main.inp","r",stdin);
    #endif // TASK
    Input();
    if(n <= 30) Solve_Brute();
    else Solve();
}
