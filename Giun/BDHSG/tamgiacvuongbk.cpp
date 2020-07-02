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
#define st(obj) system((obj).c_str());
using namespace std;
cll MOD = 1e9 + 7;
const double esf = 1e-9;
const string tenfile = "f";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cll maxn = 15e2 + 7;
struct point{
    ll x, y;
}p[maxn];
ll n, ans = 0; 

bool operator<(point const &l, point const &r){
    return (l.x < r.x) || ((l.x == r.x) && (l.y < r.y));
}

bool operator==(point const &l, point const &r){
    return (l.x == r.x && l.y == r.y);
}

map<point, ll> cntvt;

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

void prc(){
    ll tmp;
    point u, v;
    lp(i, 1, n){
        lp(j, i + 1, n){ //moi vector u = vt ij tim cac diem tao voi diem i la vector phap tuyen cua vt ij
            u.x = p[j].x - p[i].x;
            u.y = p[j].y - p[j].y;
            tmp = __gcd(abs(u.x), abs(u.y));
            if(!tmp) tmp = 1;
            u.x /= tmp, u.y /= tmp;
            if(u.x < 0) u.x *= -1, u.y *= -1;
            ++cnt[vt];
        }   
    }
}

ii main(){
    opt;
    file;
    cin >> n;  
    lp(i, 1, n){
        cin >> p[i].x >> p[i].y;
    }
    xl();
    prc();
}
