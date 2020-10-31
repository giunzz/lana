#include <bits/stdc++.h>

using namespace std;

int a, b, n, n2;
long long k, lim, cur, res[41];
map<long long, int> m;

void dq1(int in, int mask, long long d)
{
    if (in == n2)
    {
        m[d] = mask;
        return;
    }
    dq1(in + 1, mask, d);
    dq1(in + 1, mask | (1 << in), (d + res[in] * b) & lim);
}

bool ok;

void dq2(int in, int mask, long long d)
{
    if (in == n)
    {
        if (m.find((lim + 1 - d) & lim) != m.end())
        {
            ok = true;
            for (int i = n - n2 - 1; i >= 0; --i)
                if (mask & (1 << i)) cout << a + b;
                else cout << a;
            mask = m.find((lim + 1 - d) & lim)->second;
            for (int i = n2 - 1; i >= 0; --i)
                if (mask & (1 << i)) cout << a + b;
                else cout << a;
        }
        return;
    }
    dq2(in + 1, mask, d);
    if (ok) return;
    dq2(in + 1, mask | (1 << (in - n2)), (d + res[in] * b) & lim);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("MODULO.inp", "r", stdin);
    freopen("MODULO.out", "w", stdout);
    cin >> a >> b >> n >> k;
    if (n > 40) return 0;
    n2 = n >> 1;
    lim = (1LL << n) - 1;
    if (a > b) swap(a, b);
    b -= a;
    for (int i=0, j=1; i<n; ++i)
    {
        cur = (cur * 10 + a) & lim;
        res[i] = j;
        j = (j * 10) & lim;
    }
    cur = (cur - k + lim + 1) & lim;
    dq1(0, 0, 0);
    dq2(n2, 0, cur);
    return 0;
}
