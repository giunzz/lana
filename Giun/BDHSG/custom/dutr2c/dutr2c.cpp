#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "dutr2c"
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

cll mxn = 1e6 + 7, MOD = 998244353;
ll n, a[mxn], sum[mxn], cal[mxn], dp[mxn], sumdp[mxn];

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n;
    sum[0] = cal[0] = dp[0] = sumdp[0] = 0;
    lp(i, 1, n){
        cin >> a[i];
        (sum[i] = sum[i - 1] + a[i]) %= MOD;
        (cal[i] = 2 * cal[i - 1] + sum[i - 1]) %= MOD;
        (dp[i] = sumdp[i - 1] + cal[i] + sum[i]) %= MOD;
        (sumdp[i] = sumdp[i - 1] + dp[i]) %= MOD;
    }
    cout << dp[n];
    cerr << "Task: " << clock() << '\n';
}