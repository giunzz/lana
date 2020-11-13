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

cll maxn = 5e3 + 7;
ll n, k, f[maxn];
pp(ll, ll) a[maxn];
vec(ll) g[maxn];

#define c first
#define d second

#define fi first
#define se second.first.first
#define th second.first.second
#define fo second.second

void init(){
    ll u, v;
    lp(i, 1, k){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

void dijkstra(ll r){
    priority_queue<pp(ll, pp(pp(ll, ll), ll)), vec(pp(ll, pp(pp(ll, ll), ll))), greater<pp(ll, pp(pp(ll, ll), ll))>> pq;
    pq.push({0, {{0, r}, r}});
    lp(i, 1, n) f[i] = LLONG_MAX;
    f[r] = 0;
    while(pq.size()){
        pp(ll, pp(pp(ll, ll), ll)) u = pq.top();
        pq.pop();
        if(f[u.fo] != u.first) continue;
        for(ll v : g[u.fo]){
            ll rt = u.th, sp = u.se, cs = u.fi, tmp;
            ll nrt = rt, nsp = sp, ncs = cs;
            if(sp >= a[rt].d){
                tmp = cs + a[u.fo].c;
                nrt = u.fo;
                nsp = 1;
                cs = tmp;
                if(cs < f[v]) f[v] = cs, pq.push({cs, {{nsp, nrt}, v}});
            } else{
                ncs = cs + a[u.fo].c;
                // if(ncs < cs){
                //     nrt = u.fo;
                //     nsp = 1;
                // }
                ncs = cs, nsp = 1 + sp;
                if(ncs < f[v]) f[v] = ncs, pq.push({ncs, {{nsp, nrt}, v}});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n >> k;
    lp(i, 1, n){
        cin >> a[i].c >> a[i].d;
    }
    init();
    dijkstra(1);
    cout << f[n];
}