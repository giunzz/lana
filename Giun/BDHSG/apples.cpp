#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "apples"
using namespace std;

void OF(){
    freopen(Fname ".inp", "r", stdin);
    freopen(Fname ".out", "w", stdout);
}

struct quang{
    ll x, y, id;
};

cll maxn = 1e6 + 7;
ll n, idd[maxn];
quang x[maxn], root;

inline bool ccw(quang a, quang b, quang c) { //a -> b -> c
  return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
}

bool cpr(quang const &a, quang const &b){
    return ccw(x[0], a, b);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n;
    lp(i, 1, n){
        cin >> x[i].x >> x[i].y;
        x[i].id = i;
        idd[x[i].id] = i;
        if(x[i].x < x[1].x || (x[i].x == x[1].x && x[i].y < x[1].y)) swap(x[1], x[i]);
    }
    sort(x + 2, x + 1 + n, cpr);
    cout << idd[x[1].id] << ' ' << idd[x[n/2+1].id];
}