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

cll maxmask = (1LL << (7)) + 7;

class BearDestroysDiv2{
    private:
    int a[10][50] = {{0}}, dp[41][201][maxmask];
    ll w, h, mod;
    public:
    int sumUp(int W, int H, int MOD);
    ll sol();
};

int BearDestroysDiv2::sumUp(int W, int H, int MOD){
    this -> w = W, this -> h = H, this -> mod = MOD;
    memset(dp, -1, sizeof dp);
    return sol();
}

ll BearDestroysDiv2::sol(){
    dp[1][0][0] = 1;
    lp(i, 1, h){
        lp(mask, 0, (1 << w) - 1){
            lp(num,)
        }
    }
}

// ll BearDestroysDiv2::sol(ll i, ll j, ll mask){
//     if(i >= h) return 1;
//     if(j >= w) return sol(i + 1, 0, mask);
//     if(dp[i][j][mask] != -1) return dp[i][j][mask];
//     ll res = 0;
//     // nga qua phai
//     if((!a[i][j] && !a[i][j + 1] && j + 1 != w)){
//         a[i][j] = a[i][j + 1] = 1; 
//         ll tmp = sol(i, j + 1, (mask >> 1) | (1LL << ((w - 1))));
//         a[i][j] = a[i][j + 1] = 0;
//         if(i + 1 == h) (res += 2*tmp) %= mod;
//         else (res += tmp) %= mod;
//     }
//     //nga xuong duoi
//     if(i + 1 != h && !a[i][j]){
//         a[i][j] = a[i + 1][j] = 1;
//         ll tmp = sol(i, j + 1, (mask >> 1) | (1LL << ((w - 1))));
//         a[i][j] = a[i + 1][j] = 0;
//         if(j + 1 == w) (res += 2 * tmp) %= mod;
//         else (res += tmp) % mod;
//     }
//     // dung yen
//     if((i + 1 == h && a[i][j + 1]) || a[i][j]){
//         ll tmp = sol(i, j + 1, (mask >> 1));
//         (res += tmp) %= mod;
//     }
//     return dp[i][j][mask] = res;
// }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    BearDestroysDiv2 tmp;
    cerr << tmp.sumUp(3, 4, 999999937);
}