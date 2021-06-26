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

cll mxn = 1e3 + 7, MOD = 1e9;
ll dp[mxn][mxn] = {{0}};

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    lp(i, 1, 1e3) dp[i][0] = 1;
    lp(i, 1, 1e3) lp(j, 1, 1e3) (dp[i][j] = dp[i][j - 1] + dp[i - 1][j]) %= MOD;
    EACHCASE cout << dp[read()][read()] << '\n';
}