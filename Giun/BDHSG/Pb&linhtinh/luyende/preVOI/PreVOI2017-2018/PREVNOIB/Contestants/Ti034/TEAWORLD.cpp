#include <bits/stdc++.h>

#define fti(i, x, y) for(int i = (x), _y = (y); i <= _y; ++ i)
#define ftd(i, x, y) for(int i = (x), _y = (y); i >= _y; -- i)
#define x first.first
#define y first.second
#define rw second
#define ll long long

using namespace std;

typedef pair <ll, ll> ii;
typedef pair <ii, ll> iii;
const int N = 2002;
int n, m, k, bit[N];
iii a[N], b[N];
ll z, X, Y, Z, res;
bool ok, dd[N];

void fr()
{
    freopen("TEAWORLD.inp", "r", stdin);
    freopen("TEAWORLD.out", "w", stdout);
}

void inp()
{
    scanf("%d %d %d", &m, &n, &k);
    fti(i, 1, m) {
        scanf("%lld %lld %lld %lld", &a[i].x, &a[i].y, &z, &a[i].rw);
        if(a[i].y > 0) ok = true;
    }
    fti(i, 1, n) {
        scanf("%lld %lld %lld %lld", &b[i].x, &b[i].y, &z, &b[i].rw);
        if(b[i].y > 0) ok = true;
    }
    scanf("%lld %lld %lld", &X, &Y, &Z);
    if(Y > 0) ok = true;
}

void proc1()
{
    int S, cnt;
    fti(i, 0, (1 << n) - 1) {
        S = cnt = 0;
        memset(dd, false, sizeof(dd));
        fti(j, 0, n - 1) bit[j + 1] = (i >> j) & 1;
        fti(j, 1, n) {
            if(bit[j]) {
                S += b[j].rw;
                fti(l, 1, m) {
                    if(a[l].x - a[l].rw >= X && a[l].x - a[l].rw <= b[j].x) dd[l] = true;
                    if(a[l].x + a[l].rw <= X && a[l].x + a[l].rw >= b[j].x) dd[l] = true;
                }
            }
        }
        fti(j, 1, m) if(dd[j]) ++ cnt;
        if(cnt <= k) res = max(res, 1LL * S);
    }
    printf("%lld\n", res);
}

void proc2()
{
    int S, cnt;
    ll A, B, C;
    fti(i, 0, (1 << n) - 1) {
        S = cnt = 0;
        memset(dd, false, sizeof(dd));
        fti(j, 0, n - 1) bit[j + 1] = (i >> j) & 1;
        fti(j, 1, n) {
            if(bit[j]) {
                S += b[j].rw;
                B = X - b[j].x;
                A = -(Y - b[j].y);
                C = -(A * b[j].x + B * b[j].y);
                fti(l, 1, m) {
                    if((A * a[l].x + B * a[l].y + C) * (A * a[l].x + B * a[l].y + C) <= a[l].rw * a[l].rw * (A * A + B * B)) dd[l] = true;
                }
            }
        }
        fti(j, 1, m) if(dd[j]) ++ cnt;
        if(cnt <= k) res = max(res, 1LL* S);
    }
    printf("%lld\n", res);
}

int main()
{
    fr();
    inp();
    if(ok) proc2();
    else proc1();
    return 0;
}
