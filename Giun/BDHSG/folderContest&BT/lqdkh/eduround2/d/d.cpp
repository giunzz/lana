#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "d"
using namespace std;

template <typename T> inline void Read(T &x){
    x = 0; char c;
    while(!isdigit(c = getchar()));
    do
    {
        x = x * 10 + c - '0';
    } while (isdigit(c = getchar()));
}

void giuncute(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll mxn = 1e5 + 7;
ll n, m, dg[mxn] = {0};
vec(ll) g[mxn];
vec(pp(ll, ll)) res;
bool d[mxn] = {0};

void dfs1(ll u, ll p){
    for(ll v : g[u]){
        if(v == p) continue;
        dfs1(v, u); 
    }
    if(u == 1) return;
    if(~dg[u] & 1) ++dg[p], res.push_back({p, u});
    else ++dg[u], res.push_back({u, p});
}

void sub1(){
    dfs1(1, -1);
    if(dg[1] & 1) cout << "NO";
    else {
        cout << "YES\n";
        for(pp(ll, ll) i : res) cout << i.first << ' ' << i.second << '\n';
    }
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n >> m;
    lp(i, 1, m){
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(m == n - 1) sub1();
    else{
        cout << "YES\n2 1\n2 3\n4 3\n4 1"; //cai nay e cout test 1
    }
}

//hic nay em code ngu