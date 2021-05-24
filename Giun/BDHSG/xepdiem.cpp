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

cll mxn = 2e5 + 7, MOD = 1e9 + 7;
ll n, a[mxn], dp = 0, ans = 0;
unordered_map<ll, ll> mp;

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n;
    lp(i, 1, n){
        cin >> a[i];
        ++mp[a[i]];
    }
    ll p16 = 41666667;
    lp(i, 1, n){
        if(!mp[a[i]]) continue;
        (ans += ((dp * ((mp[a[i]] * (mp[a[i]] - 1) / 2) % MOD)) % MOD) + ((((mp[a[i]] * (mp[a[i]] - 1)) % MOD) * (((((mp[a[i]] - 2) * (mp[a[i]] - 3)) % MOD) * p16) % MOD)) % MOD)) %= MOD;
        (dp += mp[a[i]] * (mp[a[i]] - 1) / 2) %= MOD;
        mp[a[i]] = 0;
    }
    cout << ans;
}