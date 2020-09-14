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
#define mp(a, b) map<a, b>
#define setE(a, b) fill_n(a, sizeof(a)/sizeof(a[0]), b)
#define st(a) system((a).c_str());
using namespace std;
cll MOD = 1e9 + 7;
const double esf = 1e-9;
const string tenfile = "voi";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cll maxn = 5e2 + 7;
ll m, n, a[maxn][maxn], cnt = 0, dd;
bool lk[maxn][maxn];
pp(ll, ll) q = {-1, -1};

bool d[maxn][maxn];

void dfs(ll x, ll y, ll &dc){
    if(x == 0 || x > m) return;
    if(y == 0 || y > n) return;
    d[x][y] = 1;
    if(lk[x][y]) ++dd;
    if(abs(a[x - 1][y] - a[x][y]) <= dc && !d[x - 1][y]) dfs(x - 1, y, dc);
    if(abs(a[x + 1][y] - a[x][y]) <= dc && !d[x + 1][y]) dfs(x + 1, y, dc);
    if(abs(a[x][y - 1] - a[x][y]) <= dc && !d[x][y - 1]) dfs(x, y - 1, dc);
    if(abs(a[x][y + 1] - a[x][y]) <= dc && !d[x][y + 1]) dfs(x, y + 1, dc);
}

int main(){
    opt;
    file;
    ll ma = INT_MIN, mi = INT_MAX, ans;
    cin >> m >> n;
    lp(i, 1, m)
        lp(j, 1, n) {cin >> a[i][j]; ma = max(ma, a[i][j]);}
    lp(i, 1, m)
        lp(j, 1, n){
            cin >> lk[i][j];
            if(lk[i][j]) q = {i, j}, ++cnt;
        }
    if(q == make_pair(-1LL, -1LL)) cout << 0;
    else{
        ll l = 0, r = ma, mid;
        while(l <= r){
            mid = (l + r) / 2;
            memset(d, 0, sizeof(d));
            dd = 0;
            dfs(q.first, q.second, mid);
            if(dd == cnt) r = mid - 1, ans = mid;
            else l = mid + 1;
        }
        cout << ans;
    } 
}
