#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "f"
using namespace std;

void OF(){
    freopen(Fname ".inp", "r", stdin);
    freopen(Fname ".out", "w", stdout);
}

cll maxn = 1e4 + 7;
ll a[maxn], f[maxn];

ll getD(ll u){
    if(a[u] != u) a[u] = getD(a[u]);
    return a[u];
}

void unionD(ll u, ll v){
    u = getD(u);
    v = getD(v);
    if(u == v) return;
    if(f[u] > f[v]) swap(u, v);
    f[v] += f[u];
    a[u] = v;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // OF();
    lp(i, 0, maxn-1) a[i] = i;
    ll x, y, stt, p;
    cin >> p;
    while(p--){
        cin >> x >> y >> stt;
        if(stt == 1) unionD(x, y);
        else cout << (getD(x) == getD(y)) << '\n';
    }  
}