#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define fname "f"
using namespace std;

void File(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(fname".inp", "r", stdin);
    freopen(fname".out", "w", stdout);
}

cll maxn = 1e5 + 7;
ll f[maxn] = {0}, n, a[maxn];

void upd(ll i, ll vl){
    while(i <= n){
        f[i] += vl;
        i += (i & -i);
    }
}

ll getS(ll l, ll r){
    ll ans = 0;
    while(r >= l){
        if((r & -r) >= l){
            ans += f[r];
            r -= (r & -r);
        }
        else{
            ans += a[r];
            --r;
        }
    }
    return ans;
}

int main(){
    File();
    cin >> n;
    lp(i, 1, n) {cin >> a[i]; upd(i, a[i]);}
    ll q, l, r, du, c;
    cin >> q;
    lp(i, 1, q){
        cin >> c >> l >> r;
        if(c == 1){
            upd(l, r);
        }
        else cout << getS(l, r) << endl;
    }
}