#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair

#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)

#define all(v) v.begin(), v.end()
#define debug(a) cerr << #a << " = " << a

#define task "MODULO"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 65;
const int MASK = (1 << 20) + 5;

int a, b, n;
ll k, md, Exp[N], rem[MASK];
vector<li> hub;

ll mul(ll a, ll x, ll md) {
    //cerr << a << ' ' << x << ' ' << md << '\n';
    if (x == 0) return 0;
    ll res = mul(a, x / 2, md);
    res = (res + res) % md;
    if (x % 2) res = (res + a) % md;
    return res;
}

void init() {
    Exp[0] = 1;
    FOR(i, 1, 63) {
        Exp[i] = mul(Exp[i-1], 10, md);
        //cerr << Exp[i] << '\n';
    }
}

bool getBit(ll x, int i) {
    return (x >> i) & 1;
}

void sub1() {
    REP(mask, (1 << n)) {
        ll num = 0;
        REP(i, n) {
            if (getBit(mask, i)) num = (num + mul(Exp[i], b, md)) % md;
            else num = (num + mul(Exp[i], a, md)) % md;
        }
        if (num != k) continue;
        FORD(i, n-1, 0) {
            if (getBit(mask, i)) cout << b;
            else cout << a;
        }
        exit(0);
    }
    cout << -1;
}

int Find(ll x) {
    int l = 0, r = hub.size() - 1, mid, bs = l;
    while (l <= r) {
        mid = (l + r) / 2;
        if (hub[mid].fi <= x) {
            bs = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    if (hub[bs].fi == x) return hub[bs].se;
    return -1;
}

void sub2() {
    int m = n / 2;
    int p = (n + 1) / 2;
    hub.resize(1 << p);
    REP(mask, (1 << p)) {
        ll num = 0;
        REP(i, p) {
            if (getBit(mask, i)) num = (num + mul(Exp[i], b, md)) % md;
            else num = (num + mul(Exp[i], a, md)) % md;
        }
        rem[mask] = num;
        hub[mask] = mp(num, mask);
    }
    sort(all(hub));
    REP(mask, (1 << m)) {
        ll need = k - mul(rem[mask], Exp[p], md);
        need %= md;
        if (need < 0) need += md;
        int tmp = Find(need);
        if (tmp == -1) continue;
        ll res = (mask << p) | tmp;
        FORD(i, n-1, 0) {
            if (getBit(res, i)) cout << b;
            else cout << a;
        }
        exit(0);
    }
    cout << -1;
}

void sub3() {
    /*ll v = (k - (Exp[n] - 1) / 9 * a) % (b - a);
    v = -v;
    if (v < 0) v += b - a;
    ll md = Exp[n] % (b - a);
    REP(t, b - a) {
        if (t * md % (b - a) == v) {
            cout << t * Exp[n] + k;
            exit(0);
        }
    }*/
    cout << -1;
}

int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    cin >> a >> b >> n >> k;
    md = 1LL << n;
    init();
    if (a > b) swap(a, b);
    if (n <= 20) sub1();
    else if (n <= 40) sub2();
    else sub3();
}
