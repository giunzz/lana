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

// template <typename T> inline void Read(T &x){
//     x = 0; char c;
//     while(!isdigit(c = getchar()));
//     do
//     {
//         x = x * 10 + c - '0';
//     } while (isdigit(c = getchar()));
// }

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

// #define double long double
// #define point pp(double, double)

// cll mxn = 1e5 + 7;
// ll n;
// point p[mxn];

// int main(){
//     giuncute();
//     #ifndef ONLINE_JUDGE
//     OF();
//     #endif
//     cin >> n;
//     lp(i, 1, n) cin >> p[i].first >> p[i].second;
//     sort(p + 1, p + 1 + n);
//     double mxdis = 1e18;
//     set<point> s;
//     ll j = 0;
//     lp(i, 1, n){
//         while(p[i].first - p[j].first >= mxdis){
//             s.erase({p[j].second, p[j].first});
//             ++j;
//         }

//         auto p1 = s.lower_bound({p[i].second - mxdis, p[i].first});
//         auto p2 = s.upper_bound({p[i].second + mxdis, p[i].first});

//         for(auto pi = p1; pi != p2; ++pi){
//             double x = p[i].first - pi -> second, y = p[i].second - pi -> first;
//             mxdis = min(mxdis, sqrt(x * x + y * y));
//         }

//         s.insert({p[i].second, p[i].first});
//     }
//     cout << setprecision(3) << fixed << mxdis;
// }

#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "nearest"
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

#define point pp(double, double)

cll mxn = 1e5 + 7;
ll n;
vec(point) a, t;
double mindis = 1e18;

bool cpr_y(point &a, point &b){
    return a.second < b.second;
}

void upd(point &a, point &b){
    double dis = sqrt((b.first - a.first) * (b.first - a.first) + (b.second - a.second) * (b.second - a.second));
    if(dis < mindis) mindis = dis;
}

void sol(ll l, ll r){
    if(r - l < 2){
        lp(i, l, r) lp(j, i + 1, r) upd(a[i], a[j]);
        sort(a.begin() + l, a.begin() + r + 1, cpr_y);
        return;
    }
    ll mid = (l + r) >> 1, midx = a[mid + 1].first;
    sol(l, mid), sol(mid + 1, r);

    merge(a.begin() + l, a.begin() + mid + 1, a.begin() + mid + 1, a.begin() + r + 1, t.begin(), cpr_y);
    copy(t.begin(), t.begin() + r - l + 1, a.begin() + l);

    ll cnt = 0;
    lp(i, l, r) if(abs(a[i].first - midx) < mindis){
        for(ll j = cnt - 1; j >= 0 && a[i].second - t[j].second < mindis; --j) upd(a[i], t[j]);
        t[cnt++] = a[i];
    }
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    // cin >> n;
    scanf("%lld", &n);
    a.resize(n), t.resize(n);
    lp(i, 0, n - 1)
        // cin >> a[i].first >> a[i].second;
        scanf("%lf %lf", &a[i].first, &a[i].second);
    sort(a.begin(), a.end());
    sol(0, n - 1);
    // cout << setprecision(3) << fixed << mindis;
    printf("%0.3lf", mindis);
}