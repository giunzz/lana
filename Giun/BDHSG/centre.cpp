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

cll mxn = 3e4 + 7;
ll n, m;
vec(pp(ll, ll)) g[mxn], da, db;

void dijkstra(ll s, vec(pp(ll, ll)) &d){
    lp(i, 1, n) d[i] = {1e18, 1e18};
    d[s] = {0, 1};
    priority_queue<pp(pp(ll, ll), ll), vec(pp(pp(ll, ll), ll)), greater<pp(pp(ll, ll), ll)>> q;
    q.push({d[s], s});
    ll v;
    pp(ll, ll) uv;
    while(q.size()){
        ll u = q.top().second;
        pp(ll, ll) su = q.top().first;
        q.pop();
        if(d[u] != su) continue;
        for(auto i : g[u]){
            ll uv = i.second, sv = su.first + uv, v = i.first;
            if(sv < d[v].first){
                d[v] = {sv, su.second};
                q.push({d[v], v});
            } else if(sv == d[v].first){
                d[v] = {sv, d[v].second + su.second};
                q.push({d[v], v});
            }
        }
    }
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n >> m;
    da.resize(n + 2), db.resize(n + 2);
    lp(i, 1, m){
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    dijkstra(1, da);
    dijkstra(n, db);
    vec(ll) ans;
    lp(i, 1, n){
        if(da[i].first + db[i].first != da[n].first || da[i].second * db[i].second < da[n].second)
            ans.push_back(i);
    }
    // cerr << "1 -> i\n";
    lp(i, 1, n){
        cerr << "n -> " << i << '\n';
        cerr << "Khoang cach : " << db[i].first << '\n' << "So luong : " << db[i].second << '\n';
        cerr << "-------\n";
    }
    cout << ans.size() << '\n';
    for(ll i : ans) cout << i << '\n';
}