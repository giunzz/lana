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
    freopen(Fname".ans", "w", stdout);
}

cll maxn = 1e5 + 7;
ll n, a[maxn], inc[maxn] = {0}, decr[maxn] = {0}, binc[maxn], bdec[maxn], ans = 0;

ll getDec(ll u){
    ll i = 1, j = n, res = -1;
    while(i <= j){
        ll mid = (i + j) >> 1;
        if(bdec[mid] <= u) res = mid, j = mid - 1;
        else i = mid + 1;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n;
    lpd(i, n, 1) cin >> a[i];
    ans = 1;
    binc[1] = bdec[1] = a[1];
    lp(i, 2, n) binc[i] = INT_MAX, bdec[i] = INT_MIN;
    lp(i, 2, n){
        ll up = lower_bound(binc + 1, binc + 1 + n, a[i]) - binc, 
            down = getDec(a[i]);
        ans = max(ans, up + down - 1);
        binc[up] = bdec[down] = a[i];
    }
    cout << ans;
}