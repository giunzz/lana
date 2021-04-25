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

cll mxn = 1e3 + 7, dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
ll n, m, a[mxn][mxn], dp[mxn][mxn];
queue<pp(ll, ll)> q;

#define ONLINE_JUDGE
int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    memset(a, -1, sizeof a);
    cin >> n >> m;
    lp(i, 1, n) lp(j, 1, m){
        cin >> a[i][j];
        dp[i][j] = 1e17;
        if(a[i][j] == 2) q.push({i, j}), dp[i][j] = 0;
    }
    while(q.size()){
        pp(ll, ll) u = q.front();
        q.pop();
        lp(i, 0, 3){
            pp(ll, ll) v = {u.first + dx[i], u.second + dy[i]};
            if(a[v.first][v.second] < 1) continue;
            if(dp[v.first][v.second] > dp[u.first][u.second] + 1) dp[v.first][v.second] = dp[u.first][u.second] + 1, q.push(v);
        }
    }
    ll res = 0;
    lp(i, 1, n) lp(j, 1, m) if(a[i][j]){
        res = max(res, dp[i][j]);
    }
    cout << (res == 1e17 ? -1 : res);
}