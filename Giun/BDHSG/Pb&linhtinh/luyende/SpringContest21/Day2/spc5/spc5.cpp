#include <bits/stdc++.h>
#define ll long long
#define cll const long long
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
using namespace std;

void file(const string file){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen((file + ".inp").c_str(), "r", stdin);
    freopen((file + ".out").c_str(), "w", stdout);
}

cll maxn = 507, MOD = 1e9 + 7;
string s;
ll dp[maxn][maxn][maxn];

int main(){
    file("spc5");
    ll cs;
    cin >> cs;
    dp[0][0][0] = 1;
    while(cs--){
        cin >> s;
        // cerr << s.size() << '\n';
        ll cnt = 0;
        for(char c : s) if(c == 'T') ++cnt;
        // cerr << cnt;
        s = '*' + s;
        lp(i, 1, s.size() - 1){
            lp(singleEye, 0, cnt){
                lp(halfEye, 0, cnt){
                    dp[i][singleEye][halfEye] = 0;
                    if(s[i] == '_'){
                        if(halfEye) (dp[i][singleEye][halfEye] += dp[i - 1][singleEye + 1][halfEye - 1] * (singleEye + 1)) %= MOD;
                        (dp[i][singleEye][halfEye] += dp[i - 1][singleEye][halfEye] * halfEye) %= MOD;
                    }
                    else{
                        if(singleEye) (dp[i][singleEye][halfEye] += dp[i - 1][singleEye - 1][halfEye]) %= MOD;
                        (dp[i][singleEye][halfEye] += dp[i - 1][singleEye][halfEye + 1] * (halfEye + 1)) %= MOD;
                    }
                } 
            }
        }
        cout << dp[s.size() - 1][0][0] << '\n';
    }
}