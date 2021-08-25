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

cll mxn = 203, mxv = 403, MOD = 1e9 + 7;
ll n, a, dp[mxn][mxv], x[mxn], mi;

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    // lp(i, 0, 200) dp[i][0] = 1; 
    dp[0][0] = 1;
    EACHCASE{
        mi = 1e18;
        cin >> n >> a;
        lp(i, 1, n){
            cin >> x[i];
            x[i] -= a;
            mi = min(mi, x[i]);
        }
        ll s = 0;
        if(mi < 0) lp(i, 1, n) x[i] -= mi, s += x[i];
        mi = -mi;
        lp(i, 1, n) lp(j, 0, s){
            dp[i][j] = dp[i - 1][j];
            if(j - x[i] >= 0) (dp[i][j] += dp[i - 1][j - x[i]]) %= MOD;
        }
        if(mi < 0) cout << "0\n";
        else cout << dp[n][mi] << '\n';
    }
}