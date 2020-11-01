#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef pair < int, int > pii;

int n, b[25];
long long k, M, a[3];
vector < int > res;
map < pair < int, pii >, long long > f;

void Try(int x)
{
    if (x > n)
    {
        long long tmp = 0;
        for (int i = 1; i <= n; ++i)
            tmp = (tmp * (long long)10 + a[b[i]]) % a[2];
        if (tmp != k) return;
        for (int i = 1; i <= n; ++i)
            cout << a[b[i]];
        exit(0);
    }
    b[x] = 0;
    Try(x + 1);
    b[x] = 1;
    Try(x + 1);
}

int F(int I, int id, long long mod)
{
    if (I > n)
        if (mod == k)
        {
            res.push_back(id);
            return 2;
        }
        else return 1;
    int FF = f[mp(I, mp(id, mod))];
    if (FF)
        if (FF == 2)
        {
            res.push_back(id);
            return 2;
        }
        else
            return 1;
    if (F(I + 1, 0, (mod * (long long)10 + (long long)a[0]) % M) == 2)
    {
        res.push_back(id);
        return 2;
    }
    else
        if (F(I + 1, 1, (mod * (long long)10 + (long long)a[1]) % M) == 2)
        {
            res.push_back(id);
            return 2;
        }
    f[mp(I, mp(id, mod))] = 1;
    return 1;
}

int main()
{
    if (fopen ("MODULO.inp", "r"))
    {
        freopen ("MODULO.inp", "r", stdin);
        freopen ("MODULO.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(); cout.tie();
    cin >> a[0] >> a[1] >> n >> k;
    if (n <= 20)
    {
        a[2] = (1 << n);
        Try(1);
        cout << -1;
        return 0;
    }
    M = (1 << n);
    F(1, 0, 0);
    if (res.size() <= 1)
        cout << -1;
    else
        for (int i = res.size() - 2; i >= 0; --i)
            cout << a[res[i]];
}
