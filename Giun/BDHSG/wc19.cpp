#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "f"
// #define Fname "dbg"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

ll n;
vec(bool) bit;
vec(vec(ll)) ans;

//tach ra bit tung vi tri bit push so i vao
//chia de tri

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n;
    lp(i, 1, n - 1){
        ll tmp = i;
        bit.clear();
        while(tmp){
            bit.push_back(tmp & 1);
            tmp >>= 1;
        }
        lp(j, 0, bit.size() - 1){
            // cerr << i << ' ';
            if(j + 1 >= ans.size())
                ans.push_back(vec(ll)());
            if(bit[j]){
                ans[j].push_back(i + 1);
            }
        }
    }
    cout << ans.size() << '\n';
    for(vec(ll) &v : ans){
        cout << v.size() << ' ';
        for(ll &z : v) cout << z << ' ';
        cout << '\n';
    }
}