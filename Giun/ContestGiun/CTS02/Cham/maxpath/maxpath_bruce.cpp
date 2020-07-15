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
const string tenfile = "maxpath";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".ans").c_str(), "w", stdout)

cll maxn = 2e3 + 7;
ll m, n, a[maxn][maxn] = {{0}}, f[maxn][maxn];

ii main(){
    opt;
    file;
    cin >> m >> n;
    lp(i, 1, m)
        lp(j, 1, n) cin >> a[i][j];
    lp(i, 0, (max(m, n) + 3)) f[i][0] = -1, f[0][i] = -1;
    f[1][1] = a[1][1]; 
    lp(i, 1, m){
        lp(j, 1, n){
            if(i == 1 && j == 1) continue;
            if(a[i][j] == -1){f[i][j] = -1; continue;}
            f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            if(f[i][j] != -1) f[i][j] += a[i][j];
        }
    }
    cout << f[m][n];
}
