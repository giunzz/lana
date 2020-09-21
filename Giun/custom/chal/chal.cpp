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
const string tenfile = "chal";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cll maxn = 1e3 + 7;
ll m, n , a[maxn][maxn], d[(int)1e6+1] = {0};
vec(ll) snt;

void init(){
<<<<<<< HEAD
=======
    d[1] = 2;
>>>>>>> 71dae57a442cd26f3ab066fd924a841fdd2985b9
    for(ll i = 2; i <= 1e5 + 100; i++){
        if(!d[i]){
            // snt.push_back(i);
            for(ll j = i * i; j <= 1e5 + 100; j += i) d[j] = 1;
        }
    }
    for(int i = 2e5; i >= 2; i--) 
        if(!d[i]) d[i] = i;
        else d[i] = d[i + 1];
}

struct quang{
    ll doc = 0, ngang = 0;
}f[maxn][maxn];

int main(){
<<<<<<< HEAD
    opt;
    file;
    init();
    // cin >> m >> n;
    scanf("%lld %lld", &m, &n);
=======
    // opt;
    // file;
    init();
    cin >> m >> n;
    // scanf("%lld %lld", &m, &n);
>>>>>>> 71dae57a442cd26f3ab066fd924a841fdd2985b9
    // lp(i, 1, m){
    //     lp(j, 1, n) 
    // }
    ll ans = LLONG_MAX;
    lp(i, 1, m){
        lp(j, 1, n){
            // ll tmp = lower_bound(snt.begin(), snt.end(), a[i][j]) - snt.begin();
            // f[i][j] = {d[a[i][j]] - a[i][j], d[a[i][j]] - a[i][j]};
            scanf("%lld", &a[i][j]);
            f[i][j].doc = f[i - 1][j].doc + d[a[i][j]] - a[i][j];
            f[i][j].ngang = f[i][j - 1].ngang + d[a[i][j]] - a[i][j];
        }
        if(ans > f[i][n].ngang) ans = f[i][n].ngang;
    }
    for(int j = 1; j <= n; j++) 
        if(ans > f[m][j].doc) ans = f[m][j].doc;
<<<<<<< HEAD
    cout << ans;
    // cerr << clock();
=======
    cout << ans << endl;
    cerr << clock();
    // cout<<endl;
    // lp(i, 1, m){
    //     lp(j, 1, n) cout << f[i][j].doc << ' ';
    //     cout << endl;
    // }

>>>>>>> 71dae57a442cd26f3ab066fd924a841fdd2985b9
}
