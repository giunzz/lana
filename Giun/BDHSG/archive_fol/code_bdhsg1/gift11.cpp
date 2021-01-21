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

cll MOD = 998244353, maxn = 2e3 + 7;
ll n, a[maxn], s[maxn] = {0}, cnt[maxn] = {0};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    ll cs;
    for(cin >> cs; cs--;){
        cin >> n;
        vec(vec(vec(ll))) dp(n + 1, vec(vec(ll))(n + 1, vec(ll)(2, 0)));
        lp(i, 1, n) dp[1][i][1] = 1;
        lp(i, 1, n){
            cin >> a[i];
            s[i] = cnt[i] = 0;
            ll tmp = a[i];
            int d = -1;
            while(tmp){
                d = -d, ++cnt[i];
                s[i] += d * (tmp % 10);
                tmp /= 10;
            }
            if(d == -1) s[i] = -s[i];
        }
        lp(pos, 1, n){
            lp(i, 1, n){
                lp(stt, 0, 1){
                    if(!dp[pos][i][stt]) continue;
                    ll cur = dp[pos][i][stt];
                    
                }
            }
        }
    }
}