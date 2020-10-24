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
    freopen(Fname ".inp", "r", stdin);
    freopen(Fname ".out", "w", stdout);
}

cll maxn = 507, maxnd = maxn * maxn;
ll n, m, t, a[maxn][maxn], num[maxn][maxn];
vec(pp(ll, ll)) g[maxnd];

void init(){
    ll tmp = 0;
    lp(i, 1, n){
        lp(j, 1, m) num[i][j] = ++tmp;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    OF();
    cin >> n >> m >> t;
    init();
    lp(i, 1, n){
        lp(j, 1, m) cin >> a[i][j];
        g[]
    }
}