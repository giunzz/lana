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
const string tenfile = "bonus";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cll maxn = 307, maxk = 157;
ll f[maxn][maxn][maxk] = {{{0}}}, n, a[maxn], k, t1, t2, t3, t4, t5, y;

ii main(){
    opt;
    // file;
    cin >> n >> k;
    lp(i, 1, n) cin >> a[i];
    lp(tmp, 1, n){
        lp(x, 1, n - tmp + 1){
            y = x + tmp;
            if(y > n || y < 1) break;
            lp(z, 1, k){
                if(2 * z > y - x + 1) break;
                t1 = abs(a[x] - a[x + 1]) + f[x + 2][y][z - 1];
                t2 = abs(a[y] - a[y - 1]) + f[x][y - 2][z - 1];
                t3 = abs(a[x] - a[y]) + f[x + 1][y - 1][z - 1];
                t4 = f[x + 1][y][z];
                t5 = f[x][y - 1][z];
                f[x][y][z] = max(t1, max(t2, max(t3, max(t4, t5))));
            }
        }
    }
    cout << f[1][n][k];
}
