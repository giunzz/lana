#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define pp(a, b) pair<a, b>
#define vec(a) vector<a>
#define vecite(a) vector<a>::iterator
#define fi first
#define se second
#define mp(a, b) map<a, b>
#define setE(a, b) fill_n(a, sizeof(a)/sizeof(a[0]), b)
#define st(a) system((a).c_str());
using namespace std;
cll MOD = 1e9 + 7;
const double esf = 1e-9;
const string tenfile = "digitx";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

ll f[(int)1e6+10];
vec(ll) g[10];

ll gett(ll t){
    while(t > 9){
        ll x = 1;
        while(t) if(t % 10) x *= t % 10, t /= 10;
        t = x;
    }
    return t;
}

void init(){
    ll t, x;
    lp(i, 1, 1e6) {
        t = i;
        while(t > 9){
            x = 1;
            while(t) {if(t % 10) x *= t % 10; t /= 10;}
            t = x;
        }
        // f[i] = t;
        g[t].push_back(i);
    }
}

// void dp(){
//     lp(i, 1, 9) f[i][i] = 1, t[i] = i;
//     lp(i, 1, 1e6){
//         lp(j, 0, 9) f[i][j] += f[i - 1][j];
//         if(i <= 1e5){
//             lp(d, 0, 9){
//                 // if(d){
//                 ll p = gett(i * 10 + d);
//                     // ll p = t[i] * d;
//                     // while(p > 9) 
//                     //     if(p % 10) p = p / 10 * (p % 10);
//                     //     else p /= 10;
//                 ++f[i * 10 + d][p];
//                     // t[i * 10 + d] = p;
//                 // }
//                 // else t[i * 10] = t[i], ++f[i * 10][t[i]];
//             }
//         }
//     }
// }

ii main(){
    opt;
    file;
    ll l, r, q, k;
    init();
    cin >> q;
    while(q--){
        cin >> l >> r >> k;
        ll low = lower_bound(g[k].begin(), g[k].end(), l) - g[k].begin();
        ll high = lower_bound(g[k].begin(), g[k].end(), r) - g[k].begin();
        if(low == g[k].size()) {cout << '0' << endl; continue;}
        while(g[k][high] > r || high == g[k].size()) --high;
        cout << (high - low + 1) << endl;
    }
}
