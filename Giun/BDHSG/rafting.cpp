// #include <bits/stdc++.h>
// #define ll long long
// #define cll const ll
// #define lp(a, b, c) for(ll a = b; a <= c; ++a)
// #define lpd(a, b, c) for(ll a = b; a >= c; --a)
// #define vec(a) vector<a>
// #define pp(a, b) pair<a, b>
// #define EACHCASE lpd(cs, read(), 1)
// #define Fname "f"
// using namespace std;

// ll read(){
//     ll tmp;
//     cin >> tmp;
//     return tmp;
// }

// void giuncute(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);
// }

// void OF(){
//     freopen(Fname".inp", "r", stdin);
//     freopen(Fname".out", "w", stdout);
// }

// #define point pp(ll, ll)
// #define segment pp(point, point)

// point mk_vec(point &a, point &b){
//     return {b.first - a.first, b.second - a.second};
// }

// struct line{
//     ll a, b, c;
//     void rut(){
//         ll gcd = __gcd(a, __gcd(b, c));
//         a /= gcd, b /= gcd, c /= gcd;
//     }
//     long double dis(point &p){
//         long double tu = a * p.first + b * p.second + c, mau = a * a + b * b;
//         return abs(tu) / sqrt(mau);
//     }
//     line(point &_a, point &_b){
//         point _vec = mk_vec(_a, _b);
//         a = -_vec.second;
//         b = _vec.first;
//         c = _a.first * _vec.second - _a.second * _vec.first;
//     }
//     line(){}
// };

// cll mxn = 107;
// ll n, m;
// point a[mxn], b[mxn];
// vec(segment) up_a, down_a, up_b, down_b;
// // a la da giac nho, b la da giac lon

// ll dis_p(point &a, point &b){
//     return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
// }

// bool check_tri(point &a, point &b, point &c){
//     ll tmp[3] = {dis_p(a, b), dis_p(a, c), dis_p(b, c)};
//     return tmp[0] + tmp[2] >= tmp[1] && tmp[1] + tmp[2] >= tmp[0];
// }

// void sol(){
//     cin >> n;
//     lp(i, 1, n) cin >> a[i].first >> a[i].second;
//     cin >> m;
//     lp(i, 1, m) cin >> b[i].first >> b[i].second;

//     up_a.clear(); down_a.clear();
//     a[0] = a[n];
//     lp(i, 1, n) 
//         if(a[i - 1] < a[i]) up_a.push_back({a[i - 1], a[i]});
//         else down_a.push_back({a[i], a[i - 1]});
//     sort(up_a.begin(), up_a.end());
//     sort(down_a.begin(), down_a.end());

//     up_b.clear(); down_b.clear();
//     b[0] = b[m];
//     lp(i, 1, m) 
//         if(b[i - 1] < b[i]) up_b.push_back({b[i - 1], b[i]});
//         else down_b.push_back({b[i], b[i - 1]});
//     sort(up_b.begin(), up_b.end());
//     sort(down_b.begin(), down_b.end());

//     // for(auto i : up_b) cerr << i.first.first << " " << i.first.second << " --> " << i.second.first << ' ' << i.second.second << '\n';

//     // xu ly up
//     long double ans = 1e18, tmp;
//     line la, lb;
//     ll j = 0;
//     lp(i, 0, up_a.size() - 1){
//         while(j < up_b.size() && up_b[j].second < up_a[i].first) ++j;
//         if(j == up_b.size()) break;
//         la = line(up_a[i].first, up_a[i].second);
//         la.rut();
//         --j;
//         while(1){
//             ++j;
//             if(j == up_b.size()) break;
//             lb = line(up_b[j].first, up_b[j].second);
//             lb.rut();

//             if(check_tri(up_a[i].first, up_b[j].first, up_b[j].second)) ans = min(ans, lb.dis(up_a[i].first));
//             if(check_tri(up_a[i].second, up_b[j].first, up_b[j].second)) ans = min(ans, lb.dis(up_a[i].second));
//             if(check_tri(up_b[i].second, up_a[j].first, up_a[j].second)) ans = min(ans, la.dis(up_b[i].second));
//             if(check_tri(up_b[i].first, up_a[j].first, up_a[j].second)) ans = min(ans, la.dis(up_b[i].first));

//             if(up_b[j].second > up_a[i].second) break;
//         }
//     }

//     //xu ly down
//     j = 0;
//     lp(i, 0, down_a.size() - 1){
//         while(j < down_b.size() && down_b[j].second < down_a[i].first) ++j;
//         if(j == down_b.size()) break;
//         la = line(down_a[i].first, down_a[i].second);
//         la.rut();
//         --j;
//         while(1){
//             ++j;
//             if(j == down_b.size()) break;
//             lb = line(down_b[j].first, down_b[j].second);
//             lb.rut();

//             if(check_tri(down_a[i].first, down_b[j].first, down_b[j].second)) ans = min(ans, lb.dis(down_a[i].first));
//             if(check_tri(down_a[i].second, down_b[j].first, down_b[j].second)) ans = min(ans, lb.dis(down_a[i].second));
//             if(check_tri(down_b[i].second, down_a[j].first, down_a[j].second)) ans = min(ans, la.dis(down_b[i].second));
//             if(check_tri(down_b[i].first, down_a[j].first, down_a[j].second)) ans = min(ans, la.dis(down_b[i].first));

//             if(down_b[j].second > down_a[i].second) break;
//         }
//     }

//     cout << setprecision(8) << fixed << ans / 2.0 << '\n';
// }

// int main(){
//     giuncute();
//     #ifndef ONLINE_JUDGE
//     OF();
//     #endif
//     EACHCASE sol();
// }

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