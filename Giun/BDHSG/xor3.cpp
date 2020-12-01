#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "xor3"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll maxdg = 51;
pp(ll, ll) r[3];
ll dp[maxdg + 2][2][2][2][2][2][2], ans = 0;

inline ll cp1(ll q, ll pos){
    return (((q >> pos) & 1LL) ? 1 : 0);
}

inline ll sol(ll pos, bool fl1, bool fl2, bool fl3, bool fl4, bool fl5, bool fl6){
    ll tmp;
    if(pos == -1) return (fl1 == fl2 && fl2 == fl3 && fl3 == fl4 && fl4 == fl5 && fl5 == fl6 && fl1 == 1);
    // cerr << dp[pos][fl1][fl2][fl3][fl4][fl5][fl6] << '\n';
    if(dp[pos][fl1][fl2][fl3][fl4][fl5][fl6] != -1) return dp[pos][fl1][fl2][fl3][fl4][fl5][fl6];
    // cerr << 1;
    ll res = -2;
    lp(x, 0, 1){
        // cerr << 1;
        bool nfl1 = fl1, nfl4 = fl4;
        if(!fl1 && (tmp = cp1(r[0].first, pos)) != x){
            if(x > tmp) nfl1 = 1;
            if(x < tmp) continue;
        }
        // cerr << 1;
        if(!fl4 && (tmp = cp1(r[0].second, pos)) != x){
            if(x < tmp) nfl4 = 1;
            if(x > tmp) continue;
        }
        lp(y, 0, 1){
            bool nfl2 = fl2, nfl5 = fl5;
            if(!fl2 && (tmp = cp1(r[1].first, pos)) != y){
                if(y > tmp) nfl2 = 1;
                if(y < tmp) continue;
            }
            if(!fl5 && (tmp = cp1(r[1].second, pos)) != y){
                if(y < tmp) nfl5 = 1;
                if(y > tmp) continue;
            }
            lp(z, 0, 1){
                bool nfl3 = fl3, nfl6 = fl6;
                if(!fl3 && (tmp = cp1(r[2].first, pos)) != z){
                    if(z > tmp) nfl3 = 1;
                    if(z < tmp) continue;
                }
                if(!fl6 && (tmp = cp1(r[2].second, pos)) != z){
                    if(z < tmp) nfl6 = 1;
                    if(z > tmp) continue;
                }
                // if(pos == 2 && !x && !y && z) cout << tmp << ' ' << z  << ' ' << nfl6 << '\n';
                ll tg = x ^ y ^ z;
                // cerr 
                //     << pos<< "    "
                //     << nfl1 << ' ' 
                //     << nfl2 << ' ' 
                //     << nfl3 << "    " 
                //     << nfl4 << ' ' 
                //     << nfl5 << ' ' 
                //     << nfl6 << "    "
                //     << x << ' ' << y << ' ' << z << " -> " << tg << '\n';
                // cerr << x << ' ' << y << ' ' << z << ' ' << pos << '\n';
                // cerr << tg << ' ' << pos << '\n';
                ll tp1 = sol(pos - 1, nfl1, nfl2, nfl3, nfl4, nfl5, nfl6);
                if(tp1 && !pos) res = max(res, tg);
                else if(tp1 != -2) res = max(res, tp1 | (tg << pos));
            }
        }
    }
    dp[pos][fl1][fl2][fl3][fl4][fl5][fl6] = res;
    return res;
}

inline ll sol1(ll pos, bool fl1, bool fl2, bool fl3, bool fl4, bool fl5, bool fl6){
    ll tmp;
    // if(pos == -1) return (fl1 == fl2 && fl2 == fl3 && fl3 == fl4 && fl4 == fl5 && fl5 == fl6 && fl1 == 1);
    if(pos == -1) return fl1 & fl2 & fl3 & fl4 & fl5 & fl6;
    // cerr << dp[pos][fl1][fl2][fl3][fl4][fl5][fl6] << '\n';
    if(dp[pos][fl1][fl2][fl3][fl4][fl5][fl6] != -1) return dp[pos][fl1][fl2][fl3][fl4][fl5][fl6];
    // cerr << 1;
    ll res = LLONG_MAX;
    lp(x, 0, 1){
        // cerr << 1;
        bool nfl1 = fl1, nfl4 = fl4;
        if(!fl1 && (tmp = cp1(r[0].first, pos)) != x){
            if(x > tmp) nfl1 = 1;
            if(x < tmp) continue;
        }
        // cerr << 1;
        if(!fl4 && (tmp = cp1(r[0].second, pos)) != x){
            if(x < tmp) nfl4 = 1;
            if(x > tmp) continue;
        }
        lp(y, 0, 1){
            bool nfl2 = fl2, nfl5 = fl5;
            if(!fl2 && (tmp = cp1(r[1].first, pos)) != y){
                if(y > tmp) nfl2 = 1;
                if(y < tmp) continue;
            }
            if(!fl5 && (tmp = cp1(r[1].second, pos)) != y){
                if(y < tmp) nfl5 = 1;
                if(y > tmp) continue;
            }
            lp(z, 0, 1){
                bool nfl3 = fl3, nfl6 = fl6;
                if(!fl3 && (tmp = cp1(r[2].first, pos)) != z){
                    if(z > tmp) nfl3 = 1;
                    if(z < tmp) continue;
                }
                if(!fl6 && (tmp = cp1(r[2].second, pos)) != z){
                    if(z < tmp) nfl6 = 1;
                    if(z > tmp) continue;
                }
                // if(pos == 2 && !x && !y && z) cout << tmp << ' ' << z  << ' ' << nfl6 << '\n';
                ll tg = x ^ y ^ z;
                // cerr 
                //     << pos<< "    "
                //     << nfl1 << ' ' 
                //     << nfl2 << ' ' 
                //     << nfl3 << "    " 
                //     << nfl4 << ' ' 
                //     << nfl5 << ' ' 
                //     << nfl6 << "    "
                //     << x << ' ' << y << ' ' << z << " -> " << tg << '\n';
                // cerr << x << ' ' << y << ' ' << z << ' ' << pos << '\n';
                // cerr << tg << ' ' << pos << '\n';
                ll tp1 = sol1(pos - 1, nfl1, nfl2, nfl3, nfl4, nfl5, nfl6);
                if(tp1 && !pos) res = min(res, tg);
                else if(tp1 != -2) res = min(res, tp1 | (tg << pos));
            }
        }
    }
    if(res == LLONG_MAX) res = -2;
    dp[pos][fl1][fl2][fl3][fl4][fl5][fl6] = res;
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    lp(i, 0, 2) cin >> r[i].first >> r[i].second;
    lp(i, 0, 2) r[i].first--, r[i].second++;
    // lp(i, 0, 2) cerr << r[i].first << ' ' << r[i].second << '\n';
    // cerr << cp1(r[2].second, 1) << '\n';
    lp(i, 0, maxdg) lp(a, 0, 1) lp(b, 0, 1) lp(c, 0, 1) lp(d, 0, 1) lp(e, 0, 1) lp(f, 0, 1)
        dp[i][a][b][c][d][e][f] = -1;
    cout << sol1(maxdg, 0, 0, 0, 0, 0, 0) << '\n';
    lp(i, 0, maxdg) lp(a, 0, 1) lp(b, 0, 1) lp(c, 0, 1) lp(d, 0, 1) lp(e, 0, 1) lp(f, 0, 1)
        dp[i][a][b][c][d][e][f] = -1;
    cout << sol(maxdg, 0, 0, 0, 0, 0, 0);
    
}