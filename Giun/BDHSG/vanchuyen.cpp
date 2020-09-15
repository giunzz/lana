#include <bits/stdc++.h>
#define ll long long
#define cll const long long
#define lp(a, b, c) for (ll a  =b; a <= c; a++)
#define lpd(a, b, c) for (ll a  =b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
using namespace std;

void File(const string ff){
    freopen((ff + ".inp").c_str(), "r", stdin);
    freopen((ff + ".out").c_str(), "w", stdout);
}

cll maxn = 3e5 + 7;
ll n, k, xe[maxn];
pp(ll, ll) h[maxn];

#define kl second
#define gt first

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    File("f");
    cin >> n >> k;
    lp(i, 1, n) cin >> h[i].kl >> h[i].vt;
    lp(i, 1, k) cin >> xe[i];
    sort(xe + 1, xe + 1 + k);
    sort(h + 1, h + 1 + n);
    lpd(i, n, 1){

    }
}
