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

cll maxn = 1e5 + 7;
ll g[maxn] = {0};

void init(){
    g[1] = 0;
    lp(i, 2, 1e5){
        unordered_set<ll> s;
        for(ll j = 1; j * j <= i; ++j){
            if(!(i % j)){
                ll fi = j, se = i / j;
                if(fi & 1) s.insert(g[se]);
                if(se & 1) s.insert(g[fi]);
            }
        }
        ll mex = 0;
        while(s.find(mex) != s.end()) ++mex;
        g[i] = mex;
    }
}

void sol(){
    ll n, ans = 0;
    cin >> n;
    lp(i, 1, n){
        ans ^= g[read()];
    }
    if(ans) cout << "1\n";
    else cout << "2\n";
}

// #define ONLINE_JUDGE PMQ
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    init();
    EACHCASE sol();
}