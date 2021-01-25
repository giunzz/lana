#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "beads"
using namespace std;

ll read(){
    ll tmp;
    cin >> tmp;
    return tmp;
}

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll maxn = 1e5 + 7;
ll n, a[maxn], b[maxn], ba[maxn], bb[maxn], ans = 0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n;
    lpd(i, n, 1){cin >> a[i]; b[i] = -a[i];}
    ans = 1;
    ba[1] = a[1], bb[1] = b[1];
    lp(i, 2, n) ba[i] = bb[i] = INT_MAX;
    lp(i, 2, n){
        ll up = lower_bound(ba + 1, ba + 1 + n, a[i]) - ba, 
            down = lower_bound(bb + 1, bb + 1 + n, b[i]) - bb;
        ans = max(ans, up + down - 1);
        ba[up] = a[i];
        bb[down] = b[i];
    }
    cout << ans;
}