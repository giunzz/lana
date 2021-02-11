#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "bitree"
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

cll maxn = (1LL << 16);
ll n, g[maxn], node, dp[maxn] = {0};
bool ans = 1, d[maxn] = {0};
ifstream getOut(Fname".out");

void buildtree(ll u){
    if(u >= (1LL << n)) return;
    getOut >> g[u];
    if(d[g[u]] || g[u] > node) ans = 0;
    d[g[u]] = 1;
    buildtree(u << 1);
    buildtree(u << 1 | 1);
}

void dfs(ll u, ll fl){
    dp[u] = g[u];
    if((u << 1) > node) return;
    dfs(u << 1, fl + 1);
    dfs(u << 1 | 1, fl + 1);
    if(abs(dp[u << 1] - dp[u << 1 | 1]) != (1LL << fl)){
        ans = 0;
    }
    dp[u] += dp[u << 1] + dp[u << 1 | 1];
}

#define ONLINE_JUDGE
int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    ifstream getInp(Fname".inp");
    getInp >> n;
    getInp.close();
    node = (1LL << n) - 1;
    buildtree(1);
    lp(i, 1, node) if(!d[i]) ans = 0;
    dfs(1, 0);
    cerr << ans;
}