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

cll mxn = 507, dx[2][3] = {{0, 1, 1}, {0, 1, 1}}, dy[2][3] = {{1, 0, 1}, {-1, 0, -1}};
ll n, k, a[mxn][mxn];
bool d[2][mxn][mxn] = {{{0}}};
queue<pp(ll, pp(ll, ll))> q[2];

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n >> k;
    lp(i, 0, n + 1) a[i][0] = a[0][i] = a[n + 1][i] = a[i][n + 1] = -1;
    lp(i, 1, k){
        ll x, y;
        cin >> x >> y;
        a[x][y] = -1;
    }
    ll ans = 0;
    d[0][1][1] = d[1][1][n] = 1;
    q[0].push({0, {1, 1}}); q[0].push({1, {1, n}});
    while(q[0].size()){
        ++ans;
        while(q[0].size()){
            ll x = q[0].front().second.first, y = q[0].front().second.second, cur = q[0].front().first;
            q[0].pop();
            q[1].push({cur, {x, y}});
            d[cur][x][y] = 0;
        }
        while(q[1].size()){
            ll x = q[1].front().second.first, y = q[1].front().second.second, cur = q[1].front().first;
            q[1].pop();
            lp(i, 0, 2){
                ll nx = x + dx[cur][i], ny = y + dy[cur][i];
                if(a[nx][ny] == -1 || d[cur][nx][ny]) continue;
                if(d[!cur][nx][ny]){
                    cout << ans;
                    return 0;
                }
                d[cur][nx][ny] = 1;
                q[0].push({cur, {nx, ny}});
            }
        }
    }
}

// #include <bits/stdc++.h>
// #define ll long long
// #define cll const ll
// #define lp(a, b, c) for(ll a = b; a <= c; ++a)
// #define lpd(a, b, c) for(ll a = b; a >= c; --a)
// #define vec(a) vector<a>
// #define pp(a, b) pair<a, b>
// #define EACHCASE lpd(cs, read(), 1)
// #define Fname "f"
// using namespace std;

// template <typename T> inline void Read(T &x){
//     x = 0; char c;
//     while(!isdigit(c = getchar()));
//     do
//     {
//         x = x * 10 + c - '0';
//     } while (isdigit(c = getchar()));
// }

// ll read(){
//     ll tmp;
//     cin >> tmp;
//     return tmp;
// }

// void giuncute(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);
// }

// void OF(){
//     freopen(Fname".inp", "r", stdin);
//     freopen(Fname".out", "w", stdout);
// }

// cll mxn = 507, dx[2][3] = {{0, 1, 1}, {0, 1, 1}}, dy[2][3] = {{1, 0, 1}, {-1, 0, -1}};
// ll n, k, a[mxn][mxn] = {{0}}, ry[2] = {1, 1};
// pp(ll, ll) dp[2][mxn][mxn];

// void sol(ll id){
//     queue<pp(ll, ll)> q;
//     q.push({1, ry[id]});
//     dp[id][1][ry[id]] = {0, 0};
//     while(q.size()){
//         ll x = q.front().first, y = q.front().second;
//         q.pop();
//         lp(i, 0, 2){
//             ll nx = x + dx[id][i], ny = y + dy[id][i];
//             if(a[nx][ny] != -1 && dp[id][nx][ny].first > dp[id][x][y].first + 1){
//                 dp[id][nx][ny].first = dp[id][x][y].first + 1;
//                 q.push({nx, ny});
//             }
//         }
//     } 
//     q.push({1, ry[id]});
//     while(q.size()){
//         ll x = q.front().first, y = q.front().second;
//         q.pop();
//         bool ok = 0;
//         lp(i, 0, 1){
//             ll nx = x + dx[id][i], ny = y + dy[id][i];
//             if(a[nx][ny] != -1 && dp[id][nx][ny].second == 1e17){
//                 dp[id][nx][ny].second = dp[id][x][y].second + 1;
//                 ok = 1;
//                 q.push({nx, ny});
//             }
//         }
//         if(!ok){
//             ll nx = x + dx[id][2], ny = y + dy[id][2];
//             if(a[nx][ny] != -1 && dp[id][nx][ny].second == 1e17){
//                 dp[id][nx][ny].second = dp[id][x][y].second + 1;
//                 q.push({nx, ny});
//             }
//         }
//     } 
// }

// int main(){
//     giuncute();
//     #ifndef ONLINE_JUDGE
//     OF();
//     #endif
//     cin >> n >> k;
//     ry[1] = n;
//     lp(k, 0, 1) lp(i, 1, n) lp(j, 1, n) dp[k][i][j] = {1e17, 1e17};
//     lp(i, 0, n + 1) a[i][0] = a[0][i] = a[n + 1][i] = a[i][n + 1] = -1;
//     lp(i, 1, k){
//         ll x, y;
//         cin >> x >> y;
//         a[x][y] = -1;
//     }
//     sol(0); sol(1);
//     ll ans = 1e17;
//     lp(i, 1, n) lp(j, 1, n){
//         if(dp[0][i][j].second < dp[1][i][j].first || dp[1][i][j].second < dp[0][i][j].first) continue;
//         if(dp[0][i][j].first <= dp[1][i][j].first && dp[1][i][j].first <= dp[0][i][j].second) ans = min(ans, dp[1][i][j].first);
//         if(dp[1][i][j].first <= dp[0][i][j].first && dp[0][i][j].first <= dp[1][i][j].second) ans = min(ans, dp[0][i][j].first);
//     }
//     cout << ans;
// }