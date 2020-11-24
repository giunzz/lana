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

cll maxn = 1e5 + 7;
ll n, m, l, r; 
pp(ll, ll) sh[maxn], cp[maxn];

#define x first
#define y second
#define rt 1
#define lt -1
#define ga 0

inline ll area(pp(ll, ll) &a, pp(ll, ll) &b, pp(ll, ll) &c){
    pp(ll, ll) vecab = {b.x - a.x, b.y - a.y}, vecbc = {c.x - b.x, c.y - b.y};
    return vecab.x * vecbc.y - vecbc.x *  vecab.y;
}

ll ccw(pp(ll, ll) a, pp(ll, ll) b, pp(ll, ll) c){
    ll s = area(a, b, c);
    if(s > 0) return 1;
    if(!s) return 0;
    return -1;
}

vec(pp(ll, ll)) r;

void prc(){
    ll rq;
    lp(i, 0, n - 1){
        if((rq = ccw(sh[1], cp[i], cp[(i + 1) % n])) == ccw(sh[i], cp[i], cp[(i - 1 + n) % n])){
            if(rq == lt) l = i;
            else r = i;
        }
    }
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n;
    lp(i, 0, n - 1){
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

}