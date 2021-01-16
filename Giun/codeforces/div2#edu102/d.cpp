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

void sol(){
    ll n, m, x = 0;
    unordered_map<ll, ll> d;
    string s;
    cin >> n >> m >> s;
    s = '.' + s;
    vec(ll) a(n + 1, 0);
    a[1] = 2;
    lp(i, 1, n - 1){
        if(s[i] == '-') --x;
        else ++x;
        if(i > 1){
            a[i] = a[i - 1];
            if(!d[x]) ++a[i];
        }
        d[x] = 1;  
    }
    lp(i, 1, m){
        ll l, r;
        cin >> l >> r;

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