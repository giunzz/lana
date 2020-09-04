#include <bits/stdc++.h>
#define ll long long
#define cll const long long
#define lp(a, b, c) for (ll a  =b; a <= c; a++)
#define lpd(a, b, c) for (ll a  =b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
using namespace std;

void File(const string ff){
    freopen((ff + ".inp").c_str(), "r", stdin);
    freopen((ff + ".out").c_str(), "w", stdout);
}

cll maxn = 1e5 + 7;
ll n, m, a[maxn], Max = -1, ans = LLONG_MAX;

void init(){
    lp(i, 1 , n) cin >> a[i], Max = max(Max, a[i]);    
}

ll checkTime(ll t){
    ll sum = 0;
    lp(i, 1, n) sum += t / a[i];
    return sum;
}

void cnp(ll l, ll r){
    while(l <= r){
        ll mid = (l + r)/2, t = checkTime(mid);
        if(t >= m) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // File("checkin");
    cin >> n >> m;
    init();
    cnp(1, Max * m);
}