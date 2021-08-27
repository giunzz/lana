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

cll mxn = 1e5 + 4;
ll n, m, indeg[mxn], num[mxn];
vec(pp(pp(ll ,ll), pp(ll, ll))) edge;
vec(pp(ll, ll)) g[mxn];
vec(ll) topo;

bool check(ll id){
    lp(i, 1, n) indeg[i] = 0;
    topo.clear();
    queue<ll> q;
    ll idval = (id == -1 ? 0 : edge[id].first.first);
    lp(i, id + 1, m - 1) if(edge[i].first.first > idval) ++indeg[edge[i].second.second];
    lp(i, 1, n) if(!indeg[i]) q.push(i), topo.push_back(i);
    while(q.size()){
        ll u = q.front();
        q.pop();
        for(pp(ll, ll) v : g[u]){
            if(v.second > idval && !--indeg[v.first]){
                topo.push_back(v.first);
                q.push(v.first);
            }
        }
    } 
    return topo.size() == n;
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n >> m;
    lp(i, 1, m){
        ll u, v, c;
        cin >> u >> v >> c;
        g[u].push_back({v, c});
        edge.push_back({{c, i}, {u, v}});
    }
    sort(edge.begin(), edge.end());
    ll l = -1, r = m - 1, ans;
    vec(ll) topo_ans;
    while(l <= r){
        ll mid = (l + r) >> 1;
        if(check(mid)) topo_ans = topo, ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    if(ans == -1){
        cout << "0 0";
        return 0;
    }
    cout << edge[ans].first.first << ' ';
    lp(i, 0, n - 1) num[topo_ans[i]] = i;
    vec(ll) res;
    lp(i, 0, m - 1) if(edge[i].first.first <= edge[ans].first.first && num[edge[i].second.first] > num[edge[i].second.second])
        res.push_back(edge[i].first.second);
    cout << res.size() << '\n';
    for(ll i : res) cout << i << ' ';
}