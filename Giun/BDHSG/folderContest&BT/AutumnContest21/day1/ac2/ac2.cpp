#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "ac2"

ll read(){
    ll tmp;
    cin >> tmp;
    return tmp;
}
#define EACHCASE lpd(cs, read(), 1)

cll mxn = 40, MOD = 998244353;
ll n, d, dp[mxn][4][1 << 4][1 << 4];
bool sing[mxn], dan[mxn], t[3][mxn];

void sol(ll pos, ll team, bool op, ll mask){
    if(pos == n + 1) return;
    ll npos = 
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
    EACHCASE{
        memset(dp, 0, sizeof dp);
        cin >> n >> d;
        ll tmp;
        cin >> tmp;
        lp(i, 1, tmp) t[1][read()] = 1;
        cin >> tmp;
        lp(i, 1, tmp) t[2]dan[read()] = 1;
        lp(i, 1, n) t[0][i] = 1;
        if(sing[1]) dp[1][1][1][1] = 1, sol(1, 1, 1, 1);
        if(dan[1]) dp[1][2][1][1 << 2] = 1, sol(1, 2, 1, 1 << 2);
        dp[1][0][1][0] = 1; sol(1, 0, 1, 0);


        // lp(i, 1, n){
        //     lp(team, 0, 2){
        //         lp(mask_open, 0, (1 << 4) - 1){
        //             lp(mask_tot, 0, (1 << 4) - 1){
        //                 if(dp[i][team][mask_open][mask_tot]){
        //                     if((1 << team) & mask_open){
        //                         lp(j, 1, d){
        //                             ll nmask_open = mask_open, nmask_tot = mask_tot;

        //                         }
        //                     }
        //                 }
        //             }
        //         }
        //     }
        // }
        
    }
}
