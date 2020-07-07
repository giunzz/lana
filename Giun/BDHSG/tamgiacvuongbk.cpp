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
struct line{
    ll a, b, c;
};
ll n, ans = 0;
point p[maxn]; 

bool operator<(point const &l, point const &r){
    return (l.x < r.x) || ((l.x == r.x) && (l.y < r.y));
}

bool operator==(point const &l, point const &r){
    return (l.x == r.x && l.y == r.y);
}

vec(line) aldt;
map<line, ll> cntp;

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

void getPT(point p1, point p2, point pr, point pt){
    point cp = {p2.x - p1.x, p2.y - p1.y};
    pt = {-cp.y, cp.x};
    ll r = __gcd(abs(pt.x), abs(pt.y));
    if(!r) r = 1;
    pt.x /= r, pt.y /= r;
    if(pt.x < 0) pt.x *= -1, pt.y *= -1;
    pr = p1;
}

void getabc(line d, point pt, point pr){
    d.a = pt.x, d.b = pt.y; d.c = -(pt.x*pr.x + pt.y*pr.y);
    ll r = __gcd(abs(d.a), __gcd(abs(d.b), abs(d.c)));
    if(!r) r = 1;
    d.a /= r, d.b /= r, d.c /= r;
}

void xld(line d){
    if(d.a < 0) d.a *= -1, d.b *= -1, d.c *= -1;
}

bool check(line d, point pnt){
    return !(d.a * pnt.x + d.b * pnt.y + d.c);
}

void prc(){
    map<line, ll> cntdt;
    line tmp;
    point p1, p2, pr, pt;
    lp(i, 1, n){
        lp(j, i + 1, n){ //moi vector u = vt ij tim cac diem tao voi diem i la vector phap tuyen cua vt ij
            p1 = p[i], p2 = p[j];
            getPT(&p1, &p2, &pr, &pt);
            getabc(&tmp, &pt, &pr);
            xld(&tmp);
            if(!cntdt[tmp]++) aldt.push_back(tmp);
        }   
    }
    lp(i, 1, n){
        lp(j, 0, aldt.size() - 1){
            if(check(aldt[j], p[i])) ++cntp[aldt[j]];
        }
    }
}

void cnttg(){
    point u, v;
    lp(i, 1, n){
        lp(j, i + 1, n){

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
    //xl();
    prc();
    cnttg();
}
