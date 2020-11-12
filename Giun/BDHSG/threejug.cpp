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

ll d, q;
pp(ll, ll) t[3];

#define dt first
#define w second

bool cpr(pp(ll, ll) &a, pp(ll, ll) &b){
    if(a.w % d != q % d) return 0;
    if(b.w % d != q % d) return 1;
    if(a.dt < q) return 0;
    if(b.dt < q) return 1;
    if(a.w > b.w) return 1; 
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // OF();
    lp(i, 0, 2) cin >> t[i].dt;
    lp(i, 0, 2) cin >> t[i].w;
    cin >> d >> q;
    //process 3 bottles
    sort(t, t + 3, cpr);
    if(t[0].dt < q || t[0].w % d != q % d){
        cout << "-1";
        return 0;
    }
    ll tg = (q - t[0].w) / d;
    if(t[1].w / d + t[2].w / d >= tg){
        cout << tg;
    }
    else cout << "-1";
}
