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
vec(vec(ll)) a;
vec(vec(bool)) d;
vec(vec(pp(ll, ll))) g;
vec(ll) ans; 
ll sum = 0, suma = LLONG_MAX;

void ql(ll u){
    for(pp(ll, ll) v : g[u]){
        if(d[u][v.second] || v.first + sum >= suma) continue;
        d[u][v.second] = 1;
        
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n;
    a.resize(2*n + 1); g.resize(2*n + 1); d.resize(2*n + 1);
    for(vec(ll) &i : a) i.resize(2*n + 1);
    for(vec(bool) &i : d) i.resize(2 * n + 1);
    lp(i, 0, 2 * n) lp(j, 0, 2 * n){
        d[i][j] = 0;
        cin >> a[i][j];
        g[i].push_back({a[i][j], j});
    }
    // for(vec(pp(ll, ll)) &i : g) sort(i.begin(), i.end());
}