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

cll mxn = 3500;
ll n, k, a[mxn], dp[mxn][mxn] = {{0}}, ans = 1e18;
vec(ll) trace;

void prc(){
    lp(i, 2, n) lp(j, 1, k) dp[i][j] = min(dp[i - 1][j], dp[i - 2][j - 1] + a[i]);
}

void trc(){
    trace.clear();
    ll i = n;
    lpd(j, k, 1){
        while(dp[i - 1][j] == dp[i][j]){
            --i;
        }
        trace.push_back(i); 
        i -= 2;
    }
}

int main(){
    giuncute();
    cin >> n >> k;
    lp(i, 1, n) cin >> a[i];
    lp(i, 0, n) lp(j, 1, k) dp[i][j] = 1e18;
    
    prc();
    ans = dp[n][k]; trc();

    dp[1][1] = a[1];
    a[n] = 1e18;
    prc();
    if(dp[n][k] < ans) ans = dp[n][k], trc();
    
    cout << ans << '\n';
    reverse(trace.begin(), trace.end());
    for(ll i : trace) cout << i - 1 << ' ';
}