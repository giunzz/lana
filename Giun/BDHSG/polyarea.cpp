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

void giuncute(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

#define point pp(ll, ll)

cll mxn = 1e5 + 7;
ll n, ans = 0;
point a[mxn];
bool ok;

int main(){
    giuncute();
    #ifdef PMQ
    OF();
    #endif
    cin >> n;
    lp(i, 1, n) cin >> a[i].first >> a[i].second;
    point last = a[n];
    lp(i, 1, n){
        ans += (last.first * a[i].second - last.second * a[i].first), last = a[i];
    }
    if(ans < 0) cout << "CW ";
    else cout << "CCW ";
    ans = abs(ans);
    cout << ans / 2 << '.' << (ans & 1) * 5 << '\n';
}