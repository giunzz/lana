#include <bits/stdc++.h>
#define ll long long
#define cll const ll
#define lp(a, b, c) for(ll a = b; a <= c; ++a)
#define lpd(a, b, c) for(ll a = b; a >= c; --a)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
#define Fname "f"
using namespace std;

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

cll maxn = 1e5 + 7;
ll n, f[maxn][4][4][4];
vec(ll) q;

ll cal(ll a, ll b, ll c){
    ll res = 0;
    lp(i, 1, 3) if(a == i || b == i || c == i) ++res;
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    string s;
    cin >> n >> s;
    q.push_back(0);
    for(char c : s){
        if(c == 'M') q.push_back(1);
        else if(c == 'F') q.push_back(2);
        else q.push_back(3);
    }
    memset(f, -1, sizeof f);
    f[1][0][0][0] = 1;
    lp(i, 1, n - 1){
        lp(a, 0, 3) lp(b, 0, 3) lp(c, 0, 3){
            if(f[i][a][b][c] == -1) continue;
            ll tmp = f[i][a][b][c];
            f[i + 1][q[i]][b][c] = max(f[i + 1][q[i]][b][c], tmp + cal(q[i], q[i + 1], a));
            f[i + 1][b][q[i]][a] = max(f[i + 1][b][q[i]][a], tmp + cal(q[i + 1], b, c));
        }
    }
    ll ans = 0;
    lp(i, 1, n) lp(a, 0, 3) lp(b, 0, 3) lp(c, 0, 3) ans = max(ans, f[i][a][b][c]);
    cout << ans;
}