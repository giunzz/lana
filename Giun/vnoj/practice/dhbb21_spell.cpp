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

template <typename T> inline void Read(T &x){
    x = 0; char c;
    while(!isdigit(c = getchar()));
    do
    {
        x = x * 10 + c - '0';
    } while (isdigit(c = getchar()));
}

ll read(){
    ll tmp;
    cin >> tmp;
    return tmp;
}

void giuncute(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll mxn = 303, mxchar = 'Z' - 'A' + 1;
ll n, m, k, a[mxn][mxn];
vec(ll) dp[mxchar][mxn];
vec(pp(ll, ll)) posc[mxchar];
string s;

ll dis(pp(ll, ll) &u, pp(ll, ll) &v){return abs(u.first - v.first) + abs(u.second - v.second);}

ll sol(ll c, ll id, ll pos){
    if(~dp[c][id][pos]) return dp[c][id][pos];
    ll &cur = dp[c][id][pos];
    if(id == s.size() - 1) return cur = 0;
    cur = 1e18;
    ll nc = s[id + 1] - 'A', nid = id + 1, npos;
    lp(i, 0, posc[nc].size() - 1){
        npos = i;
        if(c == nc && i == pos){ 
            cur = min(cur, sol(nc, nid, npos) + dis(posc[c][pos], posc[nc][npos]) + 2);
            continue;
        }
        cur = min(cur, sol(nc, nid, npos) + dis(posc[c][pos], posc[nc][npos]));
    }
    return cur;
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    cin >> n >> m >> k >> s;
    lp(i, 1, n) lp(j, 1, m){
        char c;
        cin >> c;
        a[i][j] = c - 'A';
        posc[c - 'A'].push_back({i, j});
    }
    lp(i, 0, s.size() - 1)
        dp[s[i] - 'A'][i].assign(posc[s[i] - 'A'].size(), -1);
    // cerr << dp['B' - 'A'][3].size();
    ll ans = 1e18;
    lp(i, 0, posc[s[0] - 'A'].size() - 1) ans = min(ans, sol(s[0] - 'A', 0, i));
    // cerr << dp['B' - 'A'][5][0];
    cout << ans + 1;
}