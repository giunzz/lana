#include <bits/stdc++.h>

using namespace std;

int n, k, L[4005], R[4005], b[25], rs[4005], len, cur[25];
int f[4005][4005];

bool cmp(int dem)
{
    for (int i = 1; i <= dem; ++i)
        if (cur[i] > rs[i]) return true;
        else
            if (cur[i] < rs[i]) return false;
    return false;
}

void Try(int x)
{
    if (x > n)
    {
        int p = 1, dem = 0, po = 0;
        for (int i = 1; i <= n; ++i)
            if (b[i])
        {
            po = L[i];
            break;
        }
        for (int i = 1; i <= n; ++i)
            if (b[i])
            {
                if (abs(L[i] - po) > k)
                    return;
                else po = L[i];
                cur[++dem] = L[i];
                bool ok = false;
                while (p <= n)
                    if (L[i] == R[p])
                    {
                        ++p;
                        ok = true;
                        break;
                    }
                    else
                        ++p;
                if (!ok)
                    return;
            }
        if (dem > len)
        {
            len = dem;
            for (int i = 1; i <= dem; ++i)
                rs[i] = cur[i];
        }
        else
            if (len == dem)
                if (cmp(dem))
                    for (int i = 1; i <= dem; ++i)
                        rs[i] = cur[i];
        return;
    }
    b[x] = 0;
    Try(x + 1);
    b[x] = 1;
    Try(x + 1);
}
int main()
{
    if (fopen ("LIONDANCE.inp", "r"))
    {
        freopen ("LIONDANCE.inp", "r", stdin);
        freopen ("LIONDANCE.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(); cout.tie();
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> L[i];
    for (int j = 1; j <= n; ++j)
        cin >> R[j];
    if (n <= 20)
    {
        Try(1);
        cout << len << '\n';
        for (int i = 1; i <= len; ++i)
            cout << rs[i] << " ";
        return 0;
    }
    for (int i = n; i > 0; --i)
        for (int j = n; j > 0; --j)
            if (L[i] == R[j])
            {
                f[i][j] = f[i + 1][j + 1] + 1;
            }
            else
                f[i][j] = max(f[i + 1][j], f[i][j + 1]);
    len = f[1][1];
    int dd = 0, li = 0, po = -1e9, l = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (L[i] == R[j])
                if (f[i][j] == len)
                    po = max(po, L[i]);
    while (len)
    {
        int tmp = -1e9;
        int lll = l;
        for (int i = li + 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (L[i] == R[j])
                    if (f[i][j] == len)
                        if (L[i] > tmp && abs(L[i] - po) <= k && j > l)
                            tmp = L[i], li = i, lll = j;
        if (tmp != -1e9)
            rs[++dd] = po = tmp, l = lll;
        --len;
    }
    cout << dd << '\n';
    for (int i = 1; i <= dd; ++i)
        cout << rs[i] << " ";
}
