#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 305;
LL n,m,x,y,u,v,a[N][N], dp[N][N], g[N][N], Trace[N][N], res, _u, _v, cnt, tmp;
struct node {
    LL u,v;
} q[N*N*2];

void process() {
    cin >> x >> y >> u >> v;
    if( x == u || y == v ) {
        cout << 0 << '\n'; return;
    }
    for(int i = x - 1; i <= u + 1; ++ i) {
        for(int j = y - 1; j <= v + 1; ++ j) dp[i][j] = 0, Trace[i][j] = 0, g[i][j] = 0;
    }
    dp[x][y] = a[x][y];
    for(int i = x; i <= u; ++ i) {
        for(int j = y; j <= v; ++ j) {
            if( i == x && j == y ) continue;
            if( dp[i-1][j] > dp[i][j-1] ) dp[i][j] = dp[i-1][j], Trace[i][j] = 1;
            else dp[i][j] = dp[i][j-1], Trace[i][j] = 2;
            dp[i][j] += a[i][j];
        }
    }
    g[u][v] = a[u][v];
    for(int i = u; i >= x; -- i) {
        for(int j = v; j >= y; -- j) {
            if( i == u && j == v ) continue;
            g[i][j] = max( g[i+1][j], g[i][j+1] ) + a[i][j];
        }
    }
    res = 1e18;
    _u = u, _v = v;
    cnt = 0;
    while( Trace[_u][_v] != 0 ) {
        if( Trace[_u][_v] == 1 ) _u = _u - 1;
        else _v = _v - 1;
        q[++ cnt] = { _u,_v };
    }
    -- cnt;
    for(int i = 1; i <= cnt; ++ i) {
        _u = q[i].u, _v = q[i].v;
        tmp = 0;
        if( _u - 1 >= x ) {
            for(int k = _v + 1; k <= v; ++ k) {
                tmp = max( tmp, dp[_u - 1][k] + g[_u - 1][k] - a[_u - 1][k] );
            }
        }
        if( _u + 1 <= u ) {
            for(int k = _v - 1; k >= y; -- k) {
                tmp = max( res, dp[_u + 1][k] + g[_u + 1][k] - a[_u + 1][k] );
            }
        }
        res = min( res, tmp );
    }
    cout << res << '\n';
}

int main() {
    freopen("TABLE.inp","r",stdin);
    freopen("TABLE.out","w",stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++ i) {
        for(int j = 1; j <= m; ++ j) {
            cin >> a[i][j];
        }
    }

    for(int i = 1; i <= k; ++ i) {
        process();
    }

    return 0;
}
