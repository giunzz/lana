#include <stdio.h>
#include <algorithm>

#define fti(i, x, y) for(int i = (x), _y = (y); i <= _y; ++ i)
#define ftd(i, x, y) for(int i = (x), _y = (y); i >= _y; -- i)
#define ll long long

using namespace std;

const int N = 1e6 + 2;
int n, k;
ll Maxx[N], Maxn[N], a[N], S[N], res = 1e18;

void fr()
{
    freopen("GIFTS.inp", "r", stdin);
    freopen("GIFTS.out", "w", stdout);
}

void inp()
{
    scanf("%d %d", &n, &k);
    fti(i, 1, n) scanf("%lld", &a[i]);
}

void proc()
{
    fti(i, 1, k - 1) S[i] = S[i - 1] + a[i];
    fti(i, k, n) S[i] = S[i - 1] + a[i] - a[i - k];
    ftd(i, n, 1) Maxn[i] = max(Maxn[i + 1], S[i]);
    fti(i, 1, n) Maxx[i] = max(Maxx[i - 1], S[i]);
    fti(i, k, n) {
        res = min(res, max(Maxx[i - k], Maxn[i + 1]));
    }
    printf("%lld\n", res);
}

int main()
{
    fr();
    inp();
    proc();
    return 0;
}
