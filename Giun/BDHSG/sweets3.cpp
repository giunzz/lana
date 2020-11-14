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

cll maxDg = 32;
ll n, a, b, c, f[33][100];
vec(ll) bn;

ll solve(ll i, ll car){
    if(f[i][car] > -1) return f[i][car];
    if(i == 0) return (car == 0);
    ll cnt = 0;
    lp(x, 0, 1) lp(y, 0, 1) lp(z, 0, 1){
        ll tmp = x * a + y * b + z * c + car;
        if(tmp % 2 == bn[i]) cnt += solve(i - 1, tmp / 2);
    }
    f[i][car] = cnt;
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // OF();
    ll cs;
    cin >> cs;
    while(cs--){
        memset(f, -1, sizeof(f));
        cin >> n >> a >> b >> c;
        bn.clear();
        while(n){
            bn.push_back(n & 1);
            n >>= 1;
        }
        while(bn.size() <= maxDg) bn.push_back(0);
        reverse(bn.begin(), bn.end());
        cout << solve(32, 0) << '\n';
    }
}