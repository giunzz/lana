#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "tank"
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

cll maxn = 507;
ll n;
pp(ll, ll) a[maxn];

bool cpr(pp(ll, ll) &a, pp(ll, ll) &b){
    return a.second < b.second;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n;
    lp(i, 1, n) cin >> a[i].first >> a[i].second;
    ll ans = 0;
    sort(a + 1, a + 1 + n);
    lp(i, 1, n) ans += abs(a[i].first - i);
    sort(a + 1, a + 1 + n, cpr);
    lp(i, 1, n) ans += abs(a[i].second - i);
    cout << ans;
}