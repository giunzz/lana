#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "ac2"
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

cll mxn = 38, MOD = 998244353;
ll n, d, dp[mxn][mxn][mxn][1 << 3];
bool a[3][mxn];

void sol(){
    memset(a, 0, sizeof a);
    memset(dp, 0, sizeof dp);
    cin >> n >> d;
    EACHCASE a[1][read()] = 1;
    EACHCASE a[2][read()] = 1;
    lp(i, 1, n) a[0][i] = 1;
    dp[0][0][0][0] = 1;
    ll ans = 0;
    lp(i, 0, n) lp(j, 0, n) lp(k, 0, n) lp(mask, 0, (1 << 3) - 1){
        if(!dp[i][j][k][mask]) continue;
        ll next_pos = max({i, j, k}) + 1;
        if(next_pos > n){ 
            if(!mask && j && k) (ans += dp[i][j][k][mask]) %= MOD;
            continue;
        }
        lp(t, 0, 2) if(a[t][next_pos]){
            if(((1 << t) & mask)){
                if(t == 0){
                    if(next_pos - i > d) continue;
                    else (dp[next_pos][j][k][mask - 1] += dp[i][j][k][mask]) %= MOD;
                }
                if(t == 1){
                    if(next_pos - j > d) continue;
                    else (dp[i][next_pos][k][mask - 2] += dp[i][j][k][mask]) %= MOD;
                }
                if(t == 2){
                    if(next_pos - k > d) continue;
                    else (dp[i][j][next_pos][mask - 4] += dp[i][j][k][mask]) %= MOD;
                }
            }else{
                if(t == 0){
                    if(next_pos - i <= d && i) (dp[next_pos][j][k][mask] += dp[i][j][k][mask]) %= MOD;
                    else (dp[next_pos][j][k][mask | 1] += dp[i][j][k][mask]) %= MOD;
                }
                if(t == 1){
                    if(next_pos - j <= d && j) (dp[i][next_pos][k][mask] += dp[i][j][k][mask]) %= MOD;
                    else (dp[i][next_pos][k][mask | 2] += dp[i][j][k][mask]) %= MOD;
                }
                if(t == 2){
                    if(next_pos - k <= d && k) (dp[i][j][next_pos][mask] += dp[i][j][k][mask]) %= MOD;
                    else (dp[i][j][next_pos][mask | 4] += dp[i][j][k][mask]) %= MOD;
                }
            }
        }
    }
    cout << ans << '\n';
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    EACHCASE sol();
}