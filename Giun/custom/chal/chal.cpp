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
const string tenfile = "chal";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cll maxn = 1e3 + 7;
ll m, n , a[maxn][maxn];
bool d[(int)1e6+1] = {0};
vec(ll) snt;

void init(){
    for(ll i = 2; i <= 5e5; i++){
        if(!d[i]){
            snt.push_back(i);
            for(ll j = i * i; j <= 5e5; j += i) d[j] = 1;
        }
    }
}

struct quang{
    ll doc = 0, ngang = 0;
}f[maxn][maxn];

int main(){
    opt;
    file;
    init();
    cin >> m >> n;
    lp(i, 1, m){
        lp(j, 1, n) cin >> a[i][j];
    }
    lp(i, 1, m){
        lp(j, 1, n){
            ll tmp = lower_bound(snt.begin(), snt.end(), a[i][j]) - snt.begin();
            f[i][j] = {snt[tmp] - a[i][j], snt[tmp] - a[i][j]};
            f[i][j].doc += f[i - 1][j].doc;
            f[i][j].ngang += f[i][j - 1].ngang;
        }
    }
    ll ans = LLONG_MAX;
    lp(i, 1, m) ans = min(ans, f[i][m].ngang);
    lp(j, 1, n) ans = min(ans, f[m][j].doc);
    cout << ans;
}
