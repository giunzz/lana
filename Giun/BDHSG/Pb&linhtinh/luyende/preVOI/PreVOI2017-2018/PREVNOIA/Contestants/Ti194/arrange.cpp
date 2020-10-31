#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 7;

int a[maxn], n, b[maxn], t = 0;

long long tong, demmin, demmax, amin, amax, kq = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("arrange.inp", "r", stdin);
    freopen("arrange.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        tong += a[i];
    }
    demmax = tong % n;
    demmin = n - demmax;
    amin = tong / n;
    amax = tong / n + 1;
    for(int i = 1; i <= n; i++)
    {
        if(a[i] == amax)
        {
            if(demmax > 0)
            {
                demmax--;
                continue;
            }
        }
        if(a[i] == amin)
        {
            if(demmin > 0)
            {
                demmin--;
                continue;
            }
        }
        b[++t] = a[i];
    }
    sort(b + 1, b + t + 1);
    for(int i = 1; i <= t; i++)
    {
        if(demmin > 0)
        {
            kq += abs(b[i] - amin);
            demmin--;
        }
        else
        {
            kq += abs(b[i] - amax);
        }
    }
    cout << kq / 2;
}
