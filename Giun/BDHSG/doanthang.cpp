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

struct segment{
    ii x1, yy1, x2, y2;
};

vec(segment) seg, segans;
bool b = 0;

ii check(segment diem, ii x, ii y){
    return ((diem.y2 - diem.yy1) * (x - diem.x1) + (diem.x1 - diem.x2) * (y - diem.yy1));
}

int main(){
    opt;
    file;
    segment diem, tmp;
    lp(i, 0, 3){
        cin >> diem.x1 >> diem.yy1 >> diem.x2 >> diem.y2;
        if(diem.x1 > diem.x2) {swap(diem.x1, diem.x2); swap(diem.yy1, diem.y2);}
        if(diem.x1 == diem.x2 && diem.yy1 > diem.y2) swap(diem.yy1, diem.y2);
        seg.push_back(diem);
    }
    //    fprintf(stderr, "%d %d %d %d\n", seg[0].x1, seg[0].yy1, seg[0].x2, seg[0].y2);
    while(!seg.empty()){
        diem = seg.back();
        seg.pop_back();
        lp(i, 0, seg.size() - 1 && !seg.empty()){
            b = 0;
            if(!(check(diem, seg[i].x1, seg[i].yy1) || check(diem, seg[i].x2, seg[i].y2))){
                if(diem.x1 == diem.x2 && seg[i].x1 == seg[i].x2){
                    tmp.x1 = diem.x1, tmp.x2 = diem.x2;
                    // if(diem.yy1 == seg[i].yy1 && diem.y2 == seg[i].y2){
                    //     tmp.yy1 = diem.yy1, tmp.y2 = diem.y2, b = 1;
                    // }
<<<<<<< HEAD
                    if(diem.yy1 < seg[i].yy1 && seg[i].yy1 < diem.y2){
=======
        //fprintf(stderr, "%d %d %d %d %d %d\n", diem.yy1, diem.y2, seg[i].yy1, seg[i].y2, b, i);
                    if(diem.yy1 <= seg[i].yy1 && seg[i].yy1 <= diem.y2){
>>>>>>> ca8c0575587e81f424c5d9e3a82bdca8ec07fbf1
                        tmp.yy1 = diem.yy1, b = 1;
                        if(seg[i].y2 < diem.y2) tmp.y2 = diem.y2;
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
        // fprintf(stderr, "%d %d %d %d %d %d\n", tmp.x1, tmp.yy1, tmp.x2, tmp.y2, b, i);
                if(b) {seg.erase(seg.begin() + i); diem = tmp, i = -1;}
            }
        }
        // cerr << segans.size() << "\n";
        segans.push_back(diem);
    }
    // cerr << 1;
    lp(i, 0, segans.size() - 1){
        cout << segans[i].x1 << " " << segans[i].yy1 << " " << segans[i].x2 << " " << segans[i].y2 << endl;
    }
}

// 0 1 0 3
// 0 2 0 4
// 0 1 0 3
// 0 -1 0 0