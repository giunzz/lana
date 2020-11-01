#include <bits/stdc++.h>

using namespace std;

int n, m, k, a[3005], b[3005], c[6005], nm, ppp;
int B[3005], cnt, tg[3005], Cr[3005];

bool cmp()
{
    for (int i = 1; i <= k; ++i)
        if (Cr[i] < c[i]) return true;
        else if (Cr[i] > c[i]) return false;
    return true;
}

void Try(int x)
{
    if (x > nm)
    {
        if (cnt != k)
            return;
        int da = 0, db = 0;
        for (int i = 1; i <= n; ++i)
            if (B[i]) ++da;
        for (int i = n + 1; i <= nm; ++i)
            if (B[i]) ++db;
        db += da;
        int I = 1, J = da + 1, fd = 0;
        while (I <= da || J <= db)
        {
            if (tg[I] == tg[J])
            {
                if (I <= da){
                    Cr[++fd] = tg[I];
                    ++I;
                }
                else
                {
                    Cr[++fd] = tg[J];
                    ++J;
                }
                continue;
            }
            if (tg[I] < tg[J] && I <= da)
            {
                Cr[++fd] = tg[I];
                ++I;
                continue;
            }
            if (tg[I] > tg[J] && J <= db)
            {
                Cr[++fd] = tg[J];
                ++J;
                continue;
            }
            if (I > da)
            {
                for (int i = J; i <= db; ++i)
                    Cr[++fd] = tg[i];
            }
            else
            {
                for (int i = I; i <= da; ++i)
                Cr[++fd] = tg[i];
            }
            break;
        }
        if (cmp())
        {
            for (int i = 1; i <= k; ++i)
                c[i] = Cr[i];
            if (c[1] == 1 && c[5] == 2 && c[6] == 1 && c[9] == 0)
                cout << ppp << '\n';
        }
        return;
    }
    B[x] = 0;
    Try(x + 1);
    ++cnt;
    B[x] = 1;
    if (cnt <= k)
    {
        tg[cnt] = a[x];
        Try(x + 1);
    }
    --cnt;
}

int main()
{
    if (fopen ("SEQUENCE.inp", "r"))
    {
        freopen ("SEQUENCE.inp", "r", stdin);
        freopen ("SEQUENCE.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(); cout.tie();
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= m; ++i)
        cin >> b[i];
    nm = n + m;
        for (int i = 1; i <= k; ++i)
            c[i] = 10000;
        for (int i = n + 1; i <= nm; ++i)
            a[i] = b[i - n];
        Try(1);
        for (int i = 1; i <= k; ++i)
            cout << c[i] << " ";

}
