#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "tank"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll maxn = 1e5 + 7;
ll n, m, a[maxn] = {0}, ans = 0;

ll cnp(ll l, ll r, ll t){
    ll res = 0;
    while(l <= r){
        ll mid = (l + r) / 2;
        if(a[t] - a[mid] >= m) res = t - mid, l = mid + 1;
        else r = mid - 1;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> m >> n;
    lp(i, 1, n){
        cin >> a[i];
        a[i] += a[i - 1];
        ans = max(cnp(0, i - 1, i), ans);
    }
    cout << ans;
}