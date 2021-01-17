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
cll maxn = 2e5 + 7;
ll n, a[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n;
    lp(i, 1, n) cin >> a[i];
    ll ma = LLONG_MAX;
    sort(a + 1, a + 1 + n);
    lp(i, 2, n){
        ma = min(abs(a[i] - a[i - 1]), ma);
        // cerr << ma << ' ';
    }
    cout << ma;
}