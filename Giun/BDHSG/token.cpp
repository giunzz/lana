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

void giuncute(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

cll mxn = 2e5 + 4;
ll n, tmp, ans[mxn], tot[mxn];
vec(ll) g[mxn];

inline void dfs(ll u){
    tot[u] = 0, ans[u] = 1;
    for(ll v : g[u]){
        dfs(v);
        ans[u] += ans[v], tot[u] += tot[v] + 1;
    }
    ans[u] += tot[u];
}

int main(){
    // cin >> n;
    scanf("%lld", &n);
    lp(i, 2, n){
        scanf("%lld", &tmp);
        g[tmp].push_back(i);
    }
    dfs(1);
    lp(i, 1, n) printf("%lld ", ans[i]);
}