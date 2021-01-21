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
// const string tenfile = "f";
const string tenfile = "baoloi";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

ll n;
struct point{
    ll x, y;
};

bool cmp (point const &a, point const &b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

//Xba*Ybc - Yba*Xbc > 0 thi a -> b -> c re phai

bool cw(point a, point b, point c) { 
  return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) <= 0;
}

bool ccw(point a, point b, point c) { 
  return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) >= 0;
}

void bl(vec(point) &a) {
    if(a.size() == 1) return;
    sort(a.begin(), a.end(), cmp);
    point p1 = a[0], p2 = a.back();
    vector<point> up, down;
    up.push_back(p1);
    down.push_back(p1);
    lp(i, 1, a.size() - 1)
        if(i == a.size() - 1 || cw(p1, a[i], p2)){
            while (up.size() >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], a[i]))
                up.pop_back();
            up.push_back(a[i]);
        }
    lp(i, 1, a.size() - 1)
        if(i == a.size() - 1 || ccw(p1, a[i], p2)){
            while (down.size() >= 2 && !ccw(down[down.size() - 2], down[down.size() - 1], a[i])) 
                down.pop_back();
            down.push_back(a[i]);
        }
    a.clear();
    lp(i, 0, up.size() - 1) a.push_back(up[i]);
    lpd(i, down.size() - 2, 1) a.push_back(down[i]);
}

ii main(){
    opt;
    file;
    cin >> n;
    vec(point) a;
    point tmp;
    lp(i, 1, n){
        cin >> tmp.x >> tmp.y;
        a.push_back(tmp);
    }
    bl(a);
    cout << a.size() << '\n';
    for(point &t : a){
        cout << t.x << ' ' << t.y << '\n';
    }
}
