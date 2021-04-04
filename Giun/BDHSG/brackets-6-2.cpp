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

cll mxn = 2e3 + 7;
string s;
ll n, dp[mxn][mxn] = {0};

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> s;
    n = s.size();
    lp(i, 0, mxn - 1) lp(j, 0, mxn - 1) dp[i][j] = 1e18;
    if(s[0] == '(') dp[0][1] = 0;
    else dp[0][1] = 1;
    lp(i, 0, n - 2){
        lp(num, 0, i + 1){
            if(dp[i][num] == 1e18) continue;
            if(s[i + 1] == '('){
                if(num) dp[i + 1][num - 1] = min(dp[i + 1][num - 1], dp[i][num] + 1);
                dp[i + 1][num + 1] = min(dp[i + 1][num + 1], dp[i][num]);
            }
            else{
                if(num) dp[i + 1][num - 1] = min(dp[i + 1][num - 1], dp[i][num]);
                dp[i + 1][num + 1] = min(dp[i + 1][num + 1], dp[i][num] + 1);
            } 
        }
    }
    cout << dp[n - 1][0];
}