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
const string tenfile = "f";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cll maxn = 107;
ll s, n, a[maxn] = {0}, ans = 0, b, sum = 0, ma = -1, f[maxn][(int)1e5 + 7] = {{0}};

int main(){
    opt;
    file;
    cin >> n >> s;
    lp(i, 1, n) cin >> a[i], sum += a[i], ma = max(ma, a[i]);
    while (s - ma > 2 * sum){
        s -= ma, ++ans;
    }
    cerr << s;
    lp(i, 1, s) f[0][i] = LLONG_MAX/2;
    lp(i, 1, n){
        lp(j, 0, s){
            if(j < a[i]) f[i][j] = f[i - 1][j];
            else f[i][j] = min(f[i - 1][j], f[i][j - a[i]] + 1);
        }
    }
    cout << ans + f[n][s];
}
