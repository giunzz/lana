#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "f"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

ll n;
vec(ll) a;

ll sol(ll l, ll r){
    if(l == r) return 1;
    ll mid = (l + r) >> 1, res = sol(l, mid) + sol(mid + 1, r);
    vec(ll) lmin, rmin, lmax, rmax;
    lmin.resize(mid - l + 7), rmin.resize(r - mid + 7), lmax = lmin, rmax = rmin;
    lmin[0] = lmax[0] = a[mid], rmin[0] = rmax[0] = a[mid + 1];
    ll j = mid + 1, jr = ;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n;
    a.resize(n + 7);
    lp(i, 1, n) cin >> a[i];
    cout << sol(1, n);
}