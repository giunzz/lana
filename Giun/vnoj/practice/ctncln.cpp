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

cll mxn = 4e4 + 3;
ll n, a[mxn], m, cur_seg[mxn], last[mxn], dp[mxn];

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n >> m;
    lp(i, 1, n) cin >> a[i];
    memset(cur_seg, -1, sizeof cur_seg);
    memset(last, -1, sizeof last);
    cur_seg[0] = 1;
    lp(i, 1, n){
        dp[i] = 1e18;
        ll k = last[a[i]], j;
        for(j = 0; j * j <= n && cur_seg[j] - 1 != k; ++j);
        for(; j > 0; --j) cur_seg[j] = cur_seg[j - 1];
        cur_seg[0] = i + 1;
        last[a[i]] = i;
        for(j = 0; j * j <= n; ++j) if(cur_seg[j] != -1) dp[i] = min(dp[i], j * j + dp[cur_seg[j] - 1]);
    }
    // cerr << dp[1];
    cout << dp[n];
}