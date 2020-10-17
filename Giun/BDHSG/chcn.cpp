#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "chcn"
using namespace std;

void OF(){
    freopen(Fname ".inp", "r", stdin);
    freopen(Fname ".out", "w", stdout);
}

cll maxn = 1e5 + 7;
ll n, f[maxn], ma = 0, rr[maxn];
pp(ll, ll) a[maxn];

#define d first
#define r second

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n;
    f[0] = 0, rr[0] = 0;
    lp(i, 1, n) {cin >> a[i].r >> a[i].d; ma = max(ma, a[i].d);}
    sort(a + 1, a + 1 + n);
    lpd(i, n, 1){
        rr[i] = rr[i + 1] + a[i].r; 
        f[i] = f[i + 1] + a[i].r * a[i].d;
    }   
    ll top = 1, res = LLONG_MAX, tmp, ans;
    lp(i, 0, ma){
        while(a[top].d < i) ++top;
        tmp = abs(f[1] - 2 * f[top] + 2 * rr[top] * i);
        // res = min(res, abs(f[1] - f[top] + r[top] * i - (f[top] - r[top] * i)));
        if(res > tmp){
            res = tmp; ans = i;
            // cerr << ans << ' ' << res << '\n';
        }
    }
    cout << ans;
}