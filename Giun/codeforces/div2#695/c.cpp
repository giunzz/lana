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

void compress(vec(ll) &a){
    set<ll> tmp(a.begin(), a.end());
    vec(ll) tmp1(tmp.begin(), tmp.end());
    a.clear();
    a = tmp1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    vec(vec(ll)) a(3);
    ll n[3];
    lp(i, 0, 2) cin >> n[i];
    lp(i, 0, 2){
        lp(j, 1, n[i]) a[i].push_back(read());
    }
    lp(i, 0, 2){
        compress(a[i]);
    }
    vec(vec(ll)) dp(3, vec(max(n[0], max(n[1], n[2])) + 2, LLONG_MAX));
    lp(i, 0, 2) dp[i][0] = 0;
    lp(i, 0, max(n[0], max(n[1], n[2])) - 1){
        ll nstat = i + 1;
        lp(j, 0, 2){
            if(nstat > n[j]){
                dp[j][nstat] = dp[j][i];
            }
            else{
                
            }
        }
    }
}