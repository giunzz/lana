#include <bits/stdc++.h>
#define bit(x, k) ((x >> k) & 1)
#define maxn 1050000

using namespace std;

int a, b, n, q = 0;
long long k;
pair <long long, int> qu[maxn];
map <long long, pair <int, int> > m;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("MODULO.INP", "r", stdin);
    freopen("MODULO.OUT", "w", stdout);
    cin >> a >> b >> n >> k;
    long long MOD = 1ll << n, lt = min(20, n);
    for (int i = 0; i < (1ll << lt); i++)
    {
        long long cv = 0, P = 1;
        for (int j = 0; j < lt; j++)
        {
            if (bit(i, j)) cv = (cv + P * a) % MOD;
                else cv = (cv + P * b) % MOD;
            P = (P * 10) % MOD;
        }
        qu[++q] = {cv, i};
    }
    if (n <= 20)
    {
        for (int i = 1; i <= q; i++)
            if (qu[i].first == k)
            {
                for (int j = n - 1; j >= 0; j--)
                    if (bit(qu[i].second, j)) cout << a; else cout << b;
                return 0;
            }
        return cout << -1, 0;
    }
    lt = n - 20;
    long long Pi = 1;
    for (int i = 1; i < 21; i++) Pi = (Pi * 10) % MOD;
    for (int i = 0; i < (1ll << lt); i++)
    {
        long long cv = 0, P = 1;
        for (int j = 0; j < lt; j++)
        {
            if (bit(i, j)) cv = (cv + P * a) % MOD;
                else cv = (cv * P * b) % MOD;
            P = (P * 10) % MOD;
        }
        cv = (cv * Pi) % MOD;
        m[cv] = {1, i};
    }
    for (int i = 1; i <= q; i++)
    {
        if (k >= qu[i].first) if (m[k - qu[i].first].first)
        {
            int st = m[k - qu[i].first].second;
            for (int j = lt - 1; j >= 0; j--) if (bit(st, j)) cout << a; else cout << b;
            for (int j = 19; j >= 0; j--) if (bit(qu[i].second, j)) cout << a; else cout << b;
            return 0;
        }
        if (k < qu[i].first) if (m[MOD - qu[i].first + k].first)
        {
            int st = m[k - qu[i].first].second;
            for (int j = lt - 1; j >= 0; j--) if (bit(st, j)) cout << a; else cout << b;
            for (int j = 19; j >= 0; j--) if (bit(qu[i].second, j)) cout << a; else cout << b;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
