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
ll n, k, a[mxn];

bool check(ll t){
    ll tot = 0;
    lp(i, 1, n) tot += a[i] / t;
    return tot >= k; 
}

int main(){
    giuncute();
    // OF();
    cin >> n >> k;
    lp(i, 1, n){ 
        double tmp;
        cin >> tmp;
        a[i] = tmp * 10000000000000;
    }
    ll l = 1, r = 1e18, ans;
    while(l <= r){
        ll mid = (l + r) >> 1;
        if(check(mid / 100000000000 * 100000000000)){
            ans = mid / 100000000000 * 100000000000;
            l = mid + 1;
        } else r = mid - 1;
    }
    cout << fixed << setprecision(2) << ans / (double)10000000000000;
}