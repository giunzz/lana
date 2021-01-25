#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define point pp(ll, ll)
// #define Fname "triland"
#define Fname "f"
using namespace std;

void OF(){
    freopen(Fname ".inp", "r", stdin);
    freopen(Fname ".out", "w", stdout);
}

#define x first 
#define y second


bool cmp (point const &a, point const &b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

//Xba*Ybc - Yba*Xbc > 0 thi a -> b -> c re phai

bool cw(point a, point b, point c) { 
  return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) <= 0;
}

bool ccw(point a, point b, point c) { 
  return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) >= 0;
}

void bl(vec(point) &a) {
    if(a.size() == 1) return;
    sort(a.begin(), a.end(), cmp);
    point p1 = a[0], p2 = a.back();
    vector<point> up, down;
    up.push_back(p1);
    down.push_back(p1);
    lp(i, 1, a.size() - 1)
        if(i == a.size() - 1 || cw(p1, a[i], p2)){
            while (up.size() >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], a[i]))
                up.pop_back();
            up.push_back(a[i]);
        }
    lp(i, 1, a.size() - 1)
        if(i == a.size() - 1 || ccw(p1, a[i], p2)){
            while (down.size() >= 2 && !ccw(down[down.size() - 2], down[down.size() - 1], a[i])) 
                down.pop_back();
            down.push_back(a[i]);
        }
    a.clear();
    lp(i, 0, up.size() - 1) a.push_back(up[i]);
    lpd(i, down.size() - 2, 1) a.push_back(down[i]);
}

inline ll S(point &a, point &b, point &c){
    ll xba = a.x - b.x, xbc = c.x - b.x;
    ll yba = a.y - b.y, ybc = c.y - b.y;
    return abs(xba * ybc - yba * xbc);
}

cll maxn = 3e4 + 7;
ll n;
pp(ll, ll) a[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n;
    lp(i, 1, n){
        cin >> a[i].x >> a[i].y;
    }
    vec(pp(ll, ll)) ch(a + 1, a + 1 + n);
    bl(ch);
    // for(auto i : ch){
    //     cerr << i.x  << ' ' << i.y << '\n';
    // }
    ll cnt = n, area = 0;
    lp(x, 0, ch.size() - 1){
        ll i = (x + 1) % ch.size(), j = (x + 2) % ch.size(), ma = S(ch[x], ch[i], ch[j]);
        while(1){
            bool ok = 0;
            while(S(ch[x], ch[i], ch[(j + 1)%ch.size()]) >= ma && j != x) 
                ma = S(ch[x], ch[i], ch[(j + 1)%ch.size()]), j = (j + 1) % ch.size(), ok = 1;
            while(S(ch[x], ch[(i + 1)%ch.size()], ch[j]) >= ma && i != x && i != j) 
                ma = S(ch[x], ch[(i + 1)%ch.size()], ch[j]), i = (i + 1) % ch.size(), ok = 1;
            if(ma > area) area = ma;
            // if(ma == S(ch[x], ch[i], ch[j])) break;
            if(!ok) break;
        }
    }
    cout << area/2;
    if(area % 2) cout << ".5";
    else cout << ".0";
}