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

ll cnt(ll first){
    ll last = n / first * first, sum = (((((last - first) % MOD ) * poww(first, MOD - 2)) % MOD + 1) * (first % MOD)) % MOD;
    return sum;
}

ll cntrange(ll l, ll r, ll i){
    ll ct = (r - l + 1), s = (((l + r) % MOD * ct) % MOD) * (poww(2, MOD - 2) * i) % MOD;
    return s % MOD;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n;
    // mod2 = poww(2, MOD - 2);
    for(ll i = 1; i * i <= n; ++i){
        st = i;
        // ll last = n / i * i, cnt = (last - i) / i + 1, sum = (cnt * i) % MOD;
        (ans += cnt(i)) %= MOD;
        if(i * i != n) (ans += cntrange((n) / (i + 1) - 1, n / i, i)) %= MOD;
    }
    ++st;
    cerr << st;
    (ans += (((n + st) * (n - st + 1)) % MOD * poww(2, MOD - 2))) %= MOD;
    cout << ans;
    ll ans1 = 0;
    lp(i, 1, n){
        lp(j, 1, i){
            if(i % j == 0){
                ans1 += j;
                // cerr << j <<  ' ';
            }
        }
        // cerr << '\n';
    }
    cout << '\n' << ans1;
}