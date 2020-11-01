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
    freopen(Fname ".inp", "r", stdin);
    freopen(Fname ".out", "w", stdout);
}

cll maxn = 1e6 + 7;
ll n, a[maxn], f[maxn] = {0}, tv[maxn] = {0};
vec(ll) res;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n;
    lp(i, 1, n) cin >> a[i];
    if(n < 3) {cout << 0; return 0;}
    if(a[1] != a[2] && a[1] != a[3] && f[3] < a[1]) f[3] = a[1], tv[3] = 1;
    if(a[2] != a[1] && a[2] != a[3] && f[3] < a[2]) f[3] = a[2], tv[3] = 2;
    if(a[1] != a[3] && a[2] != a[3] && f[3] < a[3]) f[3] = a[3], tv[3] = 3;
    ll ans = f[3];
    lp(i, 4, n){
        f[i] = max(f[i - 2], max(f[i - 1], f[i - 3]));
        if(f[i] == f[i - 1]) tv[i] = i - 1;
        else if(f[i] == f[i - 2]) tv[i] = i - 2;
        else tv[i] = i - 3;
        if(a[i] != a[i - 1] && a[i] != a[i - 2]){
            f[i] = max(f[i], a[i] + f[i - 3]);
            if(a[i] + f[i - 3] == f[i]) tv[i] = i - 3;
        }
        ans = max(f[i], ans);
    }
    cout << ans << '\n';
    ll j = n;
    while(f[j] != ans) --j;
    while(j > 3){
        if(a[j] + f[j - 3] == f[j]) res.push_back(j);
        j = tv[j];
    }
    if(j == 3) res.push_back(tv[3]);
    reverse(res.begin(), res.end());
    for(ll &x : res) cout << x << ' ';
}