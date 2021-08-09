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

cll mxn = 1e5 + 7, mxlog = 20;
ll n, m, q, go[mxn] = {0}, par[mxn][mxlog], mhigh[mxn] = {0};
vec(pp(ll, ll)) ask_bus[mxn];
pp(ll, ll) ans[mxn];
adj_bus bus[mxn];
vec(ll) g[mxn]; // 1 -> m
vec(adj_bus) bus_at[mxn]; // 1 -> n

bool cpr(adj_bus &a, adj_bus &b){return a.s < b.s;}

bool cpr_id(adj_bus &a, adj_bus &b){return a.id < b.id;}

void dfs(ll u, ll p){
    par[u][0] = p;
    lp(i, 1, 17) if(~par[u][i - 1] && ~(par[u][i] = par[par[u][i - 1]][i - 1])) mhigh[u] = i;
    if(par[u][mhigh[u]] == -1) mhigh[u] = -1;
    while(ask_bus[u].size()){
        ll req = ask_bus[u].back().first, idq = ask_bus[u].back().second, far = u;
        ask_bus[u].pop_back();
        bool ok = 1;
        while(ok){
            ok = 0;
            lpd(i, mhigh[far], 0){
                ll nu = par[far][i];
                if(bus[nu].t <= req){far = nu, ok = 1; break;}
            }
        }
        // if(u == 2) cerr << mhigh[2] << ' ';
        if(bus[far].s < req) ans[idq] = {bus[far].a, bus[far].b};
        else ans[idq] = {bus[far].a, -1};
    }
    for(ll v : g[u]){
        if(v == p) continue;
        dfs(v, u);
    }
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
        auto pos = lower_bound(bus_at[city].begin(), bus_at[city].end(), time);
        // cerr << (*pos).id;
        if(pos != bus_at[city].end()) ask_bus[(*pos).id].push_back({req, i});
        else ans[i] = {city, -1};
    }
    // lp(i, 1, m){
    //     cerr << i << "\n---->\n";
    //     for(auto j : ask_bus[i]) cerr << '\t' << j.first << ' ' << j.second << '\n';
    //     cerr << '\n';
    // }
    lp(i, 1, m) if(go[i]) g[go[i]].push_back(i);
    sort(bus + 1, bus + 1 + m, cpr_id);
    memset(par, -1, sizeof par);
    lp(i, 1, m) if(!go[i]) dfs(i, -1);
    lp(i, 1, q){
        if(~ans[i].second) cout << ans[i].first << ' ' << ans[i].second << '\n';
        else cout << ans[i].first << '\n';
    }
    // lp(i, 1, m){
    //     cerr << i << '\n';
    //     for(auto j : bus_at[i]){
    //         cerr << j.s << ' ';
    //     }
    //     cerr << '\n';
    // }
}