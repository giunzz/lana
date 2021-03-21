#include <bits/stdc++.h>
#define ll long long
#define cll const long long
#define lp(a, b, c) for (ll a  =b; a <= c; a++)
#define lpd(a, b, c) for (ll a  =b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
using namespace std;
#define ff "c"

void File(){
    freopen(ff".inp", "r", stdin);
    freopen(ff".out", "w", stdout);
}

cll maxn = 1e5 + 7;
ll n, f[maxn][3] = {{0}}, a, b, c;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    File();
    cin >> n;
    ll ans = 0;
    lp(i, 1, n){
        cin >> f[i][0] >> f[i][1] >> f[i][2];
        f[i][0] += max(f[i - 1][1], f[i - 1][2]);
        f[i][1] += max(f[i - 1][0], f[i - 1][2]);
        f[i][2] += max(f[i - 1][1], f[i - 1][0]);
    }
    cout << max(f[n][0], max(f[n][1], f[n][2]));
}