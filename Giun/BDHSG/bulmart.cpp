#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "bulmart"
using namespace std;

void OF(){
    freopen(Fname ".inp", "r", stdin);
    freopen(Fname ".out", "w", stdout);
}

cll maxn = 5e3 + 7;
ll n, nstr, minP[maxn][maxn] = {{0}};
vec(ll) g[maxn], bfs[maxn];
vec(pp(ll, ll)) str[maxn];

void initG(){
    ll m;
    scanf("%lld %lld", &n, &m);
    // cin >> n >> m;
    ll u, v;
    while(m--){
        scanf("%lld %lld", &u, &v);
        // cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

#define nb second
#define cost first

void initStr(){
    ll a, b, c;
    // cin >> nstr;
    scanf("%lld", &nstr);
    lp(i, 1, nstr){
        scanf("%lld %lld %lld", &a, &b, &c);
        // cin >> a >> b >> c;
        str[a].emplace_back(c, b);
    }
}

inline void initBfs(ll &r, vec(ll) &x){
    vec(bool) ck(n + 1, 0);
    x.push_back(r);
    ck[r] = 1;
    lp(i, 0, x.size() - 1){
        ll u = x[i];
        for(ll &v : g[u])
            if(!ck[v]){
                ck[v] = 1, minP[r][v] = minP[r][u] + 1;
                x.push_back(v);
            }
    }
}

ll b, t, r;

inline void mg(pp(ll, ll) &s, priority_queue<pp(ll, ll)> &q, ll const &need, ll const &tt){
    ll tmp = min(need - b, s.nb);
    q.push({s.cost, tmp});
    b += tmp;
    t += tmp * s.cost;
}

inline ll sol(ll &pos, ll &need, ll &tt){
    ll i = 0;
    priority_queue<pp(ll, ll)> q; //nhung thang minh chon
    b = 0, t = 0, r = pos;
    for(; i < bfs[pos].size(); ++i){
        for(pp(ll, ll) j : str[bfs[pos][i]]){
            while(q.size() && j.cost < q.top().cost && (b - q.top().nb) + j.nb >= need){
                b -= q.top().nb, t -= q.top().nb * q.top().cost;
                q.pop();
            }
            if(q.empty() || j.cost >= q.top().cost){
                mg(j, q, need, tt);
            } 
            else{
                pp(ll, ll) tmp = q.top(); 
                q.pop();
                b -= tmp.nb; t -= tmp.cost * tmp.nb;
                if(tmp > j) swap(tmp, j);
                mg(tmp, q, need, tt); mg(j, q, need, tt);
            }
            if(b == need && t <= tt) return minP[pos][bfs[pos][i]];
        }
        // if(b == need && t <= tt) return minP[pos][bfs[pos][i]];
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    initG();
    initStr();
    lp(i, 1, n)
        initBfs(i, bfs[i]);
    ll tcs, pos, need, mn;
    // cin >> tcs;
    scanf("%lld", &tcs);
    while(tcs--){
        scanf("%lld %lld %lld", &pos, &need, &mn);
        // cin >> pos >> need >> mn;
        // cout << sol(pos, need, mn) << '\n';
        printf("%lld\n", sol(pos, need, mn));
    }
}

//vo bfs hoac cnp tim khoang cach loc cac cua hang trong khoang cach