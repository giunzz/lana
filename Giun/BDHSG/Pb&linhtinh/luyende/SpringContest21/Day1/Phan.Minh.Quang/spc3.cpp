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

cll maxn = 2e5 + 7;
ll n, k, cnt[maxn], dp[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    file("spc3");
    ll cs;
    cin >> cs;
    while(cs--){
        cnt[0] = dp[0] = 0;
        ll ans = 0;
        cin >> n >> k;
        bool num;
        lp(i, 1, n){
            cin >> num;
            cnt[i] = cnt[i - 1] + !num;
            if(num || cnt[i] <= k){
                dp[i] = dp[i - 1] + 1;
            } else{
                dp[i] = i - (lower_bound(cnt, cnt + i + 1, cnt[i] - k) - cnt);
            }
            ans = max(ans, dp[i]);
        }
        cout << ans << '\n';
    }
}