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

cll maxn = 507;
ll n, m, dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1}, a[maxn][maxn] = {{0}}, d[3][4] = {{0, 0, 0, 0}, {3, 2, 1, 0}, {1, 0, 3, 2}},
dp[maxn][maxn][4] = {{{0}}};
bool dd[maxn][maxn] = {{0}};

inline ll dfs(ll x, ll y, ll h, ll const &rx, ll const &ry){
    if(x == rx && y == ry) return INT_MAX;
    if(x == 0 || x == n + 1 || y == 0 || y == m + 1 || !a[x][y]) return 0;
    if(dp[x][y][h]) return dp[x][y][h];
    if(a[x][y] == -1){
        dp[x][y][h] = dfs(x + dx[h], y + dy[h], h, rx, ry) + 1;
    }
    else{
        ll nh = d[a[x][y]][h];
        dp[x][y][h] = dfs(x + dx[nh], y + dy[nh], nh, rx, ry) + 1;
    }
    return dp[x][y][h];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n >> m;
    lp(i, 1, n){
        lp(j, 1, m){
            char c;
            cin >> c;
            if(c == '.') a[i][j] = -1;
            else if(c == '/') a[i][j] = 1;
            else if(c == '\\') a[i][j] = 2;
        }
    }
    ll x, y;
    cin >> x >> y;
    ll ans = LLONG_MIN;
    dd[x][y] = 1;
    lp(i, 0, 3) ans = max(ans, dfs(x + dx[i], y + dy[i], i, x, y) + 1);
    if(ans < INT_MAX) cout << ans;
    else cout << "Voyager";
}