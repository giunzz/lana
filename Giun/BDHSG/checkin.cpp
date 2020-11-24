#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "checkin"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll maxn = 1e5 + 7;
ll n, m, a[maxn], ans = 0;

void cnp(ll r){
    ll l = 1;
    while(l <= r){
        ll mid = (l + r) / 2, tmp = 0;
        lp(i, 1, n){
            tmp += mid / a[i];
        }
        if(tmp >= m) r = mid - 1, ans = mid;
        else l = mid + 1;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n >> m;
    ll ma = 0;
    lp(i, 1, n){
        cin >> a[i];
        ma = max(ma, a[i]);
    }
    cnp(ma * m);
    cout << ans;
}