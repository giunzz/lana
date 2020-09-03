#include <iostream>
#include <queue>
#include <climits>
#define ll long long
#define cll const long long
#define lp(a, b, c) for (ll a  =b; a <= c; a++)
#define lpd(a, b, c) for (ll a  =b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
using namespace std;

void File(const string ff){
    freopen((ff + ".inp").c_str(), "r", stdin);
    freopen((ff + ".out").c_str(), "w", stdout);
}

cll maxn = 1e5 + 7;
ll n, m, k, d1[maxn], dn[maxn];
vector<pp(ll, ll)> g[maxn];
pp(ll, ll) d[107], tmp[maxn];

void init(){
    ll u, v, c;
    lp(i, 1, m){
        cin >> u >> v >> c;
        g[u].push_back({c, v});
    }
}

void dijkstra(ll r, ll d[]){
    priority_queue<pp(ll, ll), vec(pp(ll, ll)), greater<pp(ll, ll)>> q;
    lp(i, 1, n) d[i] = 1e10;
    d[r] = 0;
    q.push({0, r});
    ll u, wu;
    while(q.size()){
        u = q.top().second;
        wu = q.top().first;
        q.pop();
        if(d[u] != wu) continue;
        for(pp(ll, ll) v : g[u])
            if(v.first + d[u] < d[v.second]) d[v.second] = v.first + d[u], q.push({d[v.second], v.second}); 
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // File("diemhen");
    cin >> n >> m >> k;
    init();
    dijkstra(1, d1);
    dijkstra(n, dn);
    lp(i, 1, n){
        tmp[i].first = d1[i];
    }
    lp(i, 1, n){
        tmp[i].second = dn[i];
    }
    ll a, b, ans;
    lp(i, 1, k){
        ans = LLONG_MAX;
        cin >> a >> b;
        lp(j, 1, n) ans = min(ans, a * tmp[j].first + b * tmp[j].second);
        cout << ans << endl;
    } 
}