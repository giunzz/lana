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

struct quang{
    ll x, y, cnt = 1;
};

cll maxn = 1e3 + 7;
ll n, m, r;
quang a[maxn];

void init(){
    ll x, y;
    lp(i, 1, n){
        cin >> a[i].x >> a[i].y;
    }
    lp(i, 1, m){
        cin >> x >> y;
        
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n >> m >> r;
    init();
}