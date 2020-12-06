#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define pp(a, b) pair<a, b>
#define vec(a) vector<a>
#define vecite(a) vector<a>::iterator
#define fi first
#define se second
#define mp(a, b) map<a, b>
#define setE(a, b) fill_n(a, sizeof(a)/sizeof(a[0]), b)
#define st(a) system((a).c_str());
using namespace std;
cll MOD = 1e9 + 7;
const double esf = 1e-9;
const string tenfile = "restoring";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cll maxn = 307;
ll n, ans = 0;
vec(pp(ll, pp(ll, ll))) e;
vec(pp(ll, ll)) g[maxn];

struct disjointset{
    vec(ll) f, cnt;
    ll t;
    disjointset(ll _t){
        this -> t = _t;
        cnt.assign(_t + 7, 1);
        f.resize(_t + 7);
        lp(i, 0, _t - 1) f[i] = i;
    }
    ll get(ll u){
        if(u == f[u]) return u;
        return f[u] = get(f[u]);
    }
    bool join(ll u, ll v){
        u = get(u), v = get(v);
        if(u == v) return 0;
        if(cnt[u] < cnt[v]) swap(u, v);
        cnt[u] += cnt[v];
        f[v] = u;
        return 1;
    }
};

ll dijkstra(ll ru, ll rv){
    vector<ll> f;
    f.assign(n + 7, LLONG_MAX);
    f[ru] = 0;
    priority_queue<pp(ll, ll), vec(pp(ll, ll)), greater<pp(ll, ll)>> q;
    q.push({0, ru});
    while(q.size()){
        ll cu = q.top().first, u = q.top().second;
        q.pop();
        if(f[u] != cu) continue;
        if(u == rv) break;
        for(pp(ll, ll) v : g[u]){
            if(cu + v.first < f[v.second]){
                f[v.second] = cu + v.first;
                q.push({f[v.second], v.second});
            }
        }
    }
    return f[rv];
}

int main(){
    opt;
    // file;
    cin >> n;
    lp(i, 1, n) lp(j, 1, n){
        ll num;
        cin >> num;
        if(i >= j) continue;
        e.push_back({num, {i, j}});
    }
    sort(e.begin(), e.end());
    disjointset dis(n);
    ll cnt = 0;
    for(pp(ll, pp(ll, ll)) &ee : e){
        if(dis.join(ee.second.first, ee.second.second)){
            g[ee.second.first].push_back({ee.first, ee.second.second});
            g[ee.second.second].push_back({ee.first, ee.second.first});
            ans += ee.first;
            ++cnt;
        }
        else{
            ll dj = dijkstra(ee.second.first, ee.second.second);
            if(dj > ee.first){
                g[ee.second.first].push_back({ee.first, ee.second.second});
                g[ee.second.second].push_back({ee.first, ee.second.first});
                ans += ee.first;
            }
            else if(dj < ee.first){
                cout << "-1";
                return 0;
            }
        }
        // if(cnt == n - 1) break;
    }
    cout << ans;
}
