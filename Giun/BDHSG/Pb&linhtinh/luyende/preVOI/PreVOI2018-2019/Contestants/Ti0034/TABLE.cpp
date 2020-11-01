#include <bits/stdc++.h>

template <typename T> inline void read (T &x){
    bool b = 0; char c;
    while (!isdigit (c = getchar()) && c != '-');
    if (c == '-') c = getchar(), b = 1;
    x = c-48;
    while (isdigit(c = getchar())) x = x*10+c-48;
    if (b) x = -x;
}

using namespace std;
#define fname "TABLE"
#define For(i, a, b) for(int i = a; i <= b; i++)
#define FOr(i, a, b) for(int i = a; i < b; i++)
#define FOR(i, a, b) for(int i = a; i >= b; i--)
typedef int64_t ll;
const int N = 305;
const ll inf = 1e16;
int n, m, k, x, y, u, v;
ll res, a[N][N], f[N][N], g[N][N], bit[N][N], _bit[N][N];
void sub1(){
    res = inf;
    For (i, 0, n+1) For (j, 0, m+1) f[i][j] = g[i][j] = -inf;
    f[x][y] = a[x][y];
    For (i, x, u)
        For (j, y, v){
            if (i == x && j == y) continue;
            if (i == u && j == v) continue;
            ll cur = a[i][j];
            a[i][j] = -inf;
            For (p, x, u)
                For (q, y, v){
                    if (p == x && q == y) continue;
                    f[p][q] = max(f[p-1][q], f[p][q-1])+a[p][q];
                }
            res = min(res, f[u][v]);
            a[i][j] = cur;
        }
    cout << res << ' ';
}
void sub2(){
    res = inf;
    For (i, x, u)
        For (j, y, v){
            if (i == x && j == y) continue;
            if (i == u && j == v) continue;
            ll ans = -inf;
            if (j > y)
                For (t, i+1, u)
                    ans = max(ans, f[t][j-1]+g[t][j-1]-a[t][j-1]);
            if (j < v)
                For (t, x, i-1)
                    ans = max(ans, f[t][j+1]+g[t][j+1]-a[t][j+1]);
            res = min(res, ans);
        }
    cout << res << ' ';
}
void update(const int &col, int p, const ll &val){
    for (; p <= n; p += (p&-p))
        bit[col][p] = max(bit[col][p], val);
}
void _update(const int &col, int p, const ll &val){
    for (; p > 0; p -= (p&-p))
        _bit[col][p] = max(_bit[col][p], val);
}
ll get(const int col, int p){
    ll ans = -inf;
    for (; p > 0; p -= (p&-p))
        ans = max(ans, bit[col][p]);
    return ans;
}
ll _get(const int col, int p){
    ll ans = -inf;
    for (; p <= n; p += (p&-p))
        ans = max(ans, _bit[col][p]);
    return ans;
}
void tao(){
    srand(time(NULL));
    freopen (fname".inp", "w", stdout);
    n = 300 ; m = 299; k = 300;
    cout << n << ' ' << m << ' ' << k << '\n';
    For (i, 1, n){
        For (j, 1, m) cout << -3+rand()%10 << ' ';
        cout << '\n';
    }
    For (i, 1, k){
        x  = rand()%50+1;
        y  = rand()%50+1;
        u  = x+rand()%200+1;
        v  = y+rand()%200+1;
        cout << x << ' ' << y << ' ' << u << ' ' << v << '\n';
    }
}
int main(){
    //tao();
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    if (fopen(fname".inp", "r")){
        freopen (fname".inp", "r", stdin);
        freopen (fname".out", "w", stdout);
    }
    read(n); read(m); read(k);
    For (i, 1, n) For (j, 1, m) read(a[i][j]);
    while (k--){
        read(x); read(y); read(u); read(v);
        //sub1();
        For (i, 0, n+1) For (j, 0, m+1) f[i][j] = g[i][j] = -inf;
        For (j, 1, m) For (i, 1, n) bit[j][i] = _bit[j][i] = -inf;
        f[x][y] = a[x][y];
        g[u][v] = a[u][v];
        For (i, x, u)
            For (j, y, v){
                if (i == x && j == y) continue;
                f[i][j] = max(f[i-1][j], f[i][j-1])+a[i][j];
            }
        FOR (i, u, x)
            FOR (j, v, y){
                if (i == u && j == v) continue;
                g[i][j] = max(g[i+1][j], g[i][j+1])+a[i][j];
            }
        For (i, x, u)
            For (j, y, v){
                update(j, i, f[i][j]+g[i][j]-a[i][j]);
                _update(j, i, f[i][j]+g[i][j]-a[i][j]);
            }
        //sub2();
        res = inf;
        For (i, x, u)
            For (j, y, v){
                if (i == x && j == y) continue;
                if (i == u && j == v) continue;
                ll ans = -inf;
                if (j > y)
                    ans = max(ans, _get(j-1, i+1));
                if (j < v)
                    ans = max(ans, get(j+1, i-1));
                res = min(res, ans);
            }
        cout << res << '\n';
    }
}
