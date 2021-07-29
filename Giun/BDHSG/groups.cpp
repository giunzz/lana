#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "groups"
using namespace std;

ll read(){
    ll tmp;
    cin >> tmp;
    return tmp;
}

void giuncute(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll mxn = 2e5 + 7;
ll n, k, x, a[mxn], ans;
pp(ll, ll) b[mxn];

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n >> k >> x;
    ans = n;
    lp(i, 1, n) cin >> a[i];
    sort(a + 1, a + 1 + n);
    lp(i, 1, n - 1) b[i] = {a[i + 1] - a[i], i};
    sort(b + 1, b + n);
    lp(i, 1, n - 1){
        ll dis = b[i].first, pos = b[i].second;
        if(dis > x){
            if((dis - 1) / x <= k)
                k -= (dis - 1) / x;
            else break;    
        }
        --ans;
    }
    cout << ans;
}