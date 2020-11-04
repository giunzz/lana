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
const string tenfile = "morgan";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".ans").c_str(), "w", stdout)

ll n, k, a, b, f[(int)1e6 + 7];

int main(){
    opt;
    file;
    cin >> n >> k >> a >> b;
    f[1] = 0;
    lp(i, 2, n){
        f[i] = f[i - 1] + a;
        if(!(i % k)) f[i] = min(f[i], f[i / k] + b);
    }
    cout << f[n];
}
