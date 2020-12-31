#include<bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "f"
using namespace std;

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
    ll cs;
    cin >> cs;
    while(cs--){
        string s;
        cin >> s;
        vec(vec(ll)) dp(s.size(), vec(ll)(26, 0));
        ll mi = 0;
        lp(i, 1, s.size() - 1){
            mi = LLONG_MAX;
            if(i > 1 && s[i] == s[i - 2]) lp(j, 0, 'z' - 'a') if(dp[i - 2][j] != -1) mi = min(mi, dp[i - 2][j]);
            else lp(j, 0, 'z' - 'a') if(dp[i - 1][j] != -1) mi = min(mi, dp[i - 1][j]);
            if(mi == LLONG_MAX) mi = 0;
            // if(s[i] == s[i - 1]){
                // dp[i][s[i] - 'a'] = -1;
            lp(j, 0, 'z' - 'a'){
                if(j == s[i] - 'a' || (i > 1 && j == s[i - 1] - 'a')) dp[i][j] = -1;
                else dp[i][j] = mi + (j != s[i] - 'a');
            }
            // }
        }
        ll ans = LLONG_MAX;
        lp(i, 0, 'z' - 'a') if(dp[s.size() - 1][i] != -1) ans = min(ans, dp[s.size() - 1][i]);
        cout << ans << '\n';
    }
}