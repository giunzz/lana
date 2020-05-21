#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define lpdk(a, b, c, d) for(ll a = b; c; d) 
#define pp(a, b) pair<a, b>
#define vec(a) vector<a>
#define vecite(a) vector<a>::iterator
#define fi first
#define se second
using namespace std;
cll MOD = 1e9 + 7;
const string tenfile = "buying";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cll maxn = 1e5 + 7;
ll n, b, ans = 0;
pp(ll, ll) a[maxn];

int main(){
    opt;
    file;
    cin >> n >> b;
    lp(i, 1, n) cin >> a[i].first >> a[i].second;
    ii i = 1;
    sort(a + 1, a + 1 + n);
    while(b - (a[i].first * a[i].second) >= 0 && i <= n){
        ans += a[i].second;
        b -= a[i].first * a[i++].second;
    }
    if (i <= n){
        ans += min(b / a[i].first, a[i].second);
    }
    cout << ans;
}
