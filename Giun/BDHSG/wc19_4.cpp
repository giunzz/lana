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

cll MOD = 1e9 + 7, mxn = 1e3 + 7;
ll dp[mxn][mxn] = {{0}};

void init(){
    lp(i, 1, 1000) dp[i][1] = 1;
    lp(i, 1, 1000){
        lp(j, 2, i){
            dp[i][j] = (dp[i - 1][j] * j + dp[i - 1][j - 1]) % MOD;
        }
    }
}

void sol(){
    ll n, ans = 0;
    cin >> n;
    lp(i, 1, n) (ans += dp[n][i]) %= MOD;
    cout << ans << '\n';
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    init();
    EACHCASE sol();
}