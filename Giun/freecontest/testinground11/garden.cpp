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

#define ONLINE_JUDGE
cll maxn = 1e5 + 7;
ll n, t, a[maxn], b[maxn];

bool check(ll val){
    ll nuoc = 0, opt = LLONG_MAX;
    lp(i, 1, n){
        if(a[i] >= val) continue;
        ll tmp = ceil((val - a[i]) / (double)b[i]); 
        nuoc += tmp;
        opt = min(opt, a[i] + tmp * b[i]);
    }
    return nuoc <= t;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n >> t;
    ll ma = 0;
    lp(i, 1, n){cin >> a[i] >> b[i]; ma = max(ma, a[i] + t * b[i]);}
    ll l = 1, r = ma, ans = 1;
    while(l <= r){
        ll mid = (l + r) >> 1, tmp;
        if(tmp = check(mid)){
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << ans;
}