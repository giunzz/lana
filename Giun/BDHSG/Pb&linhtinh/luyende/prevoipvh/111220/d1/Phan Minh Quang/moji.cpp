#include <bits/stdc++.h>
#define ll long long
#define cll const long long
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
using namespace std;

void file(const string file){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen((file + ".inp").c_str(), "r", stdin);
    freopen((file + ".out").c_str(), "w", stdout);
}

cll maxn = 3e5 + 7;
ll t, n, k, m, a[maxn], p;
bool d[maxn] = {0};
vec(pp(pp(ll, ll), pp(ll, ll))) e;
vec(pp(ll, ll)) g[maxn];

//sub2
ll dsu[maxn], cnt[maxn];

ll gt(ll u){
    if(dsu[u] == u) return u;
    return dsu[u] = gt(dsu[u]);
}

bool join(ll u, ll v){
    u = gt(u), v = gt(v);
    if(u == v) return 0;
    if(cnt[u] < cnt[v]) swap(u, v);
    cnt[u] += cnt[v];
    dsu[v] = u;
    return 1;
}

void sub2(){
    lp(i, 1, n) dsu[i] = i, cnt[i] = 1;
    ll ans = 0;
    vec(ll) res;
    cin >> p;
    lp(i, 1, p){
        ll u, v, c;
        cin >> u >> v >> c;
        e.push_back({{c, i}, {u, v}});
    }
    sort(e.begin(), e.end());
    for(auto ee : e){
        if(join(ee.second.first, ee.second.second)){
            ans += ee.first.first;
            res.push_back(ee.first.second);
        }
    }
    cout << ans << '\n' << 0 << "\n\n" << res.size() << '\n';
    for(ll i : res) cout << i << ' ';
}

// void sub3(){
//     lp(i, 1, m){
//         ll u, v, c;
//         cin >> u >> v >> c;
//         g[u].push_back({c, v});
//         g[v].push_back({c, u});
//     }
//     cin >> p;
//     lp(i, 1, k){
//         dfs(a[i]);
//     }
// }

int main(){
    file("moji");
    cin >> t >> n >> k;
    lp(i, 1, k){
        cin >> a[i];
        d[a[i]] = 1;
    }
    cin >> m;
    if(m == 0 && k == 1) sub2();
    // else{
    //     sub3();
    // } 
}