#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "circle"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll maxn = 1e5 + 7;
ll n;
map<ll, ll> update;
pp(ll, ll) a[maxn];

bool cpr(pp(ll, ll) &x, pp(ll, ll) &y){
    return x.second < y.second;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n;
    lp(i, 1, n)
        cin >> a[i].first >> a[i].second;
    ll ans = 1;
    sort(a + 1, a + 1 + n, cpr);
    lp(i, 1, n){
        ll r = a[i].second, x = a[i].first;
        ll cnt = 1, tmp = x + r, t;
        while(update.find(tmp) != update.end() && (t = update[tmp]) >= x - r)
            tmp = t;
        if(tmp == x - r) ++cnt;
        ans += cnt;
        update[x + r] = x - r;
    }
    cout << ans;
}
