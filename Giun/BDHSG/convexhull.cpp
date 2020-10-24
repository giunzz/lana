#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opoint ios_base::sync_with_stdio(0); cin.tie(0)
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

// bool cpr(point p1, point p2){
//     if(p1.x * p2.y >= p2.x * p1.y) return 1;
//     else return 0;
// }

// void cdOp(){ //tim diem co min y nho nhat neu min y = nhau tim min x 
//     lp(i, 2, n){
//         if(p[i].y < p[1].y) swap(p[i], p[1]);
//         else if(p[1].y == p[i].y && p[i].x < p[1].x) swap(p[i], p[1]);
//     }
//     lp(i, 2, n) p[i].x -= (p[1].x), p[i].y -= (p[1].y);
//     p[1].x = 0, p[1].y = 0;
// }

// //tich co huong cua 2 vector a = (x, y, 0), b = (x, y, 0), [a, b] = p = (0, 0, a1b2 - a2b1)
// ll ccw(point p1, point p2, point p3){
//     point u, v;
//     u.x = p2.x - p1.x;
//     u.y = p2.y - p1.y;
//     v.x = p3.x - p2.x;
//     v.y = p3.y - p2.y;
//     if(u.x * v.y - u.y * v.x >= 0) return 1;
//     else return 0;
// }

// ll getts(point p1, point p2, point p3){
//     point u, v;
//     u.x = p2.x - p1.x;
//     u.y = p2.y - p1.y;
//     v.x = p3.x - p1.x;
//     v.y = p3.y - p1.y;
//     return abs(u.x * v.y - u.y * v.x);
// }

// void getS(ll k){
//     double S = 0;
//     lp(i, 3, k){
//         S += getts(pp[i], pp[i - 1], pp[1]);
//     }
//     S /= 2;
//     cout << setprecision(1) << fixed << S;
// }

// void outp(point p){
//     cerr << p.x << " " << p.y;
// }


//Cach2
// bool cmp (point a, point b) {
//   return a.x < b.x || a.x == b.x && a.y < b.y;
// }

// bool cw (point a, point b, point c) { 
//   return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
// }

// bool ccw (point a, point b, point c) { 
//   return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
// }

// void convex_hull (vector<point> & a) {
//   if (a.size() == 1) { // chỉ có 1 điểm
//     return;
//   }
//   sort (a.begin(), a.end(), &cmp);
//   point p1 = a[0],  p2 = a.back();

//   vector<point> up, down;
//   up.push_back (p1);
//   down.push_back (p1);

//   for (size_t i=1; i<a.size(); ++i) {
//     if (i==a.size()-1 || cw (p1, a[i], p2)) {
//       while (up.size()>=2 && !cw (up[up.size()-2], up[up.size()-1], a[i]))
//         up.pop_back();
//       up.push_back (a[i]);
//     }
//     if (i==a.size()-1 || ccw (p1, a[i], p2)) {
//       while (down.size()>=2 && !ccw (down[down.size()-2], down[down.size()-1], a[i]))
//         down.pop_back();
//       down.push_back (a[i]);
//     }
//   }
//   a.clear();
//   for (size_t i=0; i<up.size(); ++i)
//     a.push_back (up[i]);
//   for (size_t i=down.size()-2; i>0; --i)
//     a.push_back (down[i]);
// }

ii main(){
    opoint;
    file;
    cin >> n;
    lp(i, 1, n){
        cin >> p[i].x >> p[i].y;
    }

    //Cach 2
    // vec(point) a;
    // convex_hull(a);

    //Cach 1
    // cdOp();
    // sort(p + 2, p + 1 + n, cpr);
    // ll k = 2;
    // pp[1] = p[1], pp[2] = p[2];
    // lp(i, 3, n){
    //     while(!ccw(pp[k - 1], pp[k], p[i]) && k > 1) --k;
    //     pp[++k] = p[i];
    // }
    // getS(k);
    // // lp(i,1 , k){
    // //     cout << pp[i].x << " " << pp[i].y << endl;
    // // }
}
