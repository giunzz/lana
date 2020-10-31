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
const string tenfile = "ac3";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".ans").c_str(), "w", stdout)

cll maxn = 70;
ll n, g, k, t, a[maxn], d[maxn], cnt;

struct dg{
    ll mi, ma;
}dg[maxn];


void ql(ll vt){
    if(vt > n){
        lp(i, 1, n){
            dg[d[i]].mi = min(dg[d[i]].mi, a[i]);
            dg[d[i]].ma = max(dg[d[i]].ma, a[i]);
        }
        lp(i, 1, g){
            if ((dg[i].ma - dg[i].mi) > k || (dg[i].ma == INT_MIN)){
                lp(i, 1, g) dg[i].mi = INT_MAX, dg[i].ma = INT_MIN;
                return;
            }
        }
        ++cnt;
        return;
    }
    lp(i, 1, g){
        d[vt] = i;
        ql(vt + 1);
    }
}

int main(){
    opt;
    file;
    cin >> t;
    while(t--){
        cnt = 0;
        cin >> n >> g >> k;
        lp(i, 1, n) cin >> a[i];
        ql(1);
        cout << (cnt % MOD) << endl;
    }
}
