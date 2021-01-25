#include <bits/stdc++.h>
#define ll long long
#define cll const long long
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define fi first
#define se second
#define Fname "bonggay"
// #define Fname "f"
using namespace std;

void OF(){
    freopen(Fname ".inp", "r", stdin);
    freopen(Fname ".out", "w", stdout);
}

cll maxn = 5e5 + 7;
ll m, n, ans = 0;
pp(ll, ll) a[maxn];

// bool cpr(pp(ll, ll) const &q, pp(ll, ll) const &p){
//     return q.first * q.second > p.first * p.second;
// }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> m >> n;
    // cerr << m << ' ' << n << endl;
    priority_queue<pp(ll, ll)> q;
    lp(i, 1, n){
        // cerr << i << ' ';
        cin >> a[i].fi >> a[i].se;
        q.push({a[i].fi, i});
    }
    // sort(a + 1, a + 1 + n, cpr);
    // lp(i, 1, n){
    //     cerr << a[i].first << ' ' << a[i].second << '\n';
    // }
    // lp(j, 1, m){
    //     lp(i, 1, 6){
    //         while(a[q.top().se].se == 0) q.pop();
    //         if(q.empty()) continue; 
    //         f[i][j] = q.top().se;
    //         cerr << f[i][j] + 1 << ' ';
    //         ans += a[f[i][j]].fi;
    //         --a[f[i][j]].se;
    //         // cerr << f[i][j] << ' ';
    //         q.pop();
    //     }
    //     lp(i, 1, 6){
    //         if(a[f[i][j]].se) q.push({a[f[i][j]].fi, f[i][j]});
    //     }
    //     cerr << '\n';
    //     // cerr << '\n';
    // }
    ll tmp;
    lp(i, 1, 6){
        lp(j, 1, m){
            // while(a[q.top().se].se == 0) q.pop();
            if(q.empty()) continue; 
            tmp = q.top().se;
            // cerr << f[i][j] + 1 << ' ';
            ans += a[tmp].fi;
            --a[tmp].se;
            // cerr << f[i][j] << ' ';
            q.pop();
            if(a[tmp].se) q.push({a[tmp].fi, tmp});
        }
        // lp(i, 1, 6){
        //     if(a[f[i][j]].se) q.push({a[f[i][j]].fi, f[i][j]});
        // }
        // cerr << '\n';
        // cerr << '\n';
    }
    cout << ans;
}