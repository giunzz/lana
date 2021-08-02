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

void giuncute(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

#define point pp(ll, ll)

inline ll dis(point &a, point &b){
    return (b.first - a.first) * (b.first - a.first) + (b.second - a.second) * (b.second - a.second);
}

inline void input(point &x){
    scanf("%lld %lld", &x.first, &x.second);
}

cll mxn = 1e5 + 7;
ll n, ans = 0;
point a[mxn];

int main(){
    // #ifndef ONLINE_JUDGE
    // OF();
    // #endif
    scanf("%lld", &n);
    lp(i, 0, n - 1) input(a[i]);
    ll j = 0, nj;
    lp(i, 0, n - 1){
        nj = (j + 1) % n;
        while(dis(a[i], a[j]) <= dis(a[i], a[nj])){
            j = nj, nj = (j + 1) % n;
        }
        ans = max(ans, dis(a[i], a[j]));
    }
    printf("%lld", ans);
}