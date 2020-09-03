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
ll a[maxn], n;

ll getlom(ll u){
    while(u > 1 && a[u] >= a[u - 1]) --u;
    return u;
}

ll getdinh(ll u){
    while(u > 1 && a[u] <= a[u - 1]) --u;
    return u;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    File("duaxe");
    cin >> n;
    lp(i, 1, n) cin >> a[i];
    ll lom, dinh, ans = 0;
    lp(i, 2, n){
        lom = getlom(i);
        dinh = getdinh(lom);
        if((i > lom && a[i] > a[dinh]) || lom == 1) ans += a[i] - a[i - 1];
    }
    cout << ans;
}