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
#pragma GCC optimize("Ofast")
using namespace std;
ll MOD = 1e9 + 7;
const double esf = 1e-9;
const string tenfile = "superfb";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

ll x, m;

struct quang{
    ll a11, a12, a21, a22;
};

quang f = {1, 1, 1, 0};

inline quang mul(quang q, quang p){
    quang t = { (q.a11 * p.a11 + q.a12 * p.a21) % MOD,
                (q.a11 * p.a12 + q.a12 * p.a22) % MOD,
                (q.a21 * p.a11 + q.a22 * p.a21) % MOD,
                (q.a21 * p.a12 + q.a22 * p.a22) % MOD
                };
    return t;
}

inline quang Pow(quang t, ll n){
    if(n == 1) return t;
    quang tmp = Pow(t, n / 2);
    if(n % 2) return mul(mul(tmp, tmp), t);
    else return mul(tmp, tmp);
}

unsigned ll o[1002];

int main(){
    o[0] = 0, o[1] = 1;
    lp(i, 2, 1000) {
        if(ULLONG_MAX - o[i - 1] < o[i - 2]) break;
        o[i] = o[i - 1] + o[i - 2];
    }
    opt;
    // file;
    cin >> x >> m;
    MOD = m;
    quang tmp = Pow(f, o[x]);
    // tmp = Pow(f, tmp.a12);
    cout << (tmp.a12) % m;
}
