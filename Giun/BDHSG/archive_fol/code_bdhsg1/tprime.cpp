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
const string tenfile = "f";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cll maxn = 1e6 + 7;
ll n;
bool prime[maxn] = {0};

ii main(){
    opt;
    file;
    prime[0] = true, prime[1] = true;
    lp(i, 2, 1e6)
        if(!prime[i])
            for(ll j = i + i; j <= 1e6; j += i) prime[j] = 1;
    cin >> n;
    ll num, tmp;
    while(n--){
        cin >> num;
        tmp = sqrt(num);
        if(tmp * tmp == num && !prime[tmp]) cout << "YES\n";
        else cout << "NO\n";
    }
}
