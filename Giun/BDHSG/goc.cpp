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

cll mxn = 362;
ll n, k, a[mxn];
bool d[mxn] = {0};

void sol(ll num){
    ll t;
    lp(i, 1, n){
        t = num + a[i];
        if(t > 360) t -= 360;
        if(d[t]) continue;
        d[t] = d[360 - t] = 1;
        sol(t);
        sol(360 - t);
    }
    lp(i, 1, n){
        t = num - a[i];
        if(t < 0) t = -t;
        if(d[t]) continue;
        d[t] = d[360 - t] = 1;
        sol(t);
        sol(360 - t);
    }
}

int main(){
    giuncute();
    ll tmp;
    cin >> n >> k;
    lp(i, 1, n) cin >> a[i];
    lp(i, 1, n){
        d[a[i]] = 1;
        sol(a[i]);
    }
    lp(i, 0, 360) if(d[i]) sol(i);
    lp(i, 1, k){
        cin >> tmp;
        if(d[tmp]) cout << "YES\n";
        else cout << "NO\n";
    } 
}