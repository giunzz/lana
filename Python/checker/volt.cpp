#include<bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "volt"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

ll n, a, b, c;
vec(double) r;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n >> a >> b >> c;
    r.resize(n + 3);
    lp(i, 1, n - 1){
        ll x;
        cin >> x;
        bool ok = 1;
        double rr = 0;
        lp(j, 1, x){
            ll r, co, t;
            cin >> r >> co;
            t = r * co;
            if(ok){
                if(!t) ok = 0, rr = 0;
                else rr += 1.0 / t;
            }
        }
        if(rr) r[i] = 1.0 / rr;
        else r[i] = 0;
    }
    double s = 0;
    lp(i, a, b - 1) s += r[i];
    ll ans = s * c;
    cout << ans;
}