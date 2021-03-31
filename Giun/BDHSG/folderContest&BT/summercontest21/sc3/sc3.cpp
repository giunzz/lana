#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "sc3"
using namespace std;

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

cll mxn = 1e5 + 7, MOD = 1e9 + 7;
ll n, gt[mxn], f[mxn];

inline ll Pow(ll u, ll v){
    if(!v) return 1;
    ll tmp = Pow(u, v >> 1);
    if(v & 1) return (((tmp * tmp) % MOD) * u) % MOD;
    return (tmp * tmp) % MOD; 
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    gt[0] = f[0] = 1, f[1] = 0;
    lp(i, 1, 1e5) gt[i] = (gt[i - 1] * i) % MOD;
    lp(i, 2, 1e5) f[i] = ((i - 1) * (f[i - 1] + f[i - 2])) % MOD; 
    EACHCASE{
        cin >> n;
        ll res = ((gt[n] * Pow((gt[n >> 1] * gt[n >> 1]) % MOD, MOD - 2)) % MOD) * ((gt[n >> 1] * f[n >> 1]) % MOD);
        cout << (res % MOD) << '\n';
    }
}