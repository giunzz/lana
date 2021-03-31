#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "sc2"
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
ll f[mxn] = {0};

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    f[0] = 1, f[1] = 0;
    lp(i, 2, 1e5) (f[i] = (i - 1) * (f[i - 1] + f[i - 2])) %= MOD;
    EACHCASE cout << f[read()] << '\n';
}