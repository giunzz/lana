#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "richnum"
using namespace std;

ll read(){
    ll tmp;
    cin >> tmp;
    return tmp;
}

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    ll l, r, cnt = 0;
    cin >> l >> r;
    lp(i, l, r){
        ll s = 1;
        for(ll j = 2; j * j <= i; ++j){
            if(i %j == 0){
                s += j + i/j;
                if(s/j == j) s -= j; 
            }
        }
        if(s > i) {++cnt;}
    }
    cout << cnt;
}