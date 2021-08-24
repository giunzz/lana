#include<bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "vluoi"
#pragma GCC optimize("Ofast")
using namespace std;

cll mxn = 1e3 + 2, dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
ll n, m, a[mxn][mxn] = {{0}}, tot[mxn * mxn] = {0}, ti = 0, d[mxn][mxn] = {{0}}, curcol, dp[mxn][mxn];

void bfs(ll xr, ll yr){
    d[xr][yr] = ++ti;
    tot[ti] = 1;
    curcol = a[xr][yr];
    queue<pp(ll, ll)> q;
    q.push({xr, yr});
    while(q.size()){
        ll x = q.front().first, y = q.front().second;
        q.pop();
        lp(i, 0, 3){
            ll nx = x + dx[i], ny = y + dy[i];
            if(a[nx][ny] == curcol && !d[nx][ny]){
                d[nx][ny] = ti;
                ++tot[ti];
                q.push({nx, ny});
            }
        }
    }
}

void dijk(){
    lp(i, 1, n) lp(j, 1, m) dp[i][j] = 1e18;
    dp[1][1] = 0;
    priority_queue<pp(ll,  pp(ll, ll)), vec(pp(ll, pp(ll, ll))), greater<pp(ll, pp(ll, ll))>> q;
    q.push({0, {1, 1}});
    while(q.size()){
        ll dis = q.top().first, x = q.top().second.first, y = q.top().second.second;
        q.pop();
        if(dis != dp[x][y]) continue;
        if(x == n && y == m) break;
        lp(i, 0, 3){
            ll nx = x + dx[i], ny = y + dy[i];
            if(!nx || !ny || nx > n || ny > m) continue;
            if((a[x][y] == a[nx][ny] || a[nx][ny] == 1) && dp[x][y] < dp[nx][ny]){
                dp[nx][ny] = dp[x][y];
                q.push({dp[nx][ny], {nx, ny}});
            } else if(a[x][y] != a[nx][ny] && dp[x][y] + a[nx][ny] * tot[d[nx][ny]] < dp[nx][ny]){
                dp[nx][ny] = dp[x][y] + a[nx][ny] * tot[d[nx][ny]];
                q.push({dp[nx][ny], {nx, ny}});
            }
        }
    }
//    cout << dp[n][m];
    printf("%lld", dp[n][m]);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".ans", "w", stdout);
//    cin >> n >> m;
    scanf("%lld %lld", &n, &m);
    lp(i, 1, n) lp(j, 1, m) scanf("%lld", &a[i][j]);
    lp(i, 1, n) lp(j, 1, m)
        if(!d[i][j]) bfs(i, j);
    dijk();
}
