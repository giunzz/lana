#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define pp(a, b) pair<a, b>
#define vec(a) vector<a>
#define vecite(a) vector<a>::iterator
#define fi first
#define se second
// #define mp(a, b) map<a, b>
#define setE(a, b) fill_n(a, sizeof(a)/sizeof(a[0]), b)
#define st(a) system((a).c_str());
using namespace std;
cll MOD = 1e9 + 7;
const double esf = 1e-9;
const string tenfile = "garden";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cll maxn = 507;
ll n, m, q, dp[maxn][maxn] = {{0}}, dp1[maxn][maxn] = {{0}};
vec(pp(ll, ll)) g;

#define mp make_pair

int main(){
    opt;
    file;
    cin >> n >> m;
    lp(i, 1, n) lp(j, 1, m){
        char x;
        cin >> x;
        if(x == 'x'){
            dp[i][j] = dp1[i][j] = i;
            // g.push_back(mp(i, j));
        }
    }
    lp(i, 1, n) lp(j, 1, n) dp[i][j] = dp[i][j] ? dp[i][j] : dp[i - 1][j];
    lpd(i, n, 1) lp(j, 1, n) dp1[i][j] = dp1[i][j] ? dp1[i][j] : dp1[i + 1][j];
    cin >> q;
    lp(t, 1, q){
        ll x, y, ma = LLONG_MAX;
        cin >> x >> y;
        lp(i, 1, m){
            ll nx = dp[x][i], ny = i;
            if(nx == 0) continue;
            ma = min(ma, (nx - x) * (nx - x) + (ny - y) * (ny - y));
        }
        lp(i, 1, m){
            ll nx = dp1[x][i], ny = i;
            if(nx == 0) continue;
            ma = min(ma, (nx - x) * (nx - x) + (ny - y) * (ny - y));
        }
        dp[x][y] = x;
        lp(i, x + 1, n) dp[i][y] = dp[i][y] ? dp[i][y] : dp[i - 1][y];
        lpd(i, x - 1, 1) dp1[i][y] = dp1[i][y] ? dp1[i][y] : dp1[i + 1][y];
        cout << ma << '\n';
    }
}
