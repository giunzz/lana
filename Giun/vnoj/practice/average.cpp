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

cll mxn = 203, MOD = 1e9 + 7, mxv = 8e4 + 2;
ll n, x[mxn], a, sum = 0, dp[mxn][mxv];

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    EACHCASE{
        sum = 0;
        cin >> n >> a;
        lp(i, 1, n){
            cin >> x[i];
            x[i] -= a;
            if(x[i] < 0) sum += x[i];
            // cerr << x[i] << '\t';
        }
        // cerr << '\n';
        sum = -sum;
        // cerr << sum << '\n';
        // dem so luong day con co tong = 0
        dp[0][sum] = 1; // tong = 0 - sum
        lp(i, 1, n){
            lp(j, 0, 8e4){
                ll raw_j = j - sum;
                dp[i][j] = dp[i - 1][j];
                if(raw_j - x[i] >= -sum) (dp[i][j] += dp[i - 1][raw_j - x[i] + sum]) %= MOD;
                // cerr << i << ' ' << j << ' ' << raw_j << '\t' << dp[i][j] << '\n';
            }
            // cerr << '\n';
        }
        cout << dp[n][sum] - 1 << '\n';
    }
}   