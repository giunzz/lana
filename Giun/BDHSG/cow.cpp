#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "cow"
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
ll n, c, a[maxn], id[maxn] = {0};

bool sol(ll num){
    vec(ll) f(n + 1, 0);
    ll j = 0;
    lp(i, 1, n){
        if(a[i] - num < 0) f[i] = 1;
        else {
            while(a[j + 1] <= a[i] - num && j < i) ++j;
            f[i] = max(f[i - 1], f[j] + 1);
        }
    }
    return f[n] >= c;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n >> c;
    lp(i, 1, n) cin >> a[i];
    sort(a + 1, a + 1 + n);
    ll l = 1, r = a[n], ans = LLONG_MAX;
    while(l <= r){
        ll mid = (l + r) >> 1;
        if(sol(mid)){
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << ans;
}