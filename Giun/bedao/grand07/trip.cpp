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
const string tenfile = "trip";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cll maxn = 1e5 + 7;
ll n, a[maxn] = {0}, ans = 0, f[maxn] = {0};

map<ll, ll> mp;

ll getsum(ll i){
    ll result = 0;
    while (i >= 1){
        result = result + f[i];
        i = i - (i & -i);
    }
    return result;
}

void upd(ll i){
    while (i <= n){
        f[i] = f[i] + 1;
        i = i + (i & -i);
    }
}

int main(){
    opt;
    file;
    cin >> n;
    lp(i, 1, n){
        cin >> a[i];
        ans += i - mp[a[i]] - 1 - getsum(i);
        if(mp[a[i]]) ans += getsum(mp[a[i]] - 1) ,upd(mp[a[i]]);
        mp[a[i]] = i;
    }
    cout << ans;
}
