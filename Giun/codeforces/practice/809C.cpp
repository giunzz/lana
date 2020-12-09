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
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

ll dp[32][2][2][2], cnt[32][2][2][2];


// (i, j) -> ((x - 1) ^ (y - 1)) + 1

ll calc(ll x, ll y, ll k){
    
}

#define x first
#define y second

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    ll q;
    cin >> q;
    while(q--){
        pp(ll, ll) n[2];
        ll k;
        lp(i, 0, 1){cin >> n[i].x >> n[i].y; --n[i].x, --n[i].y;}
        cin >> k;
        // count x ^ y <= k - 1 (x1 <= x <= x2 && y1 <= y <= y2)
        memset()
        cout << sol(0, 0, 0);
    }
}