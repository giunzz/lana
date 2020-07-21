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
const string tenfile = "ac6";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cll maxn = 1e5 + 7;
ll qr, n, m, k, d, g[5], tt[maxn], ans = 0;
string tmp;

int main(){
    opt;
    file;
    cin >> qr;
    while(qr--){
        ans = 0;
        cin >> n >> m >> k >> d >> g[1] >> g[2] >> g[3] >> tmp;
        if(g[2] >= 2 * g[1] && n > 1) {
            ans += (n / 2) * g[2], n &= 1;
            if(n && k) ans += g[1];
        }
        else{
            ans += min(k, n) * g[1], n = max(n - k, (ll)0);
            ans += (n / 2) * g[2], n &= 1;
            if(n) ans = max(ans, ans - g[1] + g[2]);
        }
        cout << ans << endl;
    }
}
