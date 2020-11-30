#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "rel"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

#define x first
#define y second
#define rt 1
#define lt -1
#define ga 0

using point = pp(ll, ll); 
cll maxn = 1e5 + 7;
ll n, m, l, r, res[maxn] = {0}; 
point sh[maxn], cp[maxn];

inline ll area(point &a, point &b, point &c){
    point vecab = {b.x - a.x, b.y - a.y}, vecbc = {c.x - b.x, c.y - b.y};
    return vecab.x * vecbc.y - vecbc.x *  vecab.y;
}

inline ll ccw(point a, point b, point c){
    ll s = area(a, b, c);
    if(s > 0) return 1;
    if(!s) return 0;
    return -1;
}

void prc(){
    ll direction;
    lp(i, 1, m){
        ll pre = ccw(sh[1], cp[i], cp[i - 1]), next = ccw(sh[1], cp[i], cp[i + 1]);
        if(pre * -1 == next) continue;
        if(next == 1) r = i;
        else if(pre == -1) l = i;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n;
    lp(i, 1, n){
        ll x, y;
        cin >> x >> y;
        sh[i] = {x, y};
    }
    cin >> m;
    lp(i, 1, m){
        ll x, y;
        cin >> x >> y;
        cp[i] = {x, y};
    }
    cp[0] = cp[m], cp[m + 1] = cp[1];
    prc(); // find 2 tangent of sh1 to convex polygon
    cerr << l << ' ' << r;

}

/*
https://geogebra.org/classic/rjhvxukk
https://developer.mozilla.org/en-US/docs/Learn/Server-side/Express_Nodejs
https://nodejs.dev/learn
https://onedrive.live.com/?authkey=%21ANfPeYx6k3o2AKA&id=A6081E19970D24F2%2124698&cid=A6081E19970D24F2
*/