// MR.J
#include<bits/stdc++.h>
#define maxn 2005
#define maxC 1000000000
#define MOD 1000000007
#define mp make_pair
#define PB push_back
#define F first
#define S second
#define pii pair<int, int>
#define ll long long
#define rep(i, a, b) for(int i=(a) ; i<=(b) ; ++i)
#define repd(i, a, b) for(int i=(a) ; i>=(b) ; --i)
#define Task "teaworld"
using namespace std;
struct ball {
    int x, y, z, r;
} b[maxn];

struct tea {
    int x, y, z, e;
} a[20];
int m, n, k, x, y, z, luu[maxn], dem, val0, s[maxn], top, ans;

void setup() {
    cin >> m >> n >> k;
    rep(i, 1, m) {
        cin >> b[i].x >> b[i].y >> b[i].z >> b[i].r;
        if(b[i].z == 0) ++val0;
    }
    rep(i, 1, n) {
        cin >> a[i].x >> a[i].y >> a[i].z >> a[i].e;
        if(a[i].z == 0) ++val0;
    }
    cin >> x >> y >> z;
    if(z == 0) ++val0;
}

double dis(pii x, pii y) {
    return 1.0*sqrt(1.0*(x.F - y.F)*(x.F - y.F) + 1.0*(x.S - y.S)*(x.S - y.S));
}

bool ok(int id) {
    double kc = dis(mp(b[id].x, b[id].y), mp(x, y));
    return (kc > 1.0*b[id].r);
}

int getbit(int x, int i) {
    return (x >> i) & 1;
}

bool canBuy(int store, int ball) {
    int A = y - a[store].y;
    int B = -(x - a[store].x);
    int C = a[store].y*(x - a[store].x) - a[store].x*(y - a[store].y);
    double dLine = abs(1.0*A*b[ball].x + 1.0*B*b[ball].y + 1.0*C)/(1.0*sqrt(1.0*A*A + 1.0*B*B));
    return (dLine > b[ball].r);
}

void handling(int state) {
    top = 0;
    rep(i, 1, dem) {
        if(!getbit(state, i-1)) s[++top] = luu[i];
    }
    int sum = 0;
    rep(i, 1, n) {
        bool can = 1;
        rep(j, 1, top) {
            if(!canBuy(i, s[j])) {can = 0; break;}
        }
        if(can) sum += a[i].e;
    }
    ans = max(ans, sum);
}

void check() {
    rep(i, 1, m) {
        if(ok(i)) luu[++dem] = i;
        else --k;
    }
    int state = (1 << dem) - 1;
    rep(i, 0, state) {
        if(__builtin_popcount(i) != k) continue;
        handling(i);
    }
}

void calc0() {
    check();
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    setup();
    if(val0 == m + n + 1) calc0();
    return 0;
}
