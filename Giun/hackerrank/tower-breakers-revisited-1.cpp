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

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll mxn = 1e6 + 7;
ll g[mxn], snt[mxn] = {0};

void sol(){
    ll n = read(), ans = 0;
    lp(i, 1, n) ans ^= g[read()];
    if(ans) cout << "1\n";
    else cout << "2\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    g[1] = 0, snt[1] = 1;
    lp(i, 2, 1e6){
        if(!snt[i]){
            snt[i] = -1;
            for(ll j = i * i; j <= 1e6; j += i){
                snt[j] = i;
            }
        }
    }
    lp(i, 2, 1e6){
        if(snt[i] == -1){
            g[i] = 1;
        }
        else g[i] = g[i / snt[i]] + 1;
    }
    EACHCASE sol();
}