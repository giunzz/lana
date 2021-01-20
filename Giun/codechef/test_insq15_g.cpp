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

ll read(){
    ll tmp;
    cin >> tmp;
    return tmp;
}

void OF(){
    freopen(Fname".inp", "r", stdin);
    freopen(Fname".out", "w", stdout);
}

struct quang{
    ll a, b, c, d;
};

ll g[100][100] = {{0}}, f[100][100][100][2];
vec(quang) trace;

bool sol(ll a, ll b, ll c, ll op){
    if(b == 0 && c == 0){
        return f[0][b][c][op] = 0;
    }
    if(f[0][b][c][op] != -1) return f[0][b][c][op];
    bool ok = 0;
    lp(i, 1, b){
        if(!sol(0, b - i, c, !op)) ok = 1; 
    }
    lp(i, 1, c){
        if(!sol(0, b + i, c - i, !op)) ok = 1;
    }
    return f[0][b][c][op] = ok;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    OF();
    #endif
    memset(f, -1, sizeof(f));
    ll a = 0, b = 0, c = 10, op = 1;
    cout << sol(a, b, c, op) << '\n';
    // lp(i, 0, 0) lp(j, 0, 6) lp(k, 0, 6) cout << i << ' ' << j << ' ' << k << '\t' << f[i][j][k][0] << ' ' << f[i][j][k][1] << '\n';
}