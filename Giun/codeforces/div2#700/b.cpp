#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "f"
using namespace std;

ll read(){
    ll tmp;
    cin >> tmp;
    return tmp;
}

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll maxn = 1e5 + 7;
ll hth, dmg, n, a[maxn], b[maxn];
pp(ll, ll) c[maxn];

#define NO "NO\n"
#define YES "YES\n"

inline bool cpr(pp(ll, ll) &x, pp(ll, ll) &y){
    return x.first < y.first;
}

void sol(){
    cin >> dmg >> hth >> n;
    lp(i, 1, n) cin >> c[i].first;
    lp(i, 1, n) cin >> c[i].second;
    sort(c + 1, c + 1 + n, cpr);
    ll cnt = 0;
    lp(i, 1, n){
        if(hth <= 0) continue;
        ll minAct = c[i].second / dmg;
        if(minAct * dmg == c[i].second) --minAct;
        hth -= c[i].first * minAct;
        if(hth > 0) ++cnt;
        hth -= c[i].first;
    }
    // ll tmp = b[n] - (dmg * ceil(hth / (double)a[n]));
    //one act
    // cerr << hth << '\n';
    if(cnt != n) cout << NO;
    else cout << YES;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    EACHCASE sol();
}