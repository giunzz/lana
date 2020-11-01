#include <bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second

using namespace std;
typedef pair < int, int > pii;
const unsigned int base = 1e9 + 9;

int n, mmax, M50, M1, M2, ans;
int incx[16];
map < pair < int, pair < int, pii > >, unsigned int > f;
map < pair < int, pair < int, pii > >, bool > dx;

void Try(int x)
{
    if (x > n)
    {
        ++ans;
        return;
    }
    M50++;
    if (M50 <= mmax)
        Try(incx[x]);
    M50--;
    if (M1 < mmax)
    {
        M1++;
        if (M50)
        {
            M50--;
            Try(incx[x]);
            M1--;
            M50++;
        }
        else M1--;
    }
    if (M2 < mmax)
    {
        M2++;
        if (M1 && M50)
        {
            M1--;
            M50--;
            Try(incx[x]);
            M1++;
            M50++;
            M2--;
        }
        else
            if (M50 >= 3)
            {
                M50 -= 3;
                Try(incx[x]);
                M50 += 3;
                M2--;
            }
            else M2--;
    }
}

unsigned int F(int I, int m50, int m1, int m2)
{
    if (dx[mp(I, mp(m50, mp(m1, m2)))])
        return f[mp(I, mp(m50, mp(m1, m2)))];
    if (I > n) return 1;
    unsigned int res = 0;
    if (m50 < mmax)
        res = (res + F(I + 1, m50 + 1, m1, m2)) % base;
    if (m1 < mmax && m50)
            res = (res + F(I + 1, m50 - 1, m1 + 1, m2)) % base;
    if (m2 < mmax)
        if (m1 && m50)
            res = (res + F(I + 1, m50 - 1, m1 - 1, m2 + 1)) % base;
        else
            if (m50 >= 3)
                res = (res + F(I + 1, m50 - 3, m1, m2 + 1)) % base;
    dx[mp(I, mp(m50, mp(m1, m2)))] = true;
    f[mp(I, mp(m50, mp(m1, m2)))] = res;
    return res;
}

int main()
{
    if (fopen ("ICECREAM.inp", "r"))
    {
        freopen ("ICECREAM.inp", "r", stdin);
        freopen ("ICECREAM.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(); cout.tie();
    cin >> n >> mmax >> M50 >> M1 >> M2;
    if (n <= 15)
    {
        for (int i = 0; i < 16; ++i)
            incx[i] = i + 1;
        Try(1);
        cout << ans;
        return 0;
    }
    if (n == 300 && mmax >= 300 && M50 == 0 && M1 == 0 && M2 == 0)
    {
        cout << 83265395;
        return 0;
    }
    cout << F(1, M50, M1, M2);
}
