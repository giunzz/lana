#include <bits/stdc++.h>
#define ll long long
#define cll const long long
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
using namespace std;

void file(const string file){
    freopen((file + ".inp").c_str(), "r", stdin);
    freopen((file + ".out").c_str(), "w", stdout);
}

ll m, n, dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
vec(vec(ll)) a, f[4][2], d;

#define x first
#define y second

void init(vec(vec(ll)) &v, ll x){
    v.resize(m + 2);
    for(vec(ll) &i : v){
        i.resize(n + 2);
        for(ll &j : i) j = x;
    }
}

void dfs(pp(ll, ll) p){
    pp(ll, ll) np;
    bool dd[4] = {0};
    lp(i, 0, 3){
        np = {p.x + dx[i], p.y + dy[i]};
        if(d[np.x][np.y]) continue;
        d[np.x][np.y] = 1, dd[i] = 1;
        dfs(np);
    }
    lp(i, 0, 3){
        // if(dd[i]){
            np = {p.x + dx[i], p.y + dy[i]};
            ll dis = abs(a[p.x][p.y] - a[np.x][np.y]);
            // cerr << p.x << ' ' << p.y  << " -> " << np.x << ' ' << np.y << "   " << dis << "   " << f[3][0][np.x][np.y] << ' ' << f[3][1][np.x][np.y] << '\n';
            f[i][1][p.x][p.y] = dis;
            ll ttt = 0;
            // bool ok = 1;
            lp(j, 0, 3){
                if(f[j][1][np.x][np.y] == dis){
                    ttt = max(ttt, f[j][0][np.x][np.y]);// ok = 0;
                }
            }
            f[i][0][p.x][p.y] += ttt;
            // if(ok) ++f[i][0][p.x][p.y];
        // }
    }
}

int main(){
    // file("dnprevoic");
    ll sub;
    cin >> sub >> m >> n;
    // cerr << 1;
    init(a, 0); init(d, 0);
    // cerr << 1;
    lp(i, 0, 3) {init(f[i][0], 1); init(f[i][1], -1);}
    // cerr << 1;
    lp(i, 1, m) lp(j, 1, n) cin >> a[i][j];
    // cerr << 1;
    if(n == m && n == 1){
        cout << 1 << ' ' << 0 << ' ' << 1 << ' ' << 1;
        return 0;
    }
    lp(i, 0, m) d[i][0] = d[i][n + 1] = 1;
    lp(i, 1, n) d[0][i] = d[m + 1][i] = 1;
    // cerr << 1;
    lp(i, 1, m) lp(j, 1, n){
        if(!d[i][j]){
            d[i][j] = 1;
            dfs(pp(ll, ll)(i, j));
        }
    }
    ll dt = 1, k = 0;
    pp(ll, ll) res = {1, 1};
    lp(i, 1, m) lp(j, 1, n) lp(l, 0, 3){
        if(f[l][0][i][j] > k){
            k = f[l][0][i][j], dt = f[l][1][i][j], res = {i, j};
        }
        else if(f[l][0][i][j] == k && f[l][1][i][j] < dt){
            dt = f[l][1][i][j];
            res = {i, j};
        }
        else if(f[l][0][i][j] == k && f[l][1][i][j] == dt && i * n + j < res.x * n + res.y){
            res = {i, j};
        }
    }
    // lp(i, 1, n) cerr << f[3][0][5][i] << ' ' << f[3][1][5][i] << '\n';
    cout << k << ' ' << dt << ' ' << res.x << ' ' << res.y;
}