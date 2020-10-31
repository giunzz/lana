#include <bits/stdc++.h>
#define maxn 100
#define maxx 2000000

using namespace std;
struct mang
{
    long long tt, du;
};

long long A, B, n, K, x[maxn], KQ[maxn], base2, pow10[maxn];
mang T1[maxx], T2[maxx];


bool sosanh(mang a, mang b)
{
    return a.du < b.du;
}
void check()
{
    long long base10 = 1, s = 0;
    for (int i = 1; i <= n; i++)
        if (x[i] == 0) s = (s*10 + A) % base2;
        else s = (s*10 + B) % base2;
    if (s % base2 == K)
        for (int i = 1; i <= n; i++)
            if (x[i] == 0) KQ[i] = A;
            else KQ[i] = B;
}
void tryMOD(int i)
{
    for (int j = 0; j <= 1; j++)
    {
        x[i] = j;
        if (i == n) check();
        else tryMOD(i + 1);
    }
}
void xuli1()
{
    tryMOD(1);
    for (int i = 1; i <= n; i++)
        cout<<KQ[i];
    cout<<endl;
}
void xuli2()
{
    long long s, dem1 = 0, dem2 = 0;
    int m1 = n / 2;
    int m2 = n - m1;
    long long cmp;
    pow10[0] = 1;
    for (int i = 1; i <= n; i++) pow10[i] = (pow10[i - 1]*10) % base2;
    for (int i = 0; i <= (1<<m1) - 1; i++)
    {
        s = 0;
        for (int j = 1; j <= m1; j++)
        {
            cmp = (i>>(j - 1)) & 1;
            if (cmp == 0) s = (s*10 + A) % base2;
            else s = (s*10 + B) % base2;
        }
        dem1++;
        T1[dem1].tt = i;
        T1[dem1].du = s % base2;
    }
    for (int i = 0; i <= (1<<m2) - 1; i++)
    {
        s = 0;
        for (int j = 1; j <= m2; j++)
        {
            cmp = (i>>(j - 1)) & 1;
            if (cmp == 0) s = (s*10 + A) % base2;
            else s = (s*10 + B) % base2;
        }
        dem2++;
        T2[dem2].tt = i;
        T2[dem2].du = s % base2;
    }

    sort(T2 + 1, T2 + dem2 + 1, sosanh);
    for (int i = 1; i <= dem1; i++)
    {
        int d = 1, c = dem2, g, kq = 0;
        cmp = (K - (T1[i].du*pow10[m2]%base2) + 2*base2) % base2;
        while (d <= c)
        {
            g = (d + c)/2;
            if (T2[g].du == cmp)
            {
                kq = g;
                break;
            }
            else
            if (T2[g].du > cmp) c = g - 1;
            else d = g + 1;
        }
        if (kq != 0)
        {
            for (int j = 1; j <= m1; j++)
            {
                cmp = (T1[i].tt>>(j - 1)) & 1;
                if (cmp == 0) cout<<A;
                else cout<<B;
            }
             for (int j = 1; j <= m2; j++)
            {
                cmp = (T2[kq].tt>>(j - 1)) & 1;
                if (cmp == 0) cout<<A;
                else cout<<B;
            }
            break;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("MODULO.inp","r",stdin);
    freopen("MODULO.out","w",stdout);

    cin >> A >> B >> n >> K;
    base2 = 1;
    for (int i = 1; i <= n; i++) base2 = base2*2;
    if (n <= 20) xuli1();
    else xuli2();
}
