#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "bookex"
// #define Fname "f"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll maxn = 1e6 + 7;
ll n, dp[maxn] = {0}, a[maxn][1];
bool d[maxn] = {0}; 

inline void dfs(ll u, ll &cnt){
    ll v = a[u][0];
    ++cnt;
    if(!d[v]){
        d[v] = 1;
        dfs(v, cnt);
    }
    dp[u] = cnt;
}

ll tmp;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n;
    lp(u, 1, n)
        cin >> a[u][0];
    lp(i, 1, n) if(!d[i]){
        d[i] = 1;
        dfs(i, tmp = 0);
    }
    lp(i, 1, n) cout << dp[i] << ' ';
}