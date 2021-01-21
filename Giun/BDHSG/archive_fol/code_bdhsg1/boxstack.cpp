#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define vec(a) vector<a>
#define Fname "boxstack"
using namespace std;

void OF(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(Fname ".inp", "r", stdin);
    freopen(Fname ".out", "w", stdout);
}

struct quang{
    ll c, r = 0, d = 0;
};

ll n;
vec(quang) a;
vec(ll) f;

inline bool cpr(quang &x, quang &y){
    // return (x.d < y.d ? 1 : (x.d == y.d ? x.r < y.r : 0));
    return (x.d * x.r >= y.d * y.r);
}

void init(){
    a.resize(n + 1);
    ll h, w, d;
    lp(i, 1, n){
        cin >> h >> w >> d;
        // a[i] = {h, min(w, d), max(w, d)};
        a[i].c = h;
        a[i].r = min(w, d);
        a[i].d = max(w, d);
    }
    sort(a.begin() + 1, a.end(), cpr);
}

ll solve(){
    ll res = 0;
    a[0].r = 0, a[0].d = 0;
    f.resize(n + 1);
    lp(i, 0, n) f[i] = 0;
    lp(i, 1, n){
        lp(j, 0, i - 1){
            if(a[j].r >= a[i].r && a[j].d >= a[i].d){
                f[i] = max(f[i], f[j]);
            }
        }
        f[i] += a[i].c;
        res = max(res, f[i]);
    }
    return res;
    // return f[n];
}

int main(){
    OF();
    cin >> n;
    init();
    cout << solve();
}