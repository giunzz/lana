#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "laugh"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll maxn = 1e3 + 7, maxs = 1e5 + 7;
ll n, dp[maxs] = {0};
string s, a[maxn];
unordered_map<string, bool> d;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n >> s;
    s = "0" + s;
    lp(i, 1, n){
        string q;
        cin >> q;
        d[q] = 1;
    }
    lp(i, 1, s.size() - 1){
        string tmp;
        lp(j, 1, 30){
            if(i + j - 1 > s.size()) break;
            tmp.push_back(s[i + j - 1]);
            if(d[tmp]) dp[j + i - 1] = max(dp[j + i - 1], dp[i - 1] + j);
        }
    }
    ll ans = 0;
    lp(i, 1, s.size() - 1) ans = max(ans, dp[i]);
    cout << ans; 
}