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

cll maxn = 1e4 + 7, MOD = 1e10;
ll n, m, dp[maxn] = {0};
bool d[maxn] = {0};
vec(ll) g[maxn];

ll dfs(ll u){
    if(u == 2) return dp[u] = 1;
    if(dp[u]) return dp[u];
    ll res = 0;
    for(ll v : g[u]){
        if(d[v]){
            if(dp[v]){
                if(dp[v] == -1){
                    return dp[u] = dp[v];
                } else if(dp[v] > 0){
                    res += dp[v];
                }
            }
            else{
                
            }
        }
    }
} 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n >> m;
    lp(i, 1, m){
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    dfs(1);
}

// cll maxn = 1e4 + 7;
// ll n, m, dp[maxn] = {0}, num[maxn] = {0}, low[maxn] = {0}, cnt = 0, tt[maxn] = {0}, co = 0;
// vec(ll) g[maxn];
// ll ds[maxn] = {0};

// stack<ll> st;

// void visit(ll u){
//     low[u] = num[u] = ++cnt;
//     st.push(u);
//     for(ll v : g[u]){
//         if(num[v]){
//             low[u] = min(low[u], num[v]);
//         }
//         else{
//             visit(v);
//             low[u] = min(low[u], low[v]);
//         }
//     }
//     if(num[u] == low[u]){
//         ll v;
//         ++co;
//         do{
//             v = st.top();
//             st.pop();
//             num[v] = low[v] = LLONG_MAX;
//             ds[v] = co;
//             ++tt[co];
//         }while(v != u);
//     }
// }

// bool dd[maxn] = {0};
// vec(ll) ng[maxn];

// void dfs(ll u){
//     for(ll v : g[u]){
//         if(num[u] != num[v]) ng[num[u]].push_back(num[v]);
//         if(dd[v]) continue;
//         dd[v] = 1;
//         dfs(v);
//     }
// }

// ll bg, ed;
// bool md = 0;
// cll MOD = 1e10;

// ll sol(ll u){
//     // if(tt[u] != 1) return -1;
//     if(u == ed) return dp[u] = 1;
//     if(dp[u]) return dp[u];
//     ll aa = 0;
//     bool ok = 1, mm = 0;
//     for(ll v : ng[u]){
//         ll tmp = sol(v);
//         if(tmp > 0 && tt[v] > 1) ok = 0;
//         if(tmp == -1) ok = 0;
//         if(tmp > 0) aa += tmp;
//         if(aa >= MOD) mm = 1, aa = aa % MOD; 
//     }
//     if(aa == 0) ok = 0;
//     if(ok) {if(mm) md = mm; return dp[u] = aa;} 
//     return dp[u] = -1;
// }

// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);
//     OF();
//     cin >> n >> m;
//     lp(i, 1, m){
//         ll u, v;
//         cin >> u >> v;
//         g[u].push_back(v);
//     }
//     lp(i, 1, n) if(!num[i]) visit(i);
//     lp(i, 1, n) num[i] = ds[i];
//     // lp(i, 1, n) cerr << i << ' ' << num[i] << ' ' << tt[i] << '\n';
//     lp(i, 1, n) if(!dd[i]) dfs(i);
//     // lp(i, 1, co){
//     //     for(ll v : ng[i]) cerr << i << ' ' << v << '\n';
//     // }
//     bg = num[1], ed = num[2];
//     ll ans = sol(bg);
//     if(ans == -1 || tt[bg] > 1) cout << "inf";
//     else 
//     {
//         if(md){
//             string res = to_string(ans);
//             while(res.size() < 9) res = '0' + res;
//             cout << res;
//         }
//         else cout << ans;
//     }
// }