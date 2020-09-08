#include <bits/stdc++.h>
#define ll long long 
#define cll const long long
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define fname "f"
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen(fname".inp", "r", stdin);
    // freopen(fname".out", "w", stdout);
    ll q, n, tmp;
    cin >> q;
    while(q--){
        ll c1 = 0;
        cin >> n;
        lp(i, 1, n) {cin >> tmp; c1 += tmp;}
        if(c1 < n/2) {
            if(c1&1) ++c1;
            cout << (n - c1) << '\n';
            lp(i, 1, n - c1) cout << 0 << ' ';
        }
        else if (c1 > n/2){
            if(c1&1) --c1;
            cout << c1 << endl;
            lp(i, 1, c1) cout << 1 << ' ';
        }
        else{
            cout << c1 << '\n';
            lp(i, 1, c1) cout << 0 << ' ';
        }
        cout << endl;
    }
}