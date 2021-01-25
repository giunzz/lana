#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "machine"
#pragma GCC optimize("Ofast")
using namespace std;

void OF(){
    freopen(Fname ".inp", "r", stdin);
    freopen(Fname ".out", "w", stdout);
}

cll maxm = 1e5 + 7;
ll n, a[maxm] = {0}, euler[maxm] = {0};
bool d[maxm] = {0};

inline ll Phi(ll n) {
    if (n == 0) return 0;
    ll ans = n;
    for (ll x = 2; x*x <= n; ++x) {
        if (n % x == 0) {
            ans -= ans / x;
            while (n % x == 0) n /= x;
        }
    }
    if (n > 1) ans -= ans / n;
    return ans;
}

void phi(){
    euler[1] = euler[2] = 1;
    lp(i, 3, maxm - 1){
        euler[i] = Phi(i);
    }
}

ll ans = 0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0); 
    OF();
    cin >> n;
    phi();
    euler[1] = 0;
    lp(i, 1, n + 1){
        cin >> a[i];
        if(!d[a[i]]) ans += euler[a[i]];
        d[a[i]] = 1;
        for(ll j = 2; j * j <= a[i]; ++j){
            if(a[i] % j == 0){
                if(!d[j]) {
                    ans += euler[j];
                    d[j] = 1;
                }
                if(!d[a[i]/j]){
                    ans += euler[a[i]/j];
                    d[a[i]/j] = 1;
                }
            }
        }
        // cerr << ans << ' ';
    }
    cout << ans;
}

//hnoi
