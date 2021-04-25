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

cll mxn = 1e3 + 7, dx[] = {-1, -1, 0, 1, 1, 1, 0, -1}, dy[] = {0, -1, -1, -1, 0, 1, 1, 1};
ll n, m, a[mxn][mxn], dp[mxn][mxn] = {{0}}, res[30];
queue<pp(ll, ll)> q[2];
bool d[mxn][mxn] = {{0}};

#define ONLINE_JUDGE
int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n >> m;
    memset(a, -1, sizeof a);
    lp(i, 1, 29) res[i] = 1e17;
    lp(i, 1, n) lp(j, 1, m){
        dp[i][j] = 1e17;
        char c;
        cin >> c;
        if(c == '.') a[i][j] = 0, q[0].push({i, j}), dp[i][j] = -1;
        else a[i][j] = c - 'A' + 1;
    }
    while(q[0].size()){
        while(q[0].size()){
            pp(ll, ll) u = q[0].front();
            q[0].pop();
            lp(i, 0, 7){
                pp(ll, ll) v = {u.first + dx[i], u.second + dy[i]};
                if(a[v.first][v.second] == -1) continue;
                if(a[u.first][u.second] == a[v.first][v.second]){
                    if(dp[v.first][v.second] > dp[u.first][u.second]) dp[v.first][v.second] = dp[u.first][u.second], q[0].push(v);
                } else{
                    if(dp[v.first][v.second] > dp[u.first][u.second] + 1) dp[v.first][v.second] = dp[u.first][u.second] + 1, q[1].push(v);
                }
                res[a[v.first][v.second]] = min(res[a[v.first][v.second]], dp[v.first][v.second]);
            } 
        }
        swap(q[0], q[1]);
    }
    lp(i, 1, 29) if(res[i] != 1e17) cout << (char)('A' + i - 1) << ' ' << res[i] << '\n';
}