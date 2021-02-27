// #include <bits/stdc++.h>
#include <cstdio>
#include <queue>
#include <climits>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "fair"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll mxn = 1e3 + 2;
ll a[mxn][mxn], n, m, dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1}, dp[mxn][mxn];

void sol(){
    queue<pp(ll, pp(ll, ll))> q[2];
    lp(i, 1, n) lp(j, 1, m) dp[i][j] = LLONG_MAX;
    lp(i, 1, n) q[0].push({dp[i][1] = 1, {i, 1}});
    while(q[0].size()){
        while(q[0].size()){
            ll x = q[0].front().second.first, y = q[0].front().second.second, w = q[0].front().first;
            q[0].pop();
            if(dp[x][y] != w) continue;
            lp(i, 0, 3){
                ll nx = x + dx[i], ny = y + dy[i];
                if(a[nx][ny] == a[x][y]){
                    if(dp[nx][ny] > dp[x][y]){
                        dp[nx][ny] = dp[x][y];
                        q[0].push({dp[nx][ny], {nx, ny}});
                    }
                }
                else{
                    if(dp[nx][ny] > dp[x][y] + 1) dp[nx][ny] = dp[x][y] + 1, q[1].push({dp[nx][ny], {nx, ny}});
                }
            }
        }
        swap(q[0], q[1]);
    }
    ll ans = LLONG_MAX;
    lp(i, 1, n) ans = min(ans, dp[i][m]);
    printf("%lld", ans);
}

int main(){
#ifndef ONLINE_JUDGE
    OF();
#endif
    scanf("%lld %lld", &n, &m);
    lp(i, 1, n) lp(j, 1, m) scanf("%lld", &a[i][j]);
    sol();
}