#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "f"
using namespace std;

void OF(){
    freopen(Fname ".inp", "r", stdin);
    freopen(Fname ".out", "w", stdout);
}

// struct quang{
//     ll x, y;
// };

// struct quang1{
//     double x, y;
// };

struct quang2{
    pp(ll, ll) v;
    pp(double, double) m;
};

bool operator<(quang2 const &x, quang2 const &y){
    if(x.v < y.v) return 1;
    if(x.v == y.v && x.m < y.m) return 1;
    return 0;
}

ll n;
vec(pp(pp(ll, ll), pp(ll, ll))) a;
map<quang2, ll> mp;

#define x first
#define y second

void xuly(pp(ll, ll) &vt){
    if(vt.x < 0) vt.x *= -1, vt.y *= -1;
    else if(vt.x == 0 && vt.y) vt.y = 1;
    ll tmp = abs(__gcd(vt.x, vt.y));
    if(!tmp) tmp = 1;
    vt.x /= tmp, vt.y /= tmp;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n;
    a.resize(n);
    for(pp(ll, ll) &t : a){
        cin >> t.x >> t.y;
    }
    lp(i, 0, a.size() - 1){
        lp(j, i + 1, a.size() - 1){
            pp(ll, ll) vt = {a[j].x - a[i].x, a[j].y - a[i].y};
            pp(double, double) mid = {(a[j].x + a[i].x) / 2.0, (a[j].y + a[i].y) / 2.0};
            // cerr << i << ' ' << j << '\n';
            xuly(vt);
            quang2 tmp = {vt, mid};
            ++mp[tmp];
            // cerr << '\t' << vt.x << ' ' << vt.y << '\n';
            // cerr << '\t' << mid.x << ' ' << mid.y << '\n';
            // cerr << '\t' << mp[tmp] << '\n';
        }
    }

}