#include<bits/stdc++.h>
#define ll long long 
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define pp(a, b) pair<a, b>
#define Fname "f"
using namespace std;

void Ofile(){
    freopen(Fname ".inp", "r",  stdin);
    freopen(Fname ".out", "w",  stdout);
}

cll maxn = 3e5 + 7;
string s;
ll n, m, f[maxn], a[maxn], mi[maxn], ma[maxn];

ll getDSU(ll r){
    if(r != a[r]) a[r] = getDSU(a[r]);
    return a[r];
}

void unionDSU(ll u, ll v){
    u = getDSU(u), v = getDSU(v);
    if(u == v) return;
    if(f[u] > f[v]) swap(u, v);
    a[u] = v;
    f[v] += f[u];
    mi[v] = min(mi[v], mi[u]), ma[v] = max(ma[v], ma[u]);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    Ofile();
    cin >> n >> m;
    lp(i, 1, n) f[i] = 1, a[i] = i, mi[i] = i, ma[i] = i;
    ll u, v;
    lp(i, 1, m){
        cin >> s;
        if(s == "union") {cin >> u >> v; unionDSU(u, v);}
        else{cin >> u; cout << mi[getDSU(u)] << ' ' << ma[getDSU(u)] << ' ' << f[getDSU(u)] << '\n';}
    }
}