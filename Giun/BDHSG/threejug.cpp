#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "f"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

ll d, q;
pp(ll, ll) t[3];

#define dt first
#define w second

ll prc(pp(ll, ll) &a, pp(ll, ll) &b, pp(ll, ll) &c){
    //a + dx = q
    ll tmp = q - a.w;
    if(tmp%d) return LLONG_MAX;
    if(tmp == 0) return 0;
    if (tmp < 0){
        ll out = -tmp / d;
        ll t1 = (b.dt - b.w) / d, t2 = (c.dt - c.w) / d;
        if(t1 + t2 >= out) return out;
        return LLONG_MAX;
    }
    if(a.dt < q) return LLONG_MAX;
    ll in = tmp / d;
    ll t1 = b.w / d, t2 = c.w / d;
    if(t1 + t2 >= in) return in;
    return LONG_LONG_MAX;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // OF();
    lp(i, 0, 2) cin >> t[i].dt;
    lp(i, 0, 2) cin >> t[i].w;
    cin >> d >> q;
    //process 3 bottles
    // sort(t, t + 3, cpr);
    // if(t[0].dt < q || t[0].w % d != q % d){
    //     cout << "-1";
    //     return 0;
    // }
    // ll tg = (q - t[0].w) / d;
    // if(t[1].w / d + t[2].w / d >= tg){
    //     cout << tg;
    // }
    // else cout << "-1";
    ll ans = min(prc(t[0], t[1], t[2]), min(prc(t[1], t[0], t[2]), prc(t[2], t[0], t[1])));
    if(ans == LLONG_MAX) cout << -1;
    else cout << ans;
}
