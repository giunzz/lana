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

cll maxs = 2e5 + 7;
ll cases, t[2];

struct tt{
    ll cnt, cs, cw;
} f[maxs];

ll sol(ll tg1, ll tg2, ll cnts, ll cntw, ll s, ll w){
    ll tmp = 0, tmpt = INT_MAX;
    ll res[2] = {0};
    pp(ll, ll) r[2];
    r[0] = {0, 0}, r[1] = {0, 0};
    lp(i, 0, cnts){
        tmp = (t[tg1] - (i * s)) / w;
        tmp = min(tmp, cntw);
        if(i + tmp > res[tg1 && (i * s + tmp * w) < tmpt]) res[tg1] = tmp + i, r[tg1] = {i, tmp}, tmpt = i * s + tmp * w;
        f[i] = {tmp + i, i, tmp};
    }
    cnts -= r[tg1].fi, cntw -= r[tg1].se;
    lp(i, 0, cnts){
        tmp = (t[tg2] - (i * s)) / w;
        tmp = min(tmp, cntw);
        if(i + tmp > res[tg2]) res[tg2] = tmp + i, r[tg2] = {i, tmp};
    }
    return res[0] + res[1];
}

ii main(){
    opt;
    // file;
    cin >> cases;
    ll cnts, cntw, s, w;
    while (cases --> 0){
        cin >> t[0] >> t[1] >> cnts >> cntw >> s >> w;
        ll ans1 = sol(0, 1, cnts, cntw, s, w), ans2 = sol(1, 0, cnts, cntw, s, w);
        // cerr << rf.first << ' ' << rf.se;
        cout << max(ans1, ans2) << endl;
    }   
}
