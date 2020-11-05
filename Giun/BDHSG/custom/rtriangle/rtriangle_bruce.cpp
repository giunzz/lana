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
#define setE(a, b) fill_n(a, sizeof(a)/sizeof(a[0]), b)
#define st(a) system((a).c_str());
using namespace std;
cll MOD = 1e9 + 7;
const double esf = 1e-9;
const string tenfile = "rtriangle";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".ans").c_str(), "w", stdout)
struct quang{
    ll x, y, stt = 0;
    quang() : x(0), y(0) {}
    quang(ll x, ll y) : x(x), y(y) {}
    inline void quay(){
        swap(x, y);
        y = -y, ++stt;
    }
    inline bool check() const{
        if(!x && !y) return 0;
        return (x < 0 || y < 0);
    }
};
bool operator<(const quang &a, const quang &b){  //xa / ya && xb /yb
    if(a.x * b.y == b.x * a.y) return(a.x - a.y < b.x - b.y);
    return a.x * b.y > b.x * a.y;
}
bool operator==(const quang &a, const quang&b){
    return a.x*b.y == b.x*a.y;
}
ll n;
vec(quang) point, pt;
vec(ll) cnt[4];
//map<quang, pp(ll, ll)> cnt[4];
void init(){
    lp(i, 1, n){
        cin >> point[i].x >> point[i].y;
    }
}
int main(){
    opt;
    file;
    cin >> n;
    ll vt, res = 0;
    point.resize(n + 1);
    init();
    pt.resize(n + 1);
    lp(i, 1, n){
        vt = 0;
        lp(j, 0, 3){cnt[j].clear(); cnt[j].push_back(0);}
        lp(j, 1, n){
            pt[j].stt = 0;
            pt[j].x = point[j].x - point[i].x;
            pt[j].y = point[j].y - point[i].y;
            while(pt[j].check()) pt[j].quay();
            if(i == 1) cerr << pt[j].x << ' ' << pt[j].y << ' ' << pt[j].stt << '\n';
        }
        // cerr << i << ' ';
        sort(pt.begin() + 1, pt.end());
        // if(i == 2) lp(j, 1, n) cerr << pt[j].x << ' ' << pt[j].y << ' ' << pt[j].stt  << '\n';
        ++cnt[pt[2].stt][0];
        lp(j, 3, n){
            if(pt[j] == pt[j - 1]) 
                ++cnt[pt[j].stt][vt];
            else{
                lp(z, 0, 3) cnt[z].push_back(0);
                ++cnt[pt[j].stt][++vt];
            }
        }
        lp(j, 0, vt){
            res += cnt[0][j]*cnt[3][j] + cnt[3][j]*cnt[2][j] + cnt[2][j]*cnt[1][j] + cnt[1][j]*cnt[0][j];
        }
        // cerr << res << '\n';
    }
    cout << res;
}