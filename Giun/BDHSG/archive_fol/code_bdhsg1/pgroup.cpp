#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define Fname "pgroup"
using namespace std;

cll maxn = 1e5 + 7;
ll n, x, a[maxn], res = 0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(Fname ".inp", "r", stdin);
    freopen(Fname ".out", "w", stdout);
    cin >> n >> x;
    lp(i, 1, n) cin >> a[i];
    sort(a + 1, a + 1 + n);
    lpd(i, n, 1){
        if(a[i] > x) ++res;
        else{
            ll j = i;
            while(j > 0 && (i - j + 1) * a[j] <= x) --j;
            if(j > 0 && (i - j + 1) * a[j] > x) ++res;
            i = j; 
        }
    }
    cout << res;
}
