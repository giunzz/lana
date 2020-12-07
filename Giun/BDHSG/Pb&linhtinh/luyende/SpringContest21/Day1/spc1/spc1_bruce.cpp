#include <bits/stdc++.h>
#define ll long long
#define cll const long long
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
using namespace std;

void file(const string file){
    freopen((file + ".inp").c_str(), "r", stdin);
    freopen((file + ".out").c_str(), "w", stdout);
}

cll MOD = 1e9 + 7;

ll poww(ll i, ll k){
    if(k == 0) return 1;
    ll tmp = poww(i, k >> 1);
    if(i & 1) return ((tmp * tmp) % MOD) * i;
    return (tmp * tmp) % MOD;  
}

ll gt[1007];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    gt[0] = 1;
    lp(i, 1, 1000) gt[i] = (gt[i - 1] * i) % MOD;
    file("spc1");
    ll cs;
    cin >> cs;
    while(cs--){
        cin >> n >> k;
        ll s = 0, ans = 0;
        lp(i, 1, n){
            ll num;
            cin >> num;
            s += num;
        }
        
    }
}