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

struct adj_bus{
    ll s, t, a, b, id;
    void init(ll _id){
        cin >> a >> b >> s >> t;
        id = _id;
    }
    bool operator<(const ll &_t){
        return s < _t;
    }
};

cll mxn = 1e5 + 7;
ll n, m, q, go[mxn] = {0};
pp(ll, ll) ask_bus[mxn];
adj_bus bus[mxn];
vec(ll) g[mxn];
vec(adj_bus) bus_at[mxn];

bool cpr(adj_bus &a, adj_bus &b){return a.s < b.s;}

bool cpr_id(adj_bus &a, adj_bus &b){return a.id < b.id;}

priority_queue dfs(ll u){
    
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE    
    OF();
    #endif
    cin >> n >> m >> q;
    lp(i, 1, m) 
        bus[i].init(i);
    sort(bus + 1, bus + 1 + m, cpr);
    lp(i, 1, m) bus_at[bus[i].a].push_back(bus[i]);
    lp(i, 1, m){
        // xu ly tao do thi + danh dau adj da them vao
        ll b = bus[i].b, t = bus[i].t, 
            pos = lower_bound(bus_at[b].begin(), bus_at[b].end(), t) - bus_at[b].begin();
        if(pos != bus_at[b].size()) go[bus[i].id] = bus_at[b][pos].id;
    }
    lp(i, 1, q){
        ll time, city, req;
        cin >> time >> city >> req;
        auto pos = lower_bound(bus_at[city].begin(), bus_at[city].end(), req);
        if(pos != bus_at[city].end()) ask_bus[(*pos).id] = {req, i};
    }
    lp(i, 1, n) if(go[i]) g[go[i]].push_back(i);
    sort(bus + 1, bus + 1 + m, cpr_id);
    lp(i, 1, n) if(!go[i]){
        set<ll> s = dfs(i);
    }
    // lp(i, 1, n){
    //     cerr << i << "\n----> ";
    //     for(ll j : g[i]) cerr << j << ' ';
    //     cerr << '\n';
    // }
    // lp(i, 1, m){
    //     cerr << i << '\n';
    //     for(auto j : bus_at[i]){
    //         cerr << j.s << ' ';
    //     }
    //     cerr << '\n';
    // }
}