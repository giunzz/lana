#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "chiathe"
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

cll mxn = 407, mxv = 1e5 + 2;
ll n, a[mxn], dp[mxn][mxv] = {{0}}, sum = 0;

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n;
    lp(i, 1, n){
        cin >> a[i];
        sum += a[i];
    }
    memset(dp, -1, sizeof dp);
    dp[0][0] = 0;
    lp(i, 1, n) lp(j, 0, sum){
        dp[i][j] = dp[i - 1][j];
        if(j - a[i] >= 0 && ~dp[i - 1][j - a[i]]) dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i]] + a[i]);
        if(j + a[i] <= sum && ~dp[i - 1][j + a[i]]) dp[i][j] = max(dp[i][j], dp[i - 1][j + a[i]] + a[i]);
    }
    cout << dp[n][0] / 2 + sum - dp[n][0];
}