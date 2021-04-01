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

cll maxn = 1e3 + 7;
ll n, a[maxn], f[maxn][2];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n;
    lp(i, 1, n) cin >> a[i];
    f[1][0] = a[1], f[1][1] = 0;
    lp(i, 2, n){
        lp(j, 0, 1){
            ll sign = j ? -1 : 1;
            f[i][j] = max(f[i - 1][j], f[i - 1][!j] + sign * a[i]);
        }
    }
    cout << max(f[n][0], f[n][1]);
}