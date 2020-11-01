#include<bits/stdc++.h>

const int mod = 1e9 + 9;

using namespace std;

int n, mmax, m50, m1, m2;

int x[17];

int64_t ds = 0;

void Input()
{
    scanf("%d %d", &n, &mmax);
    scanf("%d %d %d", &m50, &m1, &m2);
}

void xuli()
{
    int dem50 = m50, dem1 = m1, dem2 = m2;

    for(int i = 1; i <= n; i++)
    {
        if(x[i] == 3)
        {
            if(dem50 == mmax) return;
            dem50++;
        }

        if(x[i] == 1)
        {
            if(dem50 == 0 || dem1 == mmax) return;
            dem50--, dem1++;
        }

        if(x[i] == 2)
        {
            if(dem2 == mmax || dem50 == 0) return;
            if(dem50 == 1 || dem50 == 2)
            {
                if(dem1 == 0) return;
                else dem2++, dem1--, dem50--;
            }
            else
            {
                if(dem1 == 0) dem2++, dem50 -= 3;
                else dem2++, dem1--, dem50--;
            }
        }
    }

    ds = (ds + 1) % mod;
}

void thu(int k)
{
    if(k > n)
    {
        xuli();
        return;
    }

    for(int i = 1; i <= 3; i++)
    {
        x[k] = i;
        thu(k + 1);
    }
}

void sub1()
{
    thu(1);

    printf("%I64d", ds);
}

int64_t Calc(int k, int dem50, int dem1, int dem2)
{
    if(k > n) return 1;

    int64_t tmp = 0;

    if(dem50 < mmax) tmp = (tmp + Calc(k + 1, dem50 + 1, dem1, dem2)) % mod;

    if(dem50 >= 1 && dem1 < mmax) tmp = (tmp + Calc(k + 1, dem50 - 1, dem1 + 1, dem2)) % mod;

    if(dem1 >= 1 && dem50 >= 1 && dem2 < mmax) tmp = (tmp + Calc(k + 1, dem50 - 1, dem1 - 1, dem2 + 1)) % mod;

    else if(dem50 >= 3 && dem2 < mmax) tmp = (tmp + Calc(k + 1, dem50 + 3, dem1, dem2 + 1)) % mod;

    return tmp;
}

void sub2()
{
    printf("%I64d", Calc(1, m50, m1, m2));
}

void Solve()
{
    if(n <= 15 && mmax <= 10) sub1();
    else sub2();
}

#define TASK "ICECREAM"
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
