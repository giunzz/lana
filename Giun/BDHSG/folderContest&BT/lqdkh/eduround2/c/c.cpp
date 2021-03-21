#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "c"
using namespace std;

template <typename T> inline void Read(T &x){
    x = 0; char c;
    while(!isdigit(c = getchar()));
    do
    {
        x = x * 10 + c - '0';
    } while (isdigit(c = getchar()));
}

void giuncute(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll mxn = 507;
ll n, dp[mxn][mxn] = {{0}};
string s;

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n >> s;
    lp(i, 0, n - 1) dp[i][i] = 1;
    lp(len, 2, n){
        lp(i, 0, n - 1){
            ll j = i + len - 1;
            if(j >= n) break;
            dp[i][j] = dp[i + 1][j] + 1;
            lp(x, i + 1, j)
                if(s[i] == s[x]) dp[i][j] = min(dp[i][j], dp[i + 1][x - 1] + dp[x][j]);
        }
    }
    cout << dp[0][n - 1];
}