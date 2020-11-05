#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define lp(obj1, obj2, obj3) for(ll obj1 = obj2; obj1 <= obj3; obj1++)
#define lpd(obj1, obj2, obj3) for(ll obj1 = obj2; obj1 >= obj3; obj1--)
#define pp(obj1, obj2) pair<obj1, obj2>
#define vec(obj1) vector<obj1>
#define vecite(obj1) vector<obj1>::iterator
#define fi first
#define se second
#define mp(obj1, obj2) map<obj1, obj2>
#define st(obj) system((obj).c_str());
using namespace std;
cll MOD = 1e9 + 7;
const double esf = 1e-9;
const string tenfile = "tamgiacvuongbk";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".ans").c_str(), "w", stdout)

struct point{
    ll x, y;
};

cll maxn = 15e2 + 7;
ll n, ans = 0;
point p[maxn], p12, p23, p31;

ll tich(point p1, point p2){
    return (p1.x * p2.x + p1.y * p2.y);
}

int main(){
    opt;
    file;
    cin >> n;
    lp(i, 1, n) cin >> p[i].x >> p[i].y;
    lp(v1, 1, n){
        lp(v2, v1 + 1, n){
            lp(v3, v2 + 1, n){
                p12 = {p[v2].x - p[v1].x, p[v2].y - p[v1].y};
                p23 = {p[v3].x - p[v2].x, p[v3].y - p[v2].y};
                p31 = {p[v1].x - p[v3].x, p[v1].y - p[v3].y};
                if(!(tich(p12, p23) && tich(p23, p31) && tich(p31, p12))){
                    ++ans;
                }
            }
        }
    }
    cout << ans;
}
