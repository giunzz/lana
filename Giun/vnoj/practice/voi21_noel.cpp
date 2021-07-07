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

cll mxn = 107;
ll n, d, a[mxn], dp[mxn][mxn][mxn] = {{{0}}}, ans = 0;

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n >> d;
    lp(i, 1, n) cin >> a[i];
    lp(i, 1, n) lp(j, i + 1, n) lp(k, j, n){ 
        dp[i][j][k] = max({dp[i - 1][j][k], dp[i][j][k - 1], dp[i - 1][j][k - 1], dp[i][j - 1][k]});
        if(abs(a[k] - a[i]) <= d) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + 1);
        ans = max(ans, dp[i][j][k]);
    }
    cout << ans;
}