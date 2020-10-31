using namespace std;
#include <bits/stdc++.h>

typedef long long ll;
typedef pair<ll, int> cp;

#define forinc(i, a, b) for (int i = a; i <= b; i++)
#define fordec(i, a, b) for (int i = a; i >= b; i--)
#define fi first
#define se second
#define mp make_pair
#define LanHT "modulo"

const int maxn = 1e6 + 1e5, base = 1e9 + 7;
ll n, a, b, k, x1, x2, ok = -1, sl = 0;

cp luu[maxn];

int check(ll tg){
    int d = 1, c = sl;
    while (d <= c){
        int giua = (d + c)/ 2;
        if (luu[giua].fi >= tg) c = giua - 1; else d = giua + 1;
    }
    if (luu[d].fi == tg) return luu[d].se;
    return -1;
}

void Input(){
    cin >> a >> b >> n >> k;
}

void Solve(){
    ll sbc = 1;
    forinc(i, 1, n) sbc *= 2;
    int m = n/2;
    ll x = 1;
    forinc(i, 1, n - m) x *= 10;
    x = x % sbc;
    forinc(i, 0, (1 << m) - 1){
        ll so = 0;
        ///0 - b, 1 - a;
        forinc(j, 0, m - 1) if ((i >> j) & 1) so = (so * 10 + a) % sbc; else so = (so * 10 + b) % sbc;
        luu[++sl] = mp((so * x) % sbc, i);
    }
    m = n - m;
    sort(luu + 1, luu + sl + 1);
    forinc(i, 0, (1 << m) - 1){
        ll so = 0;
        forinc(j, 0, m - 1) if ((i >> j) & 1) so = (so * 10 + a) % sbc; else so = (so * 10 + b) % sbc;
        if (so <= k) ok = check((k - so) % sbc);
        if (ok != -1) {x1 = ok; x2 = i; break;}
        ok = check((sbc + k - so) % sbc);
        if (ok != -1) {x1 = ok; x2 = i; break;}
    }
    if (ok != -1){
    forinc(i, 1, n / 2) if ((x1 >> (i - 1)) & 1) cout << a; else cout << b;
    forinc(i, 0, m - 1) if ((x2 >> i) & 1) cout << a; else cout << b;
    } else cout << -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    freopen(LanHT".inp", "r", stdin);
    freopen(LanHT".out", "w", stdout);
    Input();
    if (n <= 40) Solve(); else cout << -1;
}
