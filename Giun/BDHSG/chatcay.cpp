#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define lpdk(a, b, c, d) for(ll a = b; c; d) 
#define pp(a, b) pair<a, b>
#define vec(a) vector<a>
#define vecite(a) vector<a>::iterator
#define fi first
#define se second
using namespace std;
cll MOD = 1e9 + 7;
const string tenfile = "chatcay";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cii maxn = 1e4 + 7;
ii n, w;
pp(ii, ii) a[maxn];
ii f[maxn][maxn] = {{0}};

int main(){
    opt;
    file;
    cin >> n >> w;
    lp(i, 1, n) cin >> a[i].fi >> a[i].se;
    lp(i, 1, w) if(a[1].fi < i) f[1][i] = a[1].se;
    lp(i, 1, n){
        lp(j, 1, w){
            if(a[i].fi > j) f[i][j] = f[i-1][j];
            else f[i][j] = max(f[i - 1][j], f[i-1][j - a[i].fi] + a[i].se);
        }
    } 
    cout << f[n][w];
}
