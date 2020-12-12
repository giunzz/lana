#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "nhanpham"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll maxn = 1e5 + 7;
ll n, k, t[maxn], s[maxn];

ll sol(ll al){
    ll a = n * n, b = 2 * al * n + 3 * n - 2 * s[n - 1], c = al * al + 3 * al + 2 - 2 * (s[al] + k);
    ll del = b * b - 4 * a * c;
    double x1 = (-b + (double)sqrt(del)) / (2.0 * a);
    double x2 = (-b - (double)sqrt(del)) / (2.0 * a);
    if(x1 > x2) swap(x1, x2);
    if(x1 < 0) swap(x1, x2);
    return (ll)ceil(x1) * n + al + 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n >> k;
    lp(i, 0, n - 1) cin >> t[i];
    s[0] = t[0];
    lp(i, 1, n - 1) s[i] = s[i - 1] + t[i];
    ll res = LLONG_MAX;
    lp(i, 0, n - 1){
        res = min(res, sol(i));
    }
    cout << res;
}