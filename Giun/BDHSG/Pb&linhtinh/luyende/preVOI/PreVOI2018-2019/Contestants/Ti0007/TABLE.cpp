#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
#define f first
#define s second
#define mk make_pair

const int N = 3e2 + 7;
const ll Inf = 1e18 + 7;
int n, m, t, T, k, tt;
int a[N][N], check[N][N];
ll xuoi[N][N], ngc[N][N], res;

void dfs(int u, int v, int x, int y) {
    check[u][v] = tt;
    ll ans = 0;
    if(u + 1 <= x)
        if(check[u + 1][v] != tt) dfs(u + 1, v, x, y), ans = max(xuoi[u + 1][v], ans);
        else ans = max(xuoi[u + 1][v], ans);
    if(v + 1 <= y)
        if(check[u][v + 1] != tt) dfs(u, v + 1, x, y), ans = max(xuoi[u][v + 1], ans);
        else ans = max(xuoi[u][v + 1], ans);
    xuoi[u][v] = ans + a[u][v];
//    cout << u << "  " << v << "  " << xuoi[u][v] << "\n";
}
void dfs_ngc(int u, int v, int x, int y) {
    check[u][v] = tt;
    ll ans = 0;
    if(u - 1 >= x)
        if(check[u - 1][v] != tt) dfs_ngc(u - 1, v, x, y), ans = max(ngc[u - 1][v], ans);
        else ans = max(ngc[u - 1][v], ans);
    if(v - 1 >= y)
        if(check[u][v - 1] != tt) dfs_ngc(u, v - 1, x, y), ans = max(ngc[u][v - 1], ans);
        else ans = max(ngc[u][v - 1], ans);
    ngc[u][v] = ans + a[u][v];
//    cout << u << "  " << v << "  " << ngc[u][v] << "  " << xuoi[u][v] << "  " << a[u][v] << "  ngc\n";
}
void sol(int u, int v, int x, int y) {

    ll ans;
    res = Inf;
    for(int i = u; i <= x; ++ i)
    for(int j = v; j <= y; ++ j) {
        if((i == u && j == v) || (i == x && j == y)) continue;
        ans = 0;
        if(i > u && j < y) ans = max(ans, xuoi[i-1][j+1] + ngc[i-1][j+1] - a[i-1][j+1]);
        if(i < x && j > v) ans = max(ans, xuoi[i+1][j-1] + ngc[i+1][j-1] - a[i+1][j-1]);
        res = min(res, ans);
    }
//    res = min(res, ngc[x][y] - max(a[u][v], a[x][y]));
}

int main() {
//#define file "r"
#define file "TABLE"
    freopen(file".inp", "r", stdin);
    freopen(file".out", "w", stdout);

    cin >> n >> m >> T;
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= m; ++ j)
            cin >> a[i][j];

//    cout << n << "  " << m << "\n";
//    for(int i = 1; i <= n; ++ i)
//    {for(int j = 1; j <= m; ++ j) cout << a[i][j] << "  "; cout << "\n"; }
    while(T --) {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        ++ tt; dfs(u, v, x, y);
        ++ tt; dfs_ngc(x, y, u, v);
        sol(u, v, x, y);
        cout << res << "\n";
//        cout << xuoi[u][v] << "  " << ngc[x][y] << "\n";
//        cout << u << "  " << v << "  " << x << "  " << y << "\n";
    }

    return 0;
}
