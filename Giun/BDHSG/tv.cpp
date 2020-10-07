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
const string tenfile = "tv";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cll maxn = 1e5 + 7;
ll n, m, p, chkenh[maxn] = {0}, res = 0;
bool d[maxn] = {0};
pp(ll, ll) a[maxn];

ii main(){
    opt;
    file;
    cin >> n >> m >> p;
    lp(i, 1, n){ 
        cin >> a[i].first >> a[i].second;
        if(!chkenh[a[i].second]) chkenh[a[i].second] = a[i].first;
    }
    d[p] = 1;
    bool ok = 0;
    while(chkenh[p]){
        p = chkenh[p];
        if(d[p]){ok = 1; break;}
        d[p] = 1;
        ++res;
    }
    if(ok) cout << -1;
    else cout << (res ? res : -1);
}

