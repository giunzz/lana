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

ll s, k, f[1000] = {0};

ii main(){
    opt;
    file;
    ll tg = 1;
    cin >> s >> k;
    f[1] = 1;
    lp(i, 2, 500){
        if(i < k)
            lp(j, 0, i - 1) f[i] += f[j];  
        else
            lp(j, i - k, i - 1) f[i] += f[j];
        if(f[i] >= s) break;
        tg = i;
    }
    vec(ll) ans;
    ll i = tg;
    while(i > 0){
        ans.push_back(f[i]);
        s -= f[i];
        if(!s) break;
        while(f[i] > s) --i;
    }
    cout << ans.size() << endl;
    for (ll i : ans)
        cout << i << " ";
}
