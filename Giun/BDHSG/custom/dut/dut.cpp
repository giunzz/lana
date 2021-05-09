#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "dut"
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

ll n, dp[5][5] = {{0}}, cnt[5] = {0}, ans = 0;

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n;
    ll tmp;
    lp(i, 1, n){
        cin >> tmp;
        if(tmp >= 4){
            tmp = 4;
            ans += dp[1][1];
            dp[1][4] += cnt[1];
        } else if(tmp == 3){
            ans += dp[1][1] + dp[1][2] + dp[2][1];
            dp[1][3] += cnt[1];
            dp[2][3] += cnt[2];
        } else if(tmp == 2){
            ans += dp[1][1] * 2 + dp[1][2] + dp[2][1] + dp[1][3] + dp[3][1];
            lp(i, 1, 3) dp[i][2] += cnt[i];
        } else{
            ans += dp[1][1] * 3 + (dp[1][2] + dp[2][1]) * 2 + dp[2][2] + dp[2][3] + dp[3][2] + dp[1][3] + dp[3][1] + dp[1][4] + dp[4][1]; 
            lp(i, 1, 4) dp[i][1] += cnt[i];
        }
        ++cnt[tmp];
    }
    cout << ans;
}