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
const string tenfile = "spirit";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

ll a, b, c;

int main(){
    opt;
    // file;
    cin >>a >> b >> c;
    ll sa = (a / c + 1) * c, eb = b / c * c;
    if(sa > b){
        cout << (b - a + 1) / 2;
        return 0;
    }
    // cerr << sa << ' ' << eb << '\n';
    ll a1 = (sa - a + 2) / 2, aa = ((c + 1) / 2) * (eb - sa)/c, a2 = (b - eb) / 2;
    // cerr << a1 << ' ' << aa << ' ' << a2;
    cout << (a1 + aa + a2) << '\n';
}
