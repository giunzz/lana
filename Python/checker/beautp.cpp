#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define lpdk(a, b, c, d) for(ll a = b; c; d) 
#define pp(a, b) pair<a, b>
#define vec(a) vector<a>
#define vecite(a) vector<a>::iterator
#define fi first
#define se second
using namespace std;
cll MOD = 1e9 + 7;
const string tenfile = "beautp";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cll maxn = 1e3 + 7;
ll n, a[maxn] = {0}, num, ans = 0;

int main(){
    opt;
    file;
    cin >> n;
    lp(i, 1, n) {cin >> num; ++a[num];}
    //lp(i, 1, 1000) cerr << a[i] << endl;
    // lp(i, 1, 999){
    //     lp(j, i + 1, 1000){
    //         if(a[i]-- && a[j]--){
    //             ++ans;
    //         }
    //     }
    // }
    ll pre, ok;
    for(ll i = 1; i <= 1000; ++i){
        for(ll j = 1; j <= 1000; ++j){
            if(!ok && a[j]) pre = j, ok = 1; 
            else if(a[j] != 0 && ok){
                // cerr << i << " " << j << endl;
                ++ans;
                --a[pre];
                pre = j;
            }
        }
        --a[pre];
        ok = 0;
    }
    cout << ans;
}
