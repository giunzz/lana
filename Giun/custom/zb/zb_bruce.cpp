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
const string tenfile = "zb";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".ans").c_str(), "w", stdout)

cll maxn = 1e3 + 7, maxk = 1e4 + 7;
ll n, f[maxn][maxk] = {{0}}, k;

int main(){
    opt;
    file;
    cin >> n >> k;
    f[1][0] = 1;
    lp(i, 2, n){
        lp(j, 0, k){
            lp(z, 0, i - 1){
                if(j - z < 0) continue;
                f[i][j] += f[i - 1][j - z] % MOD;
            }
        }
    }
    cout << f[n][k];
}
