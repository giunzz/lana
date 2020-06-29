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

cll maxn = 1e6 + 7;
ll n;
struct point{
    ll x, y;
}p[maxn], pp[maxn];

bool cpr(point p1, point p2){
    if(p1.x * p2.y >= p2.x * p1.y) return 1;
    else return 0;
}

void cdOp(){
    lp(i, 2, n){
        if(p[i].y < p[1].y) swap(p[i], p[1]);
        else if(p[1].y == p[i].y && p[i].x < p[1].x) swap(p[i], p[1]);
    }
    lp(i, 2, n) p[i].x -= (p[1].x), p[i].y -= (p[1].y);
    p[1].x = 0, p[1].y = 0;
}

//tich co huong cua 2 vector a = (x, y, 0), b = (x, y, 0), [a, b] = p = (0, 0, a1b2 - a2b1)
ll ccw(point p1, point p2, point p3){
    point u, v;
    u.x = p2.x - p1.x;
    u.y = p2.y - p1.y;
    v.x = p3.x - p2.x;
    v.y = p3.y - p2.y;
    if(u.x * v.y - u.y * v.x >= 0) return 1;
    else return 0;
}

void outp(point p){
    cerr << p.x << " " << p.y;
}

ii main(){
    opt;
    file;
    cin >> n;
    lp(i, 1, n){
        cin >> p[i].x >> p[i].y;
    }
    cdOp();
    sort(p + 2, p + 1 + n, cpr);
    ll k = 2;
    pp[1] = p[1], pp[2] = p[2];
    lp(i, 3, n){
        while(!ccw(pp[k - 1], pp[k], p[i]) && k > 1) --k;
        pp[++k] = p[i];
    }
    // lp(i,1 , k){
    //     cout << pp[i].x << " " << pp[i].y << endl;
    // }

}
