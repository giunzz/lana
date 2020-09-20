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
    freopen((ff + ".ans").c_str(), "w", stdout);
}

cll maxn = 1e5 + 7;
ll n, q, a[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    File("building");
    cin >> n;
    lp(i, 1, n) cin >> a[i];
    cin >> q;
    lp(i, 1, q){
        ll tt, b, c;
        cin >> tt >>b >>c;
        if(tt == 1){
            a[b] = c;
        }
        else{
            ll ans = 0;
            lp(i, b + 1, c) ans += abs(a[i] - a[i - 1]);
            cout << ans << endl;
        }
    }
}