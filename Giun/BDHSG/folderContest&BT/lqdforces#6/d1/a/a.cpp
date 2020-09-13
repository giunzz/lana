#include <bits/stdc++.h>
#define ll long long
#define cll const long long
#define lp(a, b, c) for (ll a  =b; a <= c; a++)
#define lpd(a, b, c) for (ll a  =b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
using namespace std;
#define ff "a"

void File(){
    freopen(ff".inp", "r", stdin);
    freopen(ff".out", "w", stdout);
}

cll maxn = 1e5 + 7;
ll a[maxn], n, k;

bool check(ll t){
    ll tmp = k * t, cnt = 0, m;
    vec(ll) b(a + 1, a + 1 + n);
    while(1){
        m = min(b[0], t);
        for(ll &v : b){
            v -= m;
        }
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    File();
    cin >> n >> k;
    lp(i, 1, n) cin >> a[i];
    sort(a + 1, a + 1 + n);
    ll l = 0, r = 1e5, mid, ans;
    while(l <= r){
        mid = (l + r) / 2;
        if(check(mid)){
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1; 
    }
    cout << ans;
}