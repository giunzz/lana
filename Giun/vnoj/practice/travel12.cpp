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

template <typename T> inline void Read(T &x){
    x = 0; char c;
    while(!isdigit(c = getchar()));
    do
    {
        x = x * 10 + c - '0';
    } while (isdigit(c = getchar()));
}

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

cll mxn = 1e4 + 2;
ll n, m;
vec(ll) g[mxn];
bitset<mxn> child[mxn];

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n >> m;
    lp(i, 1, m){
        ll u, v;
        cin >> u >> v;
        if(!child[u][v]){    
            g[u].push_back(v);
            g[v].push_back(u);
            child[u][v] = 1;
            child[v][u] = 1;
        }
    }
    lp(u, 1, n){
        bitset<mxn> f;
        for(ll v : g[u]){
            child[v][u] = 0;
            bitset<mxn> fw = f & child[v];
            if(fw.any()){
                ll w = 0;
                while(!fw[w]) ++w;
                for(ll vv : g[w]) if(vv != v && child[u][vv]){
                    cout << u << ' ' << v << ' ' << w << ' ' << vv;
                    return 0;
                }
            } 
            f |= child[v];
            child[v][u] = 1;
        }
    }
    cout << "-1";
}