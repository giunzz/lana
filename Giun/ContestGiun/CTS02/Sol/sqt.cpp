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
const string tenfile = "sqt";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

struct point{
    ll x, y;
}p[4];

ll n;
double ans = 0;

bool kt(){
    point p01 = {p[1].x - p[0].x, p[1].y - p[0].y};
    point p12 = {p[2].x - p[1].x, p[2].y - p[1].y};
    point p20 = {p[0].x - p[2].x, p[0].y - p[2].y};
    return (!(p01.x * p12.x + p01.y * p12.y) || !(p12.x * p20.x + p12.y * p20.y) || !(p20.x * p01.x + p20.y * p01.y));
}

ll getts(point p1, point p2, point p3){
    point u, v;
    u.x = p2.x - p1.x;
    u.y = p2.y - p1.y;
    v.x = p3.x - p1.x;
    v.y = p3.y - p1.y;
    return abs(u.x * v.y - u.y * v.x);
}

ii main(){
    opt;
    file;
    cin >> n;
    lp(i, 1, n){
        lp(j, 0, 2) cin >> p[j].x >> p[j].y;
        if(kt()){
            double s = getts(p[0], p[1], p[2]) / 2.0;
            ans = max(ans, s);
        }
    }
    cout << ans;
}
