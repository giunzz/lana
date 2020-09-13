#include <bits/stdc++.h>
#define ll long long
#define cll const long long
#define lp(a, b, c) for (ll a  =b; a <= c; a++)
#define lpd(a, b, c) for (ll a  =b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
using namespace std;
#define ff "b"

void File(){
    freopen(ff".inp", "r", stdin);
    freopen(ff".out", "w", stdout);
}

cll maxn = 1e5 + 7;
ll n, m, k;
vec(pp(ll, ll)) g[maxn];

void init(){
    ll u, v, c;
    lp(i, 1, m){
        cin >> u >> v >> c;
        g[u].push_back({c, v});
        g[v].push_back({c, u});
    }
}

pp(ll, ll) d[maxn];
#define val first
#define cnt second

void dijkstra(){
    priority_queue<pp(ll, ll), vec(pp(ll, ll)), greater<pp(ll, ll)>> q;
    lp(i, 1, n) d[i] = {LLONG_MAX, INT_MAX};
    d[1] = {0, 1};
    q.push({0, 1});
    ll u, wu;
    while(q.size()){
        u = q.top().second;
        wu = q.top().first;
        q.pop();
        if(wu != d[u].val) continue;
        for(pp(ll, ll) v : g[u]){
            if(d[u].val + v.first < d[v.second].val){
                d[v.second] = {d[u].val + v.first, d[u].cnt + 1};
                q.push({d[v.second].val, v.second});
            }
            else if (d[u].val + v.first == d[v.second].val && d[u].cnt + 1 < d[v.second].cnt){
                d[v.second] = {d[u].val + v.first, d[u].cnt + 1};
                q.push({d[v.second].val, v.second});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    File();
    cin >> n >> m >> k;
    init();
    dijkstra();
    cout << d[n].val << ' ';
    if(d[n].cnt <= k) {
        cout << "YES";
    }
    else cout << "NO";
}