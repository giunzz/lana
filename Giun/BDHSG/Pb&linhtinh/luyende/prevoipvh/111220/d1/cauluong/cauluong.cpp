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

cll maxn = 1503, MOD = 998244353;
ll n, m, a[maxn][maxn] = {{0}}, cnt[maxn][maxn] = {{0}}, dp[maxn][maxn] = {{0}}, f[maxn][maxn], res[maxn][maxn] = {{0}};
vec(ll) g[maxn];
vec(pp(ll, pp(ll, ll))) e;

void dj(ll &r){ 
    priority_queue<pp(ll, ll), vec(pp(ll,  ll)), greater<pp(ll, ll)>> q;
    q.push({0, r});
    f[r][r] = 0;
    dp[r][r] = 1;
    while(q.size()){
        ll u = q.top().second, cu = q.top().first;
        q.pop();
        if(f[r][u] != cu) continue;
        for(ll v : g[u]){
            if(cu + a[u][v] < f[r][v]){
                f[r][v] = cu + a[u][v];
                (dp[r][v] = dp[r][u] * cnt[u][v]) %= MOD;
                q.push({f[r][v], v});
            }
            else if(cu + a[u][v] == f[r][v])
                (dp[r][v] += dp[r][u] * cnt[u][v]) %= MOD;
        }
    }
}

int main(){
    file("cauluong");
    ll cs;
    cin >> cs >> n >> m;
    lp(i, 1, n) lp(j, 1, n) a[i][j] = f[i][j] = LLONG_MAX;
    lp(i, 1, m){
        ll u, v, c;
        cin >> u >> v >> c;
        e.push_back({c, {u, v}});
        if(a[i][j] == LLONG_MAX) g[u].push_back(v), g[v].push_back(u);
        if(c < a[u][v]){
            a[u][v] = a[v][u] = c;
            cnt[u][v] = cnt[v][u] = 1;
        }
        else if(c == a[u][v]) ++cnt[u][v], ++cnt[v][u];
    }
    lp(i, 1, n) dj(i);
    lp(i, )
    // for(auto i : e){
    //     if()
    // }
}