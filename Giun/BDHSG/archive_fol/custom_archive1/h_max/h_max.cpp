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
const string tenfile = "h_max";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

struct line{
    ll a, b, c;
};

cll maxn = 1e5 + 7;
ll n;
line l[maxn];

bool cpr(line const &q, line const &p){
    return -q.b * p.a < -p.b * q.a;
    // return -q.b / q.a < -p.b / p.a;
}

void init(){
    ll x, z, t;
    lp(i, 1, n){
        cin >> x >> z >> t;  //(x - x0) / xvt = (y - y0) /yvt  (x - xi) / (z - x) = (y) / (t)
        l[i].a = t;
        l[i].b = x - z;
        l[i].c = - t * x;
        ll tmp = __gcd(l[i].a, __gcd(l[i].b, l[i].c));
        l[i].a /= tmp, l[i].b /= tmp, l[i].c /= tmp;
        if(l[i].a < 0) l[i].a *= -1, l[i].b *= -1, l[i].c *= -1; 
    }
}

int main(){
    opt;
    file;
    cin >> n;
    init();
    double ans = -1;
    sort(l + 1, l + 1 + n, cpr);
    lp(i, 2, n){
        ll d = l[i - 1].a * l[i].b - l[i].a * l[i - 1].b;
        ll dy = -l[i - 1].a * l[i].c + l[i].a * l[i - 1].c;
        double tmp = (double)dy / (double)d;
        if(tmp - ans >= esf) ans = tmp;  
    }
    if(ans == -1) cout << "-1";
    else cout << setprecision(3) << fixed << ans;
}
