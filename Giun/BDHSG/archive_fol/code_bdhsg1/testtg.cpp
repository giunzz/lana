#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define lp(obj1, obj2, obj3) for(ll obj1 = obj2; obj1 <= obj3; obj1++)
#define lpd(obj1, obj2, obj3) for(ll obj1 = obj2; obj1 >= obj3; obj1--)
#define lpdk(obj1, obj2, obj3, obj4) for(ll obj1 = obj2; obj3; obj4) 
#define pp(obj1, obj2) pair<obj1, obj2>
#define vec(obj1) vector<obj1>
#define vecite(obj1) vector<obj1>::iterator
#define fi first
#define se second
using namespace std;
cll MOD = 1e9 + 7;
const double esf = 1e-9;
const string tenfile = "f";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

ll n, ans = 0;

struct point{
    ll x, y;
};

struct segment{
    point p1, p2;
    ll a, b, c; // ax + by + c = 0
};

vec(segment) dt;

void getabc(segment &s){
    s.a = s.p1.y - s.p2.y;
    s.b = s.p2.x - s.p1.x;
    s.c = (s.p1.x - s.p2.x) * s.p1.y + (s.p2.y - s.p1.y) * s.p1.x;
}

ll gettich(segment s, point p){
    return (s.a * p.x + s.b * p.y + s.c);
}

bool checkgiao(segment s1, segment s2){
    if(gettich(s1, s2.p1) == 0 && gettich(s1, s2.p2) == 0) return 0;
    ll tichs1v2diems2, tichs2v2diems1;
    tichs1v2diems2 = gettich(s1, s2.p1) * gettich(s1, s2.p2);
    tichs2v2diems1 = gettich(s2, s1.p1) * gettich(s2, s1.p2);
    return ((tichs1v2diems2 <= 0) && (tichs2v2diems1 <= 0));
}

ll checkdongquy(segment s1, segment s2, segment s3){
    ll f, g, h;
    f = s3.a * (s1.b * s2.c - s2.b * s1.c);
    g = s3.b * (s1.c * s2.a - s2.c * s1.a);
    h = s3.c * (s1.a * s2.b - s2.a * s1.b);
    return (f + g + h);
}

void prc(){
    lp(a, 0, dt.size() - 1){
        lp(b, a + 1, dt.size() - 1){
            lp(c, b + 1, dt.size() - 1){
                if (checkgiao(dt[a], dt[b]) && checkgiao(dt[b], dt[c]) && checkgiao(dt[c], dt[a]) && checkdongquy(dt[a], dt[b], dt[c])){
                    ++ans;
                    // cerr << a << " " << b << " " << c << endl;
                }                
            }
        }
    }
}

int main(){
    opt;
    file;
    segment sg;
    cin >> n;
    lp(i, 1, n){
        cin >> sg.p1.x >> sg.p1.y >> sg.p2.x >> sg.p2.y;
        getabc(sg);
        // cerr << sg.a << " " << sg.b << " " << sg.c;
        dt.push_back(sg);
    }
    prc();
    cout << ans;
}