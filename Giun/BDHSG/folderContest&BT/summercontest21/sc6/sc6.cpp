#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define EACHCASE lpd(cs, read(), 1)
#define Fname "sc6"
using namespace std;

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

#define type second
#define deep first

cll mxn = 52;
ll n, k, m, found[mxn], dp_m[mxn][mxn][mxn]/*dp[col][deep][num], col la thu tu trong ds chon dc num so*/, c[mxn][mxn] = {{0}}, dp[mxn][mxn] = {{0}};
vec(ll) t[mxn];
pp(ll, ll) a[mxn];
bool d[mxn];

void hashdeep(){
    set<ll> s;
    lp(i, 1, n) s.insert(a[i].deep);
    vec(ll) tmp(s.begin(), s.end());
    lp(i, 1, n) a[i].deep = lower_bound(tmp.begin(), tmp.end(), a[i].deep) - tmp.begin() + 1;
}

void sol(){
    memset(dp_m, 0, sizeof dp_m);
    memset(dp, 0, sizeof dp);
    lp(i, 1, 50) t[i].clear(), d[i] = 0;
    cin >> n >> k >> m;
    lp(i, 1, n) cin >> a[i].type;
    lp(i, 1, n) cin >> a[i].deep;
    lp(i, 1, m) cin >> found[i], d[found[i]] = 1;
    sort(found + 1, found + 1 + m);
    sort(a + 1, a + 1 + n);
    hashdeep();
    lp(i, 1, n) t[a[i].type].push_back(a[i].deep);
    lp(i, 0, t[found[1]].size() - 1) lp(num, 1, min(t[found[1]].size() - i, k)) 
        dp_m[1][t[found[1]][i]][num] += c[num - 1][t[found[1]].size() - i - 1];
    lp(i, 2, m){
        ll cnt = 0, tot = t[found[i]].size();
        lp(j, 0, tot - 1){
            ll depth = t[found[i]][j];
            lp(num, i - 1, k){
                lp(dis, 1, 50){
                    ll ndepth = (depth > dis) ? depth : dis;
                    lp(add, 1, tot - j) 
                        if(add + num <= k)
                            dp_m[i][ndepth][add + num] += dp_m[i - 1][dis][num] * c[add - 1][tot - j - 1];
                        // else break;
                }
            }
        }
    }
    lp(i, 1, n){
        if(!d[a[i].type]){
            lp(j, m + 1, k){
                lp(depth, 1, a[i].deep - 1) dp[i][j] += dp_m[m][depth][j - 1];
                lp(i1, 1, i - 1){
                    if(!d[a[i1].type]) dp[i][j] += dp[i1][j - 1];
                }
            }
        }
    }
    ll ans = 0;
    lp(i, 1, n) 
        if(!d[a[i].type]) ans += dp[i][k];
    lp(depth, 1, 50) ans += dp_m[m][depth][k];
    cout << ans << '\n';
}

int main(){
    giuncute();
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    lp(i, 0, 50) c[0][i] = 1;
    lp(i, 1, 50) lp(j, 1, i) c[j][i] = c[j - 1][i - 1] + c[j][i - 1];
    EACHCASE sol();
}