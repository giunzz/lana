#include <bits/stdc++.h>
#define ll long long 
#define cll const long long
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define fname "f"
using namespace std;

cll maxn = 1e3 + 7;
ll gcd[(ll)1e3 + 7][(ll)1e3 + 7], n, a[maxn], Max, d[maxn];
vec(ll) ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    lp(i, 1, 1e3){
        lp(j, 1, 1e3) 
            gcd[i][j] = __gcd(i, j);
    }
    // freopen(fname".inp", "r", stdin);
    // freopen(fname".out", "w", stdout);
    ll q;
    cin >> q;
    while(q--){
        memset(d, 0, sizeof(d));
        ans.clear();
        Max = -1;
        cin >> n;
        lp(i, 1, n) {cin >> a[i]; Max = max(Max, a[i]);}
        lp(i, 1, n){
            ll tmp = 1, vt;
            lp(i, 1, n){
                if(gcd[a[i]][Max] >= tmp && !d[i]) tmp = gcd[a[i]][Max], vt = i; 
            }
            // cerr << vt << endl;
            ans.push_back(a[vt]);
            a[vt] = 1, Max = tmp, d[vt] = 1;
        }
        for(ll i : ans) cout << i << ' ';
        lp(i, 1, n) if(!d[i]) cout << a[i] << ' ';
        cout << '\n';
    }
}