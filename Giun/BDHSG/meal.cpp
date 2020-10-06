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
const string tenfile = "f";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cll maxn = 5e5 + 7;

struct quang{
    ll a, b;
}a[maxn];

ll n, f[maxn], ff[maxn];

inline bool cpr(quang x, quang y){
    return x.b < y.b;
}

void init(){
    f[n] = a[n].a;
    lpd(i, n - 1, 1) f[i] = min(f[i + 1], a[i].a);
    ff[1] = a[1].a - a[1].b;
    lp(i, 2, n) ff[i] = min(a[i].a - a[i].b, ff[i - 1]);
}

ii main(){
    opt;
    file;
    cin >> n;
    lp(i, 1, n) cin >> a[i].a >> a[i].b;
    sort(a + 1, a + 1 + n, cpr);
    init();
    ll s = 0;
    lp(i, 1, n){
        cout << min(s + f[i], (s += a[i].b) + ff[i]) << endl;
    }
}
