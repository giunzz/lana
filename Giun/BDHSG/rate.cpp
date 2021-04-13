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

cll mxn = 3e5 + 7;
ll n, k;
double a[mxn];

//(a[l] + a[l + 1] + .. + a[r]) / (r - l + 1) >= x
// => a[l] - x + a[l + 1] - x + .. + a[r] - x >= 0
// => b[l] + b[l + 1] + .. + b[r] >= 0

bool check(double vl){
    vec(double) b(n + 1);
    b[0] = 0;
    lp(i, 1, n) b[i] = b[i - 1] + a[i] - vl;
    double mi = 0;
    lp(i, k, n){
        mi = min(b[i - k], mi);
        if(b[i] - mi >= (double)0) return 1; 
    }
    return 0;
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n >> k;
    lp(i, 1, n) cin >> a[i];
    ll l = 0, r = 1e13;
    double ans;
    while(l <= r){
        ll mid = (l + r) / 2;
        if(check(mid / 1e7)) ans = mid / 1e7, l = mid + 1;
        else r = mid - 1;
    }
    cout << fixed << setprecision(6) << ans;
}