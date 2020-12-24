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
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

#define point pp(ll, ll)
#define x first
#define y second

ll area(point &a, point &b, point &c){
    point ab = {b.x - a.x, b.y - a.y}, bc = {c.x - b.x, c.y - b.y};
    return ab.x * bc.y - ab.y * bc.x;
}

bool ccw(point &a, point &b, point &c){ 
    ll tmp = area(a, b, c);
    return tmp > 0; //re trai a -> b -> c
}

bool cw(point &a, point &b, point &c){
    return area(a, b, c) < 0; //re phai
}

// trai lon hon 0, phai < 0

cll maxn = 1e6 + 7;
ll n;
point a[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n;
    lp(i, 1, n){
        cin >> a[i].x >> a[i].y;
    }
    sort(a + 1, a + 1 + n);
    vec(point) up, down;
    point p1 = a[1], p2 = a[n];
    up.push_back(p1); down.push_back(p1);
    lp(i, 2, n){
        if(i == n || cw(up.back(), a[i], p2)){
            while(up.size() > 2 && !cw(up[up.size() - 2], up.back(), a[i])) up.pop_back();
            up.push_back(a[i]); 
        }
        if(i == n || ccw(down.back(), a[i], p2)){
            while(down.size() > 2 && !ccw(down[down.size() - 2], down.back(), a[i])) down.pop_back();
            down.push_back(a[i]);
        }
    } 
    cout << (up.size() + down.size() - 2) << '\n';
    for(point p : down) cout << p.x << ' ' << p.y << '\n';
    lpd(i, up.size() - 2, 1) cout << up[i].x << ' ' << up[i].y << '\n';
}