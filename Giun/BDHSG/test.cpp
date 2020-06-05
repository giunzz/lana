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
cll esf = 1e-9;
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
    // cerr << sa*sb << " ";
    if(abs(sa - esf) <= esf && abs(sb - esf) <= esf) return 0;
    return (sa*sb <= 0);
}

bool ktracat2s(segment s1, segment s2){
    return (ktracat2diem(s1, s2.p1, s2.p2) && ktracat2diem(s2, s1.p1, s1.p2));
}

int main(){
    opt;
    //file;
    segment sg1, sg2;
    cin >> sg1.p1.x >> sg1.p1.y >> sg1.p2.x >> sg1.p2.y;
    cin >> sg2.p1.x >> sg2.p1.y >> sg2.p2.x >> sg2.p2.y;
    cout << ktracat2s(sg1, sg2);
}
