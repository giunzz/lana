#include<bits/stdc++.h>

const int maxn = 65;

using namespace std;

int A, B, n, k;

int x[maxn], y[maxn];
int sl, p[maxn];

void Input()
{
    scanf("%d %d", &A, &B);
    scanf("%d %d", &n, &k);
}

int luythua(int u, int v)
{
    int mod = (1 << n);

    if(v == 0) return 1;
    if(v == 1) return (u % mod);

    int t = luythua(u, v / 2);

    t = ((t % mod) * (t % mod)) % mod;

    if(t % 2) t = (t * u) % mod;

    return t % mod;
}

void xuli()
{
    int ds = 0;

    int tmp = (1 << n);

    for(int i = 1; i <= n; i++)
    {
        if(x[i] == 0) y[i] = A;
        else y[i] = B;
    }

    reverse(y + 1, y + n + 1);

    for(int i = 1; i <= n; i++) ds = (ds + ((y[i] % tmp) * (luythua(10, i - 1))) % tmp) % tmp;

    if(ds == k)
    {
        sl = 0;
        for(int i = 1; i <= n; i++) p[++sl] = y[i];
    }
}

void thu(int k)
{
    if(k > n)
    {
        xuli();
        return;
    }

    for(int i = 0; i <= 1; i++)
    {
        x[k] = i;
        thu(k + 1);
    }
}

void sub1()
{
    thu(1);

    if(sl == 0) printf("-1");
    else for(int i = n; i >= 1; i--) printf("%d", p[i]);
}

void Solve()
{
    if(n <= 20) sub1();
    else sub1();
}

#define TASK "MODULO"
int main()
{
    #ifdef TASK
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    #else
    freopen("1.inp", "r", stdin);
    #endif // TASK
    Input();
    Solve();
}
