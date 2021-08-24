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

cll mxbit = 22, mxn = 1 << mxbit;
ll n, f[mxn] = {0}, a[mxn];

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n;
    memset(f, -1, sizeof f);
    lp(i, 1, n){
        cin >> a[i];
        f[a[i]] = a[i];
    }
    lp(i, 0, mxbit - 1) lp(j, 0, mxn - 1){
        if(j & (1 << i)) f[j] = max(f[j], f[j ^ (1 << i)]);
    }
    // cerr << f[10] << '\n';
    // bitset<mxbit> test((1 << mxbit) - 1 - a[1]);
    // cerr << test;
    lp(i, 1, n) cout << f[(1 << mxbit) - 1 - a[i]] << ' ';
}