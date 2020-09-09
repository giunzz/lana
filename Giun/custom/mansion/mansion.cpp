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
const string tenfile = "mansion";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

ll n, m, k;
cll maxn = 2e5 + 7;
vec(pp(ll, ll)) g[maxn];
vec(ll) hang[maxn], cot[maxn];

int main(){
    opt;
    file;
    cin >> m >> n >> k;
    ll x, y;
    hang[1].push_back(0); cot[1].push_back(0);
    hang[n].push_back(k + 1); cot[n].push_back(k + 1);
    lp(i, 1, k){
        cin >> x >> y;

    }
}
