#include <iostream>
#include <queue>
#include <climits>
#define ll long long
#define cll const long long
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
using namespace std;

void file(const string file){
    freopen((file + ".inp").c_str(), "r", stdin);
    freopen((file + ".out").c_str(), "w", stdout);
}

cll maxn = 1e3 + 7;
ll n, m, s, t, a, b, da[maxn] = {0}, db[maxn] = {0};
vec(pp(ll, ll)) g[maxn];

void init(){
    ll u, v, w;
    lp(i, 1, m){
        cin >> u >> v >> w;
        g[u].push_back({w, v});
        g[v].push_back({w, u});
    }
}

void dijkstra(ll r, ll d[]){
    priority_queue<pp(ll, ll), vec(pp(ll, ll)), greater<pp(ll, ll)>> q;
    lp(i, 1, n) d[i] = INT_MAX;
    d[r] = 0;
    q.push({0, r});
    ll u, wu;
    while(q.size()){
        u = q.top().second;
        wu = q.top().first;
        q.pop();
        if(d[u] != wu) continue;
        for(pp(ll, ll) v : g[u]){
            if(d[u] + v.first < d[v.second]) d[v.second] = d[u] + v.first, q.push({d[v.second], v.second});
        }
    }
}

int main(){
    file("games");
    cin >> n >> m >> s >> t >> a >> b;
    init();
    dijkstra(a, da);
    dijkstra(b, db);
    ll ans = min(da[s] + db[t], da[t] + db[s]);
    if(ans >= INT_MAX) cout << -1;
    else cout << ans;
}