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

cll mxn = 18, mxs = 137;
ll a, b, s, dp[mxn][mxs][2][2], res = -1, tmp = 0;
vec(ll) dg_a, dg_b;

void init(vec(ll) &dg, ll num){
    while(num) dg.push_back(num % 10), num /= 10;
    while(dg.size() < mxn) dg.push_back(0);
}

ll sol(ll n, ll sum, bool stt_a, bool stt_b){
    ll &cur = dp[n][sum][stt_a][stt_b];
    if(~cur) return cur;
    if(!n){
        if(res == -1 && sum == s) res = tmp;
        return cur = (sum == s);
    }
    cur = 0;
    ll nsum = sum, nn = n - 1;
    bool nstt_a = stt_a, nstt_b = stt_b;
    lp(digit, 0, 9){
        if(stt_a){
            if(digit < dg_a[nn]) continue;
            else if(digit == dg_a[nn]) nstt_a = stt_a;
            else nstt_a = 0;
        }
        if(stt_b){
            if(digit > dg_b[nn]) continue;
            else if(digit == dg_b[nn]) nstt_b = stt_b;
            else nstt_b = 0;
        }
        nsum = sum + digit;
        tmp = tmp * 10 + digit;
        if(nsum <= s) cur += sol(nn, nsum, nstt_a, nstt_b);
        tmp /= 10;
    }
    return cur;
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> a >> b >> s;
    init(dg_a, a); init(dg_b, b);
    memset(dp, -1, sizeof dp);
    cout << sol(mxn - 1, 0, 1, 1) << '\n' << res << '\n';
}