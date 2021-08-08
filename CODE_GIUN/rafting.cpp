#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "f"
using namespace std;

ll read(){
    ll tmp;
    cin >> tmp;
    return tmp;
}

void giuncute(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

#define point pp(ll, ll)

cll mxn = 107;
ll n, m;
point a[mxn], b[mxn];
long double ans;

point mk_vec(point &a, point &b){
    return {b.first - a.first, b.second - a.second};
}

struct line{
    ll a, b, c;
    void rut(){
        ll gcd = __gcd(a, __gcd(b, c));
        a /= gcd, b /= gcd, c /= gcd;
    }
    long double dis(point &p){
        long double tu = a * p.first + b * p.second + c, mau = a * a + b * b;
        return abs(tu) / sqrt(mau);
    }
    line(point &_a, point &_b){
        point _vec = mk_vec(_a, _b);
        a = -_vec.second;
        b = _vec.first;
        c = _a.first * _vec.second - _a.second * _vec.first;
    }
    line(){}
} l[mxn];

int ccw(point &a, point &b, point &c){
    ll tmp = (b.first - a.first) * (c.second - b.second) - (b.second - a.second) * (c.first - b.first);
    if(tmp < 0) return -1;
    else return tmp > 0;
}

ll dis_p(point &a, point &b){
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

bool check_tri(point &a, point &b, point &c){
    // vector<ll> tmp{dis_p(a, b), dis_p(a, c), dis_p(b, c)};
    ll tmp[3] = {dis_p(a, b), dis_p(a, c), dis_p(b, c)};
    return tmp[0] + tmp[2] >= tmp[1] && tmp[1] + tmp[2] >= tmp[0];
}

void sol(){
    ans = 1e18;
    cin >> m;
    lp(i, 1, m) cin >> b[i].first >> b[i].second;
    cin >> n;
    lp(i, 1, n) cin >> a[i].first >> a[i].second; 

    a[0] = a[n];
    lp(i, 1, n) l[i] = line(a[i - 1], a[i]), l[i].rut();
    // xu ly diem vs 1 canh
    lp(i, 1, m) lp(j, 1, n){
        ans = min(ans, sqrt((long double) dis_p(b[i], a[j])));
        if(check_tri(b[i], a[j], a[j - 1])){
            ans = min(ans, l[j].dis(b[i]));
        }
    }

    b[0] = b[m];
    lp(i, 1, m) l[i] = line(b[i - 1], b[i]), l[i].rut();
    // xu ly diem vs 1 canh
    lp(i, 1, n) lp(j, 1, m){
        if(check_tri(a[i], b[j], b[j - 1])){
            ans = min(ans, l[j].dis(a[i]));
        }
    }

    ans /= 2.0;
    cout << setprecision(8) << fixed << ' ' << ans << '\n';
}

int main(){
    giuncute();
    EACHCASE sol();
}