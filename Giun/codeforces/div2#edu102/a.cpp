#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "f"
#define YES "YES\n"
#define NO "NO\n"
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

void sol(){
    ll n, d;
    cin >> n >> d;
    vec(ll) a(n);
    for(ll &i : a) cin >> i;
    sort(a.begin(), a.end());
    if(a.back() <= d)
        cout << YES;
    else{
        if(a[0] + a[1] <= d) cout << YES;
        else cout << NO;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    EACHCASE sol();
}