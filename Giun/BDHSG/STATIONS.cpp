#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "stations"
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

cll mxn = 2e5 + 7, init[] = {3, 2, 1};
ll n, a[mxn], ans[3], ansbk;

inline ll Find(ll val, ll r){
    ll l = 0, res;
    while(l <= r){
        ll mid = (l + r) >> 1;
        if(a[mid] <= val) res = mid, l = mid + 1;
        else r = mid - 1;
    }
    return res;
}

bool check(ll d){
    vec(ll) dp(n + 1, 0), trace(n + 1, 0);
    lp(i, 1, n){
        ll last = a[i] - d * 2 - 1, pos = Find(max(last, 0LL), i - 1);
        dp[i] = dp[pos] + 1, trace[i] = pos;
    }
    if(dp[n] > 3) return 0;
    ll le = n;
    lp(i, 0, 2){
        ans[i] = max(a[le] - d, init[i]);
        le = trace[le];
        if(le == 0) break;
    }
    return 1;
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n;
    lp(i, 1, n) a[i] = read() * 1e6;
    sort(a + 1, a + 1 + n);
    ll l = 0, r = 1e15;
    while(l <= r){
        ll mid = (l + r) >> 1;
        if(check(mid)) ansbk = mid, r = mid - 1;
        else l = mid + 1;
    }
    cout << setprecision(6) << fixed << ansbk / 1e6 << endl;
    lpd(i, 2, 0) cout << setprecision(6) << fixed << ans[i] / 1e6 << ' ';
}