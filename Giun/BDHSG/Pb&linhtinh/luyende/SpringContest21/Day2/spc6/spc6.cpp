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

cll maxn = 43;
ll dp[maxn][maxn][maxn][maxn], a[maxn][maxn], n, m, so[200],
dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
pp(ll, ll) p[4];
bool ok[maxn][maxn][maxn][maxn];

void sol1(ll x1, ll y1, ll x2, ll y2){
    queue<vec(ll)> q;
    q.push({x1, y1, x2, y2});
    while(q.size()){
        x1 = q.front()[0], y1 = q.front()[1], x2 = q.front()[2], y2 = q.front()[3];
        q.pop();
        lp(i, 0, 3){
            lp(j, 0, 3){
                ll nx1 = x1 + dx[i], ny1 = y1 + dy[i], nx2 = x2 + dx[j], ny2 = y2 + dy[j];
                if(a[nx1][ny1] == -1 || a[nx2][ny2] == -1) continue;
                if(nx1 ==  x2 && ny1 == y2 && nx2 == x1 && ny2 == y1) continue;
                if(nx1 == nx2 && ny1 == ny2) continue;
                // if(ok[nx1][ny1][nx2][ny2]) continue;
                // ok[nx1][ny1][nx2][ny2] = 1;
                if(dp[nx1][ny1][nx2][ny2] <= dp[x1][y1][x2][y2] + 1) continue;
                dp[nx1][ny1][nx2][ny2] = dp[x1][y1][x2][y2] + 1;
                // sol1(nx1, ny1, nx2, ny2);
                q.push({nx1, ny1, nx2, ny2});
                // ok[nx1][ny1][nx2][ny2] = 0;
                // if(tmp != -2) res = min(res, sol1(nx1, ny1, nx2, ny2));
            }
        }
    }
    // if(res == LLONG_MAX) res = -2;
    // else ++res;
    // return dp[x1][y1][x2][y2] = res;
}

int main(){
    file("spc6");
    ll cs;
    so['A'] = 0, so['a'] = 1, so['B'] = 2, so['b'] = 3;
    cin >> cs;
    while(cs--){
        memset(a, -1, sizeof(a)); memset(dp, -1, sizeof(dp));
        // cerr << dp[40][40][40][40];
        cin >> n >> m;
        lp(i, 1, n) lp(j, 1, m) lp(ii, 1, n) lp(jj, 1, m) dp[i][j][ii][jj] = LLONG_MAX;
        lp(i, 1, n){
            lp(j, 1, m){
                char c;
                cin >> c;
                if(c == '.') a[i][j] = 0;
                else if(c != '#'){
                    p[so[c]] = {i, j};
                    a[i][j] = 0;
                }
                // cerr << a[i][j] << ' ';
            }
            // cerr << '\n';
        }
        dp[p[0].first][p[0].second][p[2].first][p[2].second] = 0;
        // ok[p[1].first][p[1].second][p[3].first][p[3].second] = 1;
        // cerr << p[3].first << ' ' << p[3].second;
        // cerr << dp[1][1][1][2];
        sol1(p[0].first, p[0].second, p[2].first, p[2].second);
        ll tmp = dp[p[1].first][p[1].second][p[3].first][p[3].second];
        if(tmp == LLONG_MAX) cout << "NO SOLUTION\n";
        else cout << tmp << '\n';
    }
}