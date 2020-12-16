#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "f"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll maxn = 1e3 + 7, MOD = 1e9 + 9, maxdiff = 31;
ll n, h, dp[2][maxdiff][maxdiff][maxdiff][2] = {{0}};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    // xet canh 1
    cin >> n >> h;
    dp[0][0][0][0][1] = 1;
    lp(i, 0, n - 1){
        lp(l0, 0, h) lp(l1, 0, h) lp(l2, 0, h) lp(stt, 0, 1){
            ll tmp = dp[i & 1][l0][l1][l2][stt];
            if(!tmp) continue;
            ll l3 = (stt ? 1 : h);
            dp[(i & 1)][l0][l1][l2][stt] = 0;
            (dp[!(i & 1)][min(l1 + 1, h)][min(l2 + 1, h)][l3][l0 < h] += tmp) %= MOD;
            (dp[!(i & 1)][min(l0 + 1, h)][min(l2 + 1, h)][l3][l1 < h] += tmp) %= MOD;
            (dp[!(i & 1)][min(l0 + 1, h)][min(l1 + 1, h)][l3][l2 < h] += tmp) %= MOD;
            (dp[!(i & 1)][min(l0 + 1, h)][min(l1 + 1, h)][min(l2 + 1, h)][stt] += tmp) %= MOD; 
        }
    }
    // l0 = h tuc la xet truong hop ko den dc
    ll res = 0;
    lp(l0, 0, h) lp(l1, 0, h) lp(l2, 0, h) lp(stt, 0, 1) 
    if(l0 < h || l1 < h || l2 < h || stt) (res += dp[n & 1][l0][l1][l2][stt]) %= MOD;
    cout << res;
}