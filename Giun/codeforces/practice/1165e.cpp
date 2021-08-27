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

cll MOD = 998244353, mxn = 2e5 + 7;
ll n, a[mxn], b[mxn];

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n;
    lp(i, 1, n){
        cin >> a[i];
        a[i] *= i * (n - i + 1);
    }
    lp(i, 1, n) cin >> b[i];
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n, greater<ll>());
    ll ans = 0;
    // lp(r, 1, n) lp(l, 1, r) lp(k, l, r) ans += a[k] * b[k];
    lp(i, 1, n) (ans += (a[i] % MOD) * b[i]) %= MOD;
    cout << ans;
}