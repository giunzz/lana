#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "f"
// #define Fname "fair"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll maxn = 1e3 + 7;
ll m, n, a[maxn][maxn], dp[maxn][maxn] = {{0}}, dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
bool d[maxn][maxn] = {{0}};

void dfs(ll x, ll y){
    if(y == n){dp[x][y] = 0; return;}
    ll res = 1e18;
    lp(i, 0, 3){
        ll nx = x + dx[i], ny = y + dy[i];
        if(!d[nx][ny]){
            d[nx][ny] = 1;
            dfs(nx, ny);
        }
        if(a[x][y] == a[nx][ny]) res = min(res, dp[nx][ny]);
        else res = min(res, dp[nx][ny] + 1);
    }
    dp[x][y] = res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> m >> n;
    lp(i, 0, m + 1) lp(j, 0, n + 1){
        dp[i][j] = 1e18;
        a[i][j] = -1;
        d[i][j] = 1;
    }
    lp(i, 1, m) lp(j, 1, n) cin >> a[i][j], d[i][j] = 0;
    d[1][1] = 1;
    dfs(1, 1);
    ll ans = 1e18;
    lp(i, 1, m){
        lp(j, 1, n) cerr << dp[i][j] << ' ';
        cerr << endl;
    }
    lp(i, 1, m) ans = min(dp[i][1], ans);
    cout << (ans + 1);   
}