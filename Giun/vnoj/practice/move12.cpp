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

cll mxn = 1e4 + 7;
ll n, c[mxn], t[mxn], l[mxn], r[mxn];

inline bool check(ll time){
    lp(i, 1, n) l[i] = r[i] = 0;
    lp(i, 1, n) ++l[max(1LL, c[i] - time / t[i])], ++r[min(n, c[i] + time / t[i])];
    lp(i, 1, n){
        l[i] += l[i - 1], r[i] += r[i - 1];
        if(l[i] < i or r[i] > i) return 0;
    }
    return 1;
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n;
    lp(i, 1, n) cin >> c[i] >> t[i];
    ll l = 0, r = 1e9, ans;
    while(l <= r){
        ll mid = (l + r) >> 1;
        if(check(mid)) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    cout << ans;
}