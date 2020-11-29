#include<bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "cake"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

using Point = pp(ll, ll);

cll maxn = 1e5 + 7;
ll n;
vec(Point) p;

#define x first
#define y second

ll area(Point a, Point b, Point c){
    Point ab = {b.x - a.x, b.y - a.y}, bc = {c.x - b.x, c.y - b.y};
    return ab.x * bc.y - ab.y * bc.x;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n;
    p.resize(n);
    ll ans = 0;
    for(Point &i : p) cin >> i.first >> i.second;
    lp(i, 0, p.size() - 4){
        ll a = i + 1, b = i + 2, c = i + 3, s = abs(area(p[i], p[a], p[b])) + abs(area(p[i], p[b], p[c]));
        ans = max(ans, s);
        bool ok = 1;
        while(ok){
            ok = 0;
            bool check = 1;
            while(c < p.size() - 1 && check){
                check = 0;
                ll nc = c + 1, ns = abs(area(p[i], p[a], p[b])) + abs(area(p[i], p[b], p[nc]));
                if(ns > s) s = ns, ++c, ok = 1, check = 1, ans = max(ans, s);
            }
            check = 1;
            while(b < c - 1 && check){
                check = 0;
                ll nb = b + 1, ns = abs(area(p[i], p[a], p[nb])) + abs(area(p[i], p[nb], p[c]));
                if(ns > s) s = ns, ++b, ok = 1, check = 1, ans = max(ans, s);
            }
            check = 1;
            while(a < b - 1 && check){
                check = 0;
                ll na = a + 1, ns = abs(area(p[i], p[na], p[b])) + abs(area(p[i], p[b], p[c]));
                if(ns > s) s = ns, ++a, ok = 1, check = 1, ans = max(ans, s);
            }
        }
        // ans = max(ans, s);
    }
    cout << (ans >> 1) << '.' << (ans & 1) * 5;
}