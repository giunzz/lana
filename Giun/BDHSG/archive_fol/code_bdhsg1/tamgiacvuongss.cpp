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
#define st(a) system((a).c_str())
#define filla(a, b) memset(a, b, sizeof(a))
using namespace std;
cll MOD = 1e9 + 7;
const double esf = 1e-9;
const string tenfile = "f";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

ll n;
cll maxn = 3e3 + 7;
ll dy[(ll)1e5 + 7], dx[(ll)1e5 + 7], ans = 0;
struct point{
    ll x = INT_MIN, y = INT_MIN;
}p[maxn];

bool operator<(point const &left, point const &right){
    return (left.x < right.x) || ((left.x == right.x) && (left.y < right.y));
}

bool operator==(point const &l, point const &r){
    return (l.x == r.x && l.y == r.y);
}

map<point, ll> a;

void xl(){
    sort(p + 1, p + 1 + n);
    vec(point) vtmp;
    lp(i, 1, n){
        if(!(p[i] == p[i - 1])) vtmp.push_back(p[i]);
    }
    n = vtmp.size();
    lp(i, 1, n){
        p[i] = vtmp[i - 1];
    }
}

ii main(){
    opt;
    file;
    cin >> n;
    filla(dx, 0); filla(dy, 0);
    lp(i, 1, n){
        cin >> p[i].x >> p[i].y;
    }
    xl();
    lp(i, 1, n){
        ++dx[p[i].x], ++dy[p[i].y];
        ++a[p[i]];
    }
    lp(i, 1, n){
        ans += (dx[p[i].x] - a[p[i]]) * (dy[p[i].y] - a[p[i]]);
    }
    cout << ans;
}
