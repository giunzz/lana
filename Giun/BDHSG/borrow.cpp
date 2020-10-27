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
    freopen(Fname ".inp", "r", stdin);
    freopen(Fname ".out", "w", stdout);
}

cll maxn = 2e5 + 7;
ll n, dC[maxn] = {0}, k = 0;
bool d[maxn] = {0}; 
vec(pp(ll, ll)) g[maxn], preg[maxn];

void init(){
    ll v, c;
    lp(u, 1, n){
        cin >> v >> c;
        cerr << u  << ' ' << v << ' ' << c << '\n';
        g[u].push_back({c, v});
        preg[v].push_back({c, u});
    }
}

#define pos second
#define cost first

void getCycle(ll &r){
    
}

void findCycle(ll &r){
    ll u = r;
    // pp(ll, ll) v = g[u];
    // if(d[v.pos]){
    //     if(dC[v.pos]) return;
    //     ++k;
    //     selectCycle(v.pos);
    // }
    while(g[u].size()){
        pp(ll, ll) v = g[u].back();
        if(d[v.pos]){
            getCycle(v.pos);
            break;
        }
        d[v.pos] = 1;
        u = v.pos;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n;
    init();
    lp(i, 1, n){
        if(!d[i]) findCycle(i);
    }
}