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
ll n; 

bool operator<(point const &l, point const &r){
    return (l.x < r.x) || ((l.x == r.x) && (l.y < r.y));
}

void xl(){
    ll u, v, x;
    lp(i, 1, n){
        lp(j, i + 1, n){ //vt ij = (xj - xi, yj - yi)
            // if(i == j) continue;
            u = p[j].x - p[i].x;
            v = p[j].y - p[i].y;
            x = __gcd(abs(u), abs(v));
            if(!x) x = 1;
            u /= x, v /= x;
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
}
