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

template <typename T> inline void Read(T &x){
    x = 0; char c;
    while(!isdigit(c = getchar()));
    do
    {
        x = x * 10 + c - '0';
    } while (isdigit(c = getchar()));
}

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

bool cpr(point &u, point &v){
    return ccw(a[1], u, v) == -1 || (ccw(a[1], u, v) == 0 && (u.second < v.second || (u.second == v.second && u.first < v.first)));
}

ll dis_p(point &a, point &b){
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

bool checkk(point &a, point &b, point &c){
    return dis_p(a, b) + dis_p(a, c) >= dis_p(b, c);
}

bool check_tri(point &a, point &b, point &c){
    return checkk(a, b, c) && checkk(a, c, b) && checkk(b, c, a);
}

void sol(){
    ans = 1e18;
    cin >> m;
    lp(i, 1, m) cin >> b[i].first >> b[i].second;
    cin >> n;
    lp(i, 1, n){
        cin >> a[i].first >> a[i].second; 
        // if(a[i].second < a[1].second || (a[i].second == a[1].second && a[i].first < a[1].first)) swap(a[1], a[i]);
    }
    // sort(a + 2, a + 1 + n, cpr);
    // sort(b + 1, b + 1 + m, cpr);
    a[0] = a[n];
    lp(i, 1, n) l[i] = line(a[i - 1], a[i]), l[i].rut();
    // xu ly diem vs 1 canh
    lp(i, 1, m) lp(j, 1, n){
        if(!check_tri(b[i], a[j], a[j - 1])) ans = min(ans, l[j].dis(b[i]));
    }
    ans /= 2.0;
    cout << setprecision(8) << fixed << ' ' << ans << '\n';
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    point p1 = {-1, 1}, p2 = {-5, 10}, p3 = {-2, 6};
    line test(p1, p2);
    test.rut();
    cerr << test.a << ' ' << test.b << ' ' << test.c << ' ' << test.dis(p3);
    EACHCASE sol();
}