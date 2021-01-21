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

cll maxn = 24;
ll n, a[maxn][maxn] = {{0}}, tt[maxn] = {0};

void init(){
    ll x = 1;
    lp(i, 1, n){
        tt[i] = x;
        x = x << 1;
    }
}

ii main(){
    opt;
    file;
    cin >> n;
    lp(i, 1, 20){
        lp(j, 1, 20) cin >> a[i][j];
    }
    init();
    lp(i, 1, n) cerr << tt[i] << " ";
}
