#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, long long> II;
const int maxn = 1e6;
int m, a, b,E[maxn], P[maxn], nP,  kn, kA, kB;
II p[maxn], c[maxn], pA[maxn], pB[maxn];
int read_int()
{
    int kq = 0, sign = 1;
    char c = getchar();
    while (c <'0' || c > '9')
    {
        if (c == '-')
            sign = -1;
        c = getchar();
    }
    while (c >= '0' && c <='9')
        kq = kq*10+c-'0', c = getchar();
    return kq*sign;
}

long long eratos(long long m)
{
    for (long long i = 1; i<=m; ++i)
        E[i] = i;
    for (long long i = 2; i<=m; i++)
    {
        if (E[i] == i)
        {
            P[++nP] = i;
            for (long long j=1; j<=m/i; ++j)
                E[i*j] = nP;
        }

    }
}

void TSNT(long long n)
{
    kn = 0;
    while (n >  maxn)
    {
        long long i = 1;
        while (i<=nP && n%P[i]) i++;
        if (i>nP) p[i+kn] = II(n,1), n = 1;
        else
        {
            p[++kn].first = P[i], p[kn].second = 0;
            while (n%P[i] == 0) ++ p[kn].second, n/=P[i];
        }
    }
    while (n > 1)
    {
        long long a = P[E[n]];
        p[++kn].first = a;
        p[kn].second = 0;
        while (n % a == 0) ++p[kn].second, n/=a;
    }
}

void checkNT(long long A, long long B, bool &ntA, bool &ntB)
{
    for (int i = 1; i<=max(sqrt(A), sqrt(B)); i++)
    {
        if (A%P[i] == 0 && A != P[i])
            ntA = false;
        if (B%P[i] == 0 && B != P[i])
            ntB = false;
    }
}

void write_kq()
{
    long long A = 1, B =1;
    for (int i = 1; i<=kA; i++)
        for (int j = 1; j<=pA[i].second; j++)
            A*=pA[i].first;
    for (int i = 1; i<=kB; i++)
        for (int j = 1; j<=pB[i].second; j++)
            B*=pB[i].first;
    TSNT(A);
    memcpy(pA, p, sizeof(p));
    kA = kn;
    TSNT(B);
    memcpy(pB, p, sizeof(p));
    kB = kn;
    int xA = kA, xB = kB;
    for (int i = 1; i<= kA; i++)
    {
        while (A % pA[i].first == 0 && A - A/pA[i].first > B*pA[i].first - B)
        {
            A /= pA[i].first;
            B *= pA[i].first;
        }
    }
    for (int i = 1; i<= kB; i++)
    {
        while (B % pB[i].first == 0 && B - B/pB[i].first > A*pB[i].first - A)
        {
            B /= pB[i].first;
            A *= pB[i].first;
        }
    }
    cout << A << " " <<B << endl;
}

int main()
{
    eratos(1e6);
    freopen("MINSUM.INP", "r", stdin);
    freopen("MINSUM.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    m = read_int();
    while (m)
    {
        a = read_int();
        b = read_int();
        bool ntA = true, ntB = true;
        //checkNT(a, b, ntA, ntB);
        TSNT(a);
        memcpy(pA, p, sizeof(p));
        kA = kn;
        TSNT(b);
        memcpy(pB, p, sizeof(p));
        kB = kn;
        int xA = kA, xB = kB;
        while (true)
        {
            if (pA[xA].first == pB[xB].first)
            {
                int m = min(pA[xA].second, pB[xB].second);
                pA[xA].second -= m;
                pB[xB].second -= m;
                xA--;
                xB--;

            }
            else if ((pA[xA].first < pB[xB].first || xB == 0) && xA  > 0)
            {
                pA[xA].second = pA[xA].second % 2;
                xA--;
            }
            else if ((pB[xB].first < pA[xA].first || xA == 0) && xB > 0)
            {
                pB[xB].second = pB[xB].second % 2;
                xB--;
            }
            if (xA == 0 && xB ==0)
                break;
        }

        /*for (int i = 1; i<= kA; i++)
            cout << pA[i].first << " " << pA[i].second << endl;
        cout << "-" << endl;
        for (int i = 1; i<= kB; i++)
            cout << pB[i].first << " " << pB[i].second << endl;
        cout << "---" << endl;*/
        write_kq();
        m--;
    }
    return 0;
}
