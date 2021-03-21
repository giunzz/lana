#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "b"
using namespace std;

template <typename T> inline void Read(T &x){
    x = 0; char c;
    while(!isdigit(c = getchar()));
    do
    {
        x = x * 10 + c - '0';
    } while (isdigit(c = getchar()));
}

void giuncute(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll mxn = 2e5 + 7;
ll n, a[mxn], s[mxn];

inline ll Get(ll val){
    ll pos = lower_bound(a + 1, a + 1 + n, val) - a - 1;
    return pos * val - (n - pos) * val + (s[n] - s[pos]) - s[pos];
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n;
    lp(i, 1, n){
        cin >> a[i];
        a[i] -= i;
    }
    s[0] = 0;
    sort(a + 1, a + 1 + n);
    lp(i, 1, n) s[i] = s[i - 1] + a[i];
    ll l = a[1], r = a[n], res = 1e15;
    while(l <= r){
        ll mid1 = l + (r - l) / 3, mid2 = r - (r - l) / 2, val1 = Get(mid1), val2 = Get(mid2);
        if(val1 > val2) res = min(res, val2), l = mid1 + 1;
        else res = min(res, val1), r = mid2 - 1;
    }
    cout << res;
}