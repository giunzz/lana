#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define pp(a, b) pair<a, b>
#define vec(a) vector<a>
#define vecite(a) vector<a>::iterator
#define fi first
#define se second
#define mp(a, b) map<a, b>
#define setE(a, b) fill_n(a, sizeof(a)/sizeof(a[0]), b)
#define st(a) system((a).c_str());
using namespace std;
cll MOD = 1e9 + 7;
const double esf = 1e-9;
const string tenfile = "duaxe";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".ans").c_str(), "w", stdout)

cll maxn = 1e6 + 7;
ll n, a[maxn] = {0};

ll getlom(ll u){
    if(a[u] <= a[u - 1]) return u;
    while(u > 1 && a[u] >= a[u - 1]) --u;
    return u;
}

ll getdinh(ll u){
    while(u > 1 && a[u] <= a[u - 1]) --u;
    return u;
}

int main(){
    opt;
    file;
    cin >> n;
    lp(i, 1, n) cin >> a[i];
    ll pre = 1, ans = 0, lom, dinh;
    lp(i, 2, n){
        lom = getlom(i);
        dinh = getdinh(lom);
        if((i > lom && a[i] > a[lom] && a[i] > a[dinh]) || lom == 1) ans += (a[i] - a[pre]);
        pre = i;
    }
    cout << ans;
}
