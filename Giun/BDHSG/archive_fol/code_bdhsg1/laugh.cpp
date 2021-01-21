#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "laugh"
// #define Fname "f"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll maxn = 1e3 + 7, maxs = 1e5 + 7, mod = 1e9 + 9;
ll n, dp[maxs] = {0}, p[31];
string s, a[maxn];
// unordered_map<string, bool> d;
bool d[mod] = {0};

inline ll hashstr(string &t){
    ll hashnum = 0;
    lp(i, 0, t.size() - 1) (hashnum += (t[i] - 'a' + 1) * p[i]) %= mod;
    return hashnum;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n >> s;
    s = "0" + s;
    p[0] = 1;
    lp(i, 1, 30) p[i] = (p[i - 1] * 31) % mod;
    lp(i, 1, n){
        string q;
        cin >> q;
        d[hashstr(q)] = 1;
        // cerr << hashstr(q) << ' ' << q << '\n';
    }
    // cerr << d[39];
    lp(i, 1, s.size() - 1){
        ll tmp = 0;
        string x;
        lp(j, 1, 30){
            if(i + j - 1 >= s.size()) break;
            x.push_back(s[i + j - 1]);
            // tmp.push_back(s[i + j - 1]);
            (tmp += (s[i + j - 1] - 'a' + 1) * p[j - 1]) %= mod; 
            // cerr << x << ' ' << tmp << '\n';
            if(d[tmp]) dp[j + i - 1] = max(dp[j + i - 1], dp[i - 1] + j);
        }
    }
    ll ans = 0;
    lp(i, 1, s.size() - 1) ans = max(ans, dp[i]);
    cout << ans; 
}