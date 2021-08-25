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

cll MOD = 1e9 + 9, mxb = 130, mxk = 1003;
ll k, b;
pp(ll, ll) dp[mxb][mxk];

ll modk(ll u, ll v){
    if(!v) return 1 % k;
    ll tmp = modk(u, v >> 1);
    if(v & 1) return (((tmp * tmp) % k) * u) % k;
    return (tmp * tmp) % k; 
}

pp(ll, ll) sol(ll pos, ll r){
    ll &cur = dp[pos][r].first, &sl = dp[pos][r].second;
    pp(ll, ll) &cur_dp = dp[pos][r];
    if(~cur) return dp[pos][r];
    if(!pos){
        if(k == 1){
            if(r == 0) return cur_dp = {1, 2};
            return cur_dp = {1e18, -1};
        }
        if(r > 1) return cur_dp = {1e18, -1};
        else return cur_dp = {(r == 1), 1};
    }
    cur = 0, sl = 0;
    ll npos = pos - 1, nr;
    pp(ll, ll) tmp;
    bool ok = 0;
    lp(i, 0, 1){
        if(i) nr = (k + r - modk(2, pos)) % k;
        else nr = r;
        tmp = sol(npos, nr);
        if(tmp.first == 1e18) continue;
        // if(pos == 4) cerr << nr << ' ' << tmp.first << '\n';
        ok = 1;
        (cur += tmp.first + i * tmp.second) %= MOD;
        (sl += tmp.second) %= MOD;
    }
    if(ok) return cur_dp;
    return cur_dp = {1e18, -1};
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    lp(i, 0, mxb - 1) lp(j, 0, mxk - 1) dp[i][j] = {-1, -1};
    cin >> k >> b;
    cout << sol(b - 1, 0).first;
}