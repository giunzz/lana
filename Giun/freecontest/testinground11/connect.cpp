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

cll maxn = 1e5 + 7, MOD = 1e9 + 7;
ll n, a[maxn], b[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n;
    lp(i, 1, n) cin >> a[i];
    lp(i, 1, n) cin >> b[i];
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n);
    ll ans = 0;
    lp(i, 1, n) (ans += abs(a[i] - b[i])) %= MOD;
    cout << ans;
}