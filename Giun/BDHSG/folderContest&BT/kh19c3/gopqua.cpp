#include <iostream>
#include <algorithm>
#include <cmath>
#define ll long long 
#define cll const long long
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define vec(a) vector<a>
#define pp(a, b) pair<a, b>
using namespace std;

void File(const string ff){
    freopen((ff + ".inp").c_str(), "r", stdin);
    freopen((ff + ".out").c_str(), "w", stdout);
}

cll maxm = 2e5 + 7;
ll a[maxm], n, m, cnt[(ll)1e6 + 7] = {0}, res[maxm], S;

struct qr{
    ll l, r, index;
}q[maxm];

bool cpr(const qr &a, const qr &b){
    if (a.l / S != b.l / S) return a.l / S < b.l / S;
    return a.r < b.r;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    File("gopqua");
    cin >> n >> m;
    S = sqrt(n); 
    lp(i, 1, n) cin >> a[i];
    lp(i, 1, m){
        cin >> q[i].l >> q[i].r;
        q[i].index = i;
    }
    sort(q + 1, q + 1 + m, cpr);
    ll ans = 0;
    lp(i, q[1].l, q[1].r) ans += a[i] * (2 * cnt[a[i]]++ + 1);
    res[q[1].index] = ans;
    lp(i, 2, m){
        lp(j, q[i - 1].l, q[i].l - 1) ans -= a[j] * (2 * cnt[a[j]]-- - 1);
        lp(j, q[i].l, q[i - 1].l - 1) ans += a[j] * (2 * cnt[a[j]]++ + 1);
        lp(j, q[i].r + 1, q[i - 1].r) ans -= a[j] * (2 * cnt[a[j]]-- - 1);
        lp(j, q[i - 1].r + 1, q[i].r) ans += a[j] * (2 * cnt[a[j]]++ + 1);
        res[q[i].index] = ans;
    }
    lp(i, 1, m) cout << res[i] << endl;
}