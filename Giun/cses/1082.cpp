#include<bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "f"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll MOD = 1e9 + 7;
ll n, st = 0, ans = 0;

ll poww(ll x, ll p){
    if(p == 0) return 1;
    ll tmp = poww(x, p / 2);
    if(p & 1) return (tmp * (tmp * x) % MOD) % MOD;
    else return (tmp * tmp) % MOD;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // OF();
    cin >> n;
    ll p2 = poww(2, MOD - 2);
    // cerr << p2;
    for(ll i = 1; i * i <= n; ++i){
        (ans += ((n / i) % MOD) * i) %= MOD;
        // if((i + 1) * (i + 1) > n) continue;
        ll ed = n / i, bg = n / (i + 1) + 1;
        if(bg <= i) continue;
        // cerr << bg << ' ' << ed << '\n';
        (ans += ((((ed - bg + 1) % MOD) * ((ed + bg) % MOD)) % MOD) * ((p2 * i) % MOD)) %= MOD;
    }
    cout << ans % MOD;
    // ll ans1 = 0;
    // lp(i, 1, n){
    //     lp(j, 1, i){
    //         if(i % j == 0){
    //             ans1 += j;
    //             // cerr << j <<  ' ';
    //         }
    //     }
    //     // cerr << '\n';
    // }
    // cout << '\n' << ans1;
}