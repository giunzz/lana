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

ll k;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> k;
    if(k == 0){
        cout << 0;
        return 0;
    }
    bool ok = 1;
    if(k < 0) ok = 0;
    k = abs(k);
    ll ans = LLONG_MAX, x, y;
    for(ll i = 1; i * i <= k; i++){
        if(!(k % i)){
            if(ok) x = i;
            else x = -i;
            y = k / i;
            if((x + y) & 1 || (x + y) < 0) continue;
            ans = min((x + y) / 2, ans);
        }
    }
    if(ans != LLONG_MAX) cout << ans;
    else cout << "none";
}