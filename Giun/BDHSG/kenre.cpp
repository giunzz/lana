#include <bits/stdc++.h>
#define ll long long
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define Fname "kenre"
using namespace std;

ll n;
vec(ll) a, b;

bool increase(vec(ll) &a, bool k, ll &res){
    ++res;
    if(k) for(ll i = 0; i < 2 * n - 1; i += 2) swap(a[i], a[i + 1]);
    else lp(i, 0, n - 1) swap(a[i], a[i + n]);
    if(a != b) return 1;
    return 0;
}

ll sol(bool k){
    ll res = 0;
    bool ok;
    a = b;
    do{
        k = !k, ok = 1;
        lp(i, 0, 2 * n - 2) if(a[i] > a[i + 1]) ok = 0;
        if(ok) break;
    } while(increase(a, k, res));
    return ok ? res : -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
    cin >> n;
    lp(i, 1, n << 1){ll num; cin >> num; a.push_back(n);}
    b = a;
    cout << min(sol(0), sol(1));
}
