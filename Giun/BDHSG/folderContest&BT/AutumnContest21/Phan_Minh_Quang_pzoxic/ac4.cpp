#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "ac4"

ll read(){
    ll tmp;
    cin >> tmp;
    return tmp;
}
#define EACHCASE lpd(cs, read(), 1)

ll n, g[5][5], row[5][5], col[5][5];

ll calc(ll i, ll j){
    if(~g[i][j]) return g[i][j];
    if(!i || !j || (row[i][j] & col[i][j])) return g[i][j] = 0;
    set<ll> s;
    if(!row[i][j]) s.insert(calc(i - 1, j));
    if(!col[i][j]) s.insert(calc(i, j - 1));
    g[i][j] = 0;
    for(auto &v : s) if(g[i][j] == v) ++g[i][j]; else break;
    return g[i][j];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
    EACHCASE{
        ll ans = 0;
        cin >> n;
        lp(i, 1, n){
            lp(i, 1, 4) lp(j, 1, 4){
                g[i][j] = -1;
                ll tmp;
                cin >> tmp;
                row[i][j] = (tmp + row[i][j - 1]) & 1;
                col[i][j] = (tmp + col[i - 1][j]) & 1;
            }
            ans ^= calc(4, 4);
        }
        if(ans) cout << "Bun\n";
        else cout << "Dau\n";
    }
}