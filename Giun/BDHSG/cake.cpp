#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "cake"
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

cll mxn = 1503;
ll n, ans = 0;
point p[mxn];

ll ccw(point &a, point &b, point &c){
    return (b.first - a.first) * (c.second - b.second) - (b.second - a.second) * (c.first - b.first);
}

ll area(point &a, point &b, point &c, point &d){
    return abs(ccw(a, b, c)) + abs(ccw(a, c, d));
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n;
    lp(i, 0, n - 1) cin >> p[i].first >> p[i].second;
    lp(x, 0, n - 1){
        ll i = (x + 1) % n, j = (x + 3) % n, tmp, tmpp;
        for(ll y = (x + 2) % n; ((y + 1) % n) != x; (++y) %= n){
            tmp = area(p[x], p[i], p[y], p[j]);
            bool ok = 1;
            while(ok){
                ok = 0;
                while((i + 1) % n != y && (tmpp = area(p[x], p[(i + 1) % n], p[y], p[j])) >= tmp) 
                    tmp = tmpp, (++i) %= n, ok = 1;
                while((j + 1) % n != x && (tmpp = area(p[x], p[i], p[y], p[(j + 1) % n])) >= tmp) 
                    tmp = tmpp, (++j) %= n, ok = 1;
            }
            ans = max(ans, tmp);
        }
    }
    cout << (ans >> 1) << '.' << ((ans & 1) * 5);   
}