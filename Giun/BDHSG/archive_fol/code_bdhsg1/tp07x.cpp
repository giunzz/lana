#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "tp07x"
using namespace std;

void OF(){
    freopen(Fname ".inp", "r", stdin);
    freopen(Fname ".out", "w", stdout);
}

cll maxn = 1e5 + 7;
ll n, ans = 0, tc[maxn];
vec(ll) g[maxn];
bool d[maxn] = {0};
// pp(ll, ll) tmp[maxn];

void init(){
    ll u, v;
    cin >> n;
    lp(i, 1, n - 1){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

// void solve(){
//     priority_queue<pp(ll, ll)> q;
//     lp(i, 1, n){
//         // tmp[i] = {g[i].size(), i};
//         tc[i] = g[i].size();
//         // cerr << i << ' ' << tc[i] << '\n';
//         q.push({tc[i], i});
//     }
//     ll cu, u;
//     while(q.size()){
//         u = q.top().second;
//         cu = q.top().first;
//         q.pop();
//         if(cu != tc[u] || !tc[u]) continue;
//         d[u] = 1;
//         ++ans;
//         // cerr << u << ' ' << cu << '\n';
//         for(ll v : g[u]){
//             if(d[v]) continue;
//             d[v] = 1;
//             // ++ans;
//             --tc[v];
//             q.push({tc[v], v});
//             // for(ll z : g[v]) {--tc[z]; if(u != z) q.push({tc[z], z});}
//         }
//     }
//     // sort(tmp + 1, tmp + 1 + n);
//     // lpd(i, n, 1){
//     //     bool ck = 0;
//     //     d[tmp[i].second] = 1;
//     //     for(ll v : g[tmp[i].second]) {
//     //         if(!d[v]) d[v] = 1, ck = 1;
//     //     }
//     //     if(ck) ++ans;
//     // }
// }

pp(ll, ll) dfs(ll u){
    pp(ll, ll) tmp;
    ll tmp0 = 0, tmp1 = 0;
    for(ll v : g[u]){
        if(d[v]) continue;
        d[v] = 1;
        tmp = dfs(v);
        tmp0 += min(tmp.second, tmp.first), tmp1 += tmp.first;
    }
    ++tmp0;
    return make_pair(tmp0, tmp1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    init();
    // solve();
    // dfs(1);
    d[1] = 1;
    pp(ll, ll) tmp = dfs(1);
    cout << min(tmp.first, tmp.second);
}