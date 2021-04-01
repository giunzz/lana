#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "f"
using namespace std;

ll read(){
    ll tmp;
    cin >> tmp;
    return tmp;
}

void giuncute(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll mxm = 1e3 + 3;
ll n, m, dp[(1 << 10) + 3][mxm] = {{0}};

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n >> m;
    lp(mask, 0, (1 << n) - 1){
        bool ok = 0;
        lp(bit, 0, n - 2){
            if(((mask >> bit) & 1) + ((mask >> (bit + 1)) & 1) == 0) ok = 1;
        }
        if(ok) continue;
        ll nmask = (1 << n) - 1;
        lp(bit, 0, n - 2){
            if(((mask >> bit) & 1) + ((mask >> (bit + 1)) & 1) == 2) mask ^= (1 << bit);
        }
        if(((mask >> (n - 1)) & 1)) mask ^= 
    }
}