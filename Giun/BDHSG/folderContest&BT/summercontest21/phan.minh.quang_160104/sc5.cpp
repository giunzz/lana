#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "sc5"
using namespace std;

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

#define refill 10

cll mxn = 23, dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
ll a[mxn][mxn], n, m, dp[mxn][mxn][mxn];

void sol(){
    cin >> n >> m;
    lp(i, 1, n) lp(j, 1, m){
        char c;
        cin >> c;
        if(c == '.') a[i][j] = 0;
        else if(c == '#') a[i][j] = -1;
        else if(c == 'S') a[i][j] = refill;
        else a[i][j] = c - '0';
    }
    memset(dp, -1, sizeof dp);
    queue<pp(pp(ll, ll), ll)> q;
    q.push({{1, 1}, 0});
    dp[1][1][0] = 1;
    while(q.size()){
        ll x = q.front().first.first, y = q.front().first.second, toxic = q.front().second;
        q.pop();
        lp(i, 0, 3){
            ll nx = x + dx[i], ny = y + dy[i], ntoxic = toxic + a[nx][ny];
            if(ntoxic < 0 || a[nx][ny] == refill) ntoxic = 0;
            if(dp[nx][ny][ntoxic] != -1) continue;
            if(!nx || !ny || nx > n || ny > m || a[nx][ny] == -1 || (a[nx][ny] != refill && ntoxic >= 10)){
                dp[nx][ny][ntoxic] = 0;
                continue;
            }
            dp[nx][ny][ntoxic] = 1;
            q.push({{nx, ny}, ntoxic});
        }
    }

    bool res = 0;
    lp(i, 0, 9) if(dp[n][m][i] == 1) res = 1;
    cout << (res ? "possible\n" : "impossible\n");
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    EACHCASE sol();
}