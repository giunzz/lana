#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define lpdk(a, b, c, d) for(ll a = b; c; d) 
#define pp(a, b) pair<a, b>
#define vec(a) vector<a>
#define vecite(a) vector<a>::iterator
#define fi first
#define se second
using namespace std;
cll MOD = 1e9 + 7;
const string tenfile = "f";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

struct point{
    double x, y;
};

struct segment {
    point p1, p2;
};

vec(segment) dt;

double gettich(segment s, point a){
    return ((s.p2.y - s.p1.y) * (a.x - s.p1.x) + (s.p1.x - s.p2.x) * (a.y - s.p1.y));
}

bool ktracat2diem(segment s, point a, point b){
    double sa = gettich(s, a);
    double sb = gettich(s, b);
    return (sa*sb <= 0);
}

bool ktracat2s(segment s1, segment s2){
    return (ktracat2diem(s1, s2.p1, s2.p2) && ktracat2diem(s2, s1.p1, s1.p2));
}

point giaihpt(double a1, double b1, double c1, double a2, double b2, double c2){
    double D, Dx, Dy;
    D = a1 * b2 - a2 * b1;
    Dx = c1 * b2 - c2 * b1;
    Dy = a1 * c2 - a2 * c1;
    point gd;
    gd.x = Dx / D;
    gd.y = Dy / D;
    return gd;
}

point getgd(segment a, segment b){
    return giaihpt()
}

int main(){
    opt;
    file;
    segment sg;
    lp(i, 1, 20){
        cin >> sg.p1.x >> sg.p1.y >> sg.p2.x >> sg.p2.y;
        dt.push_back(sg);
    }
    lp(a, 0, dt.size() - 1){
        lp(b, a + 1, dt.size() - 1){
            lp(c, b + 1, dt.size() - 1){
                if(ktracat2s(dt[a], dt[b]) && ktracat2s(dt[b], dt[c]) && ktracat2s(dt[c], dt[a])){
                    point ab = getgd(dt[a], dt[b]);
                }
            }
        }
    }
}
