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
const double esf = 1e-9;
const string tenfile = "army";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

struct sgmt{
    ii x1, yy1, x2, y2;
};

vec(sgmt) seg, segans;
bool b = 0;

ii check(sgmt diem, ii x, ii y){
    return ((diem.y2 - diem.yy1) * (x - diem.x1) + (diem.x1 - diem.x2) * (y - diem.yy1));
}

// ifstream fi1, fi2; ofstream fo1, fo2;

vec(sgmt) dtgop(ll ca){
    sgmt diem, tmp;
    lp(i, 0, ca - 1){
        cin >> diem.x1 >> diem.yy1 >> diem.x2 >> diem.y2;
        if(diem.x1 > diem.x2) {swap(diem.x1, diem.x2); swap(diem.yy1, diem.y2);}
        if(diem.x1 == diem.x2 && diem.yy1 > diem.y2) swap(diem.yy1, diem.y2);
        seg.push_back(diem);
    }
    while(!seg.empty()){
        diem = seg.back();
        seg.pop_back();
        lp(i, 0, seg.size() - 1 && !seg.empty()){
            b = 0;
            if(!(check(diem, seg[i].x1, seg[i].yy1) || check(diem, seg[i].x2, seg[i].y2))){
                if(diem.x1 == diem.x2 && seg[i].x1 == seg[i].x2){
                    tmp.x1 = diem.x1, tmp.x2 = diem.x2;
                    if(diem.yy1 <= seg[i].yy1 && seg[i].yy1 <= diem.y2){
                        tmp.yy1 = diem.yy1, b = 1;
                        if(seg[i].y2 <= diem.y2) tmp.y2 = diem.y2;
                        else tmp.y2 = seg[i].y2;
                    }
                    else if(seg[i].yy1 < diem.yy1 && diem.yy1 < seg[i].y2){
                        tmp.yy1 = seg[i].yy1, b = 1;
                        if(diem.y2 < seg[i].y2) tmp.y2 = seg[i].y2;
                        else tmp.y2 = diem.y2;
                    }
                }
                else{
                    if(diem.x1 <= seg[i].x1 && seg[i].x1 <= diem.x2){
                        tmp.x1 = diem.x1, tmp.yy1 = diem.yy1, b = 1;
                        if(seg[i].x2 <= diem.x2) tmp.x2 = diem.x2, tmp.y2 = diem.y2;
                        else tmp.x2 = seg[i].x2, tmp.y2 = seg[i].y2;
                    }
                    else if(seg[i].x1 < diem.x1 && diem.x1 < seg[i].x2){
                        tmp.x1 = seg[i].x1, tmp.yy1 = seg[i].yy1, b = 1;
                        if(diem.x2 < seg[i].x2) tmp.x2 = seg[i].x2, tmp.y2 = seg[i].y2;
                        else tmp.x2 = diem.x2, tmp.y2 = diem.y2;
                    }
                }
                if(b) {seg.erase(seg.begin() + i); diem = tmp, i = -1;}
            }
        }
        segans.push_back(diem);
    }
    // lp(i, 0, segans.size() - 1){
    //     fo1 << segans[i].x1 << " " << segans[i].yy1 << " " << segans[i].x2 << " " << segans[i].y2 << endl;
    // }
    // fo1.close(); fi1.close();
    return segans;
}

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
    if(abs(sa - esf) <= esf && abs(sb - esf) <= esf) return 0;
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
    double a1, b1, c1, a2, b2, c2;
    a1 = a.p2.y - a.p1.y;
    b1 = a.p1.x - a.p2.x;
    c1 = (a.p1.x - a.p2.x) * a.p1.y + (a.p2.y - a.p1.y) * a.p1.x;
    a2 = b.p2.y - b.p1.y;
    b2 = b.p1.x - b.p2.x;
    c2 = (b.p1.x - b.p2.x) * b.p1.y + (b.p2.y - b.p1.y) * b.p1.x;
    return giaihpt(a1, b1, c1, a2, b2, c2);
}

void dttg(){
    ll ans = 0;
    segment sg;
    // fi2.open("f.inp"); fo2.open("f.out");
    lp(i, 0, segans.size() - 1){
        // fi2 >> sg.p1.x >> sg.p1.y >> sg.p2.x >> sg.p2.y;
        sg.p1.x = segans[i].x1;
        sg.p1.y = segans[i].yy1;
        sg.p2.x = segans[i].x2;
        sg.p2.y = segans[i].y2;
        dt.push_back(sg);
    }
    lp(a, 0, dt.size() - 1){
        lp(b, a + 1, dt.size() - 1){
            lp(c, b + 1, dt.size() - 1){
                // cerr << ktracat2s(dt[a], dt[b]);
                if(ktracat2s(dt[a], dt[b]) && ktracat2s(dt[b], dt[c]) && ktracat2s(dt[c], dt[a])){
                    point ab = getgd(dt[a], dt[b]);
                    // cerr << ab.x << " " << ab.y;
                    point bc = getgd(dt[b], dt[c]);
                    point ca = getgd(dt[c], dt[a]);
                    if(abs(ab.x - bc.x) <= esf && abs(ab.y - bc.y) <= esf) continue;
                    ++ans;
                }
            }
        }
    }
    // fo2.open("army.out");
    cout << ans << "\n";    
    // fo2.close();
}

int main(){
    opt;
    file;
    // fi1.open("army.inp");
    ll n;
    cin >> n;
    dtgop(n);
    dttg();
}
