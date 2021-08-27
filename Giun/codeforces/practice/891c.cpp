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

cll mxn = 5e5 + 3;
ll n, m, q, par[mxn], par1[mxn], cur[mxn] = {0}, ti = 0;
pp(pp(ll, ll), ll) edge[mxn];
vec(pp(ll, ll)) ew[mxn], query[mxn];
bool wa[mxn] = {0};

ll _get(ll u){
    return par[u] = (par[u] == u ? u : _get(par[u]));
}

ll _get1(ll u){
    if(cur[u] != ti) cur[u] = ti, par1[u] = par[u];
    return par1[u] = (par1[u] == u ? u : _get1(par1[u]));
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n >> m;
    lp(i, 1, m){
        cin >> edge[i].first.first >> edge[i].first.second >> edge[i].second;
        ew[edge[i].second].push_back(edge[i].first);
    }
    cin >> q;
    lp(i, 1, q){
        ll k, id;
        cin >> k;
        lp(j, 1, k){
            cin >> id;
            query[edge[id].second].push_back({i, id});
        }
    }
    lp(i, 1, n) par[i] = i;
    lp(i, 0, 5e5){
        lp(j, 0, (ll)query[i].size() - 1){
            // cerr << i << ' ' << query[i].size() << '\n';
            _get(edge[query[i][j].second].first.first);
            _get(edge[query[i][j].second].first.second);
        }
        lp(j, 0, (ll)query[i].size() - 1){
            if(!j || query[i][j].first != query[i][j - 1].first) ++ti;
            ll u = edge[query[i][j].second].first.first, v = edge[query[i][j].second].first.second;
            if((u = _get1(u)) == (v = _get1(v))) wa[query[i][j].first] = 1;
            par1[u] = v;
        }
        for(pp(ll, ll) e : ew[i]) par[_get(e.first)] = _get(e.second);
    }
    lp(i, 1, q) cout << (wa[i] ? "NO\n" : "YES\n"); 
}