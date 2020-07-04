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
const string tenfile = "chonlinh";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cll maxn = 1e6 + 7;
ll n, a[maxn] = {0}, ans = -1, dem = 0;

void sol(){
    ll s = a[1], j = 0, i = 1;
    while(j <= n){
        if(i > j) j = i, s = a[i];
        while(!(s & a[j + 1]) && j <= n){
            s += a[++j];
        }
        if(s > ans) ans = s, dem = 1;
        else if(s == ans) ++dem;
        if(j > n) break;
        while(s & a[j + 1]) {s -= a[i++];}
    }
}

ii main(){
    opt;
    file;
    cin >> n;
    lp(i, 1, n) cin >> a[i];
    sol();
    cout << ans << " " << dem;
}
