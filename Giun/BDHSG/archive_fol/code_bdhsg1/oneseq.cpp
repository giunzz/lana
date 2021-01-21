#include<bits/stdc++.h>
#define ll long long
#define cll const ll
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
using namespace std;

void file(const string s){
    freopen((s + ".inp").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

cll maxn = 1e3 + 7;
ll n, m, a[maxn][maxn], dp[maxn][maxn];

// void bfs(){
//     queue<pp(ll, ll)> q;
//     q.push({1, 1});
//     ll x, y;
//     while(!q.empty()){
//         x = q.front().first;
//         y = q.front().second;
//         q.pop();
//         if(a[x][y])
//     }
// }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    file("oneseq");
    cin >> m >> n;
    memset(a, -1, sizeof(a));
    memset(dp, 0, sizeof(dp));
    lp(i, 1, m){
        lp(j, 1, n){
            cin >> a[i][j];
        }
    }
    ll ans = 0;
    lp(i, 1, m){
        lp(j, 1, n){
            if(a[i][j]) dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
            if(dp[i - 1][j - 1] < dp[i][j] - 1 && a[i][j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            ans = max(ans, dp[i][j]);
            // cerr << dp[i][j] << ' ';
        }
        // cerr << endl;
    }
    cout << ans;
}
