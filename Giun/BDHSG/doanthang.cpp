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
    ii x1, y1, x2, y2;
};

vec(segment) seg, segans;

ii check(segment diem, ii x, ii y){
    return ((diem.y2 - diem.y1) * (x - diem.x1) + (diem.x1 - diem.x2) * (y - diem.y1));
}

int main(){
    opt;
    file;
    segment diem, tmp;
    lp(i, 0, 19){
        cin >> diem.x1 >> diem.y1 >> diem.x2 >> diem.y2;
        if(diem.x1 > diem.x2) {swap(diem.x1, diem.x2); swap(diem.y1, diem.y2);}
        if(diem.x1 == diem.x2 && diem.y1 > diem.y2) swap(diem.y1, diem.y2);
        seg.push_back(diem);
    }
    while(!seg.empty()){
        diem = seg.back();
        seg.pop_back();
        lp(i, 0, seg.size() - 1){
            // if((diem.x1 <= seg[i].x1 && seg[i].x1 <= diem.x2) || (seg[i].x1 <= diem.x1 && diem.x1 <= seg[i].x2)){
            //     if(!(check(diem, seg[i].x1, seg[i].y1) || check(diem, seg[i].x2, seg[i].y2))){
            //         if(diem.x1 < seg[i].x1) tmp.x1 = diem.x1, tmp.y1 = diem.y1;
            //         else if(diem.x1 > seg[i].x1) tmp.x1 = seg[i].x1, tmp.y1 = seg[i].y1;
            //         else if(diem.y1 < seg[i].y1) tmp.x1 = diem.x1, tmp.y1 = diem.y1;
            //         else tmp.x1 = diem.x1, tmp.y1 = seg[i].y1;
            //         if(diem.x2)
            //     }
            // }
            if(!(check(diem, seg[i].x1, seg[i].y1) || check(diem, seg[i].x2, seg[i].y2))){
                if(diem.x1 == diem.x2 == seg[i].x1 == seg[i].x2){

                }
                else{
                    if(diem.x1 < seg[i].x1 < diem.x2){
                        tmp.x1 = diem.x1, tmp.y1 = diem.y1;
                        if(seg[i].x2 < diem.x2) tmp.x2 = diem.x2, tmp.y2 = diem.y2;
                        else tmp.x2 = seg[i].x2, tmp.y2 = seg[i].y2;
                    }
                    else if(seg[i].x1 < diem.x1 < seg[i].x2){
                        tmp.x1 = seg[i].x1, tmp.y1 = seg[i].y1;
                        if()
                    }
                }
            }
        }
    }
}
